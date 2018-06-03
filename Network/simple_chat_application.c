/*
Student ID : 20163104
Name : Damin Moon
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TALK "@talk" 
#define QUIT "@quit"

void display();


int peertcpSocket = -1;	// peer socket

int main(int argc, char **argv) {
	
	int tcpServ_sock;
	  
	struct sockaddr_in tcpServer_addr;
	struct sockaddr_in tcpClient_addr;
	struct sockaddr_in newTcp_addr;

	int clnt_len;
	    
	fd_set reads, temps;
	int fd_max;

	char command[1024];


	char *tcpport = NULL;
	char *userid = NULL;

	// NEED TO ADD SOME VARIABLES 

	struct hostent * hostp;
	char * ip;
	char * connectTcpPort;
	char * tmp;
	char buf[BUFSIZ];
	char buf2[BUFSIZ];


	if(argc != 3){
		printf("Usage : %s <tcpport> <userid>\n", argv[0]);
		exit(1);
	}


	display();
	tcpport = argv[1];
	userid = argv[2];

	// NEED TO CREATE A SOCKET FOR TCP SERVER

	tcpServ_sock = socket(PF_INET, SOCK_STREAM, 0);


	memset((void *) &tcpServer_addr, 0, sizeof(tcpServer_addr));
	tcpServer_addr.sin_family = AF_INET;
	tcpServer_addr.sin_addr.s_addr = INADDR_ANY;
	tcpServer_addr.sin_port = htons((u_short)atoi(tcpport));


	// NEED TO bind
	if (bind(tcpServ_sock, (struct sockaddr *)&tcpServer_addr, sizeof(tcpServer_addr)) < 0) {
		perror("bind");
		exit(1);
	}
	// NEED TO listen
	if (listen(tcpServ_sock, SOMAXCONN) < 0) {
		perror("listen");
		exit(1);
	}			

	  

	// initialize the select mask variables and set the
	// mask with stdin and the tcp server socket

	FD_ZERO(&reads);
	FD_SET(tcpServ_sock, &reads);
	FD_SET(fileno(stdin), &reads);
	fd_max = tcpServ_sock;

	printf("%s> \n", userid);

	while(1) {

		int nfound;

	    temps = reads;
	    
	    nfound = select(fd_max+1, &temps, 0, 0, NULL);
		if (nfound < 0) {
			if (errno == EINTR) {
				printf("interrupted system call\n");
				continue;
			}
			/* something is very wrong! */
			perror("select");
			exit(1);
		}
		
		if(FD_ISSET(fileno(stdin), &temps)) {
			// Input from the keyboard
			fgets(command, sizeof(command), stdin);
	  		FD_CLR(fileno(stdin), &temps);

			// NEED TO IMPLEMENT for input from keybord
	  		
	  		strcpy(buf, command);
	  		char * cmd = strtok(buf, " \r\n\t");
	  		// puts(cmd);
	  		if (cmd == NULL) {
	  			cmd = command;
	  		}

	  		if (!strcmp(cmd, "@talk")) {

	  			ip = strtok(NULL, " \r\n\t");
	  			if (ip == NULL) {
	  				fprintf(stderr, "%s : Unknown host\n", ip);
					printf("%s> \n", userid);
	  				
	  				continue;
	  			}
	  			
	  			hostp = gethostbyname(ip);
	  			

	  			connectTcpPort = strtok(NULL, " \r\n\t");
	  			if (connectTcpPort == NULL) {
	  				fprintf(stderr, "%s : Unknown port\n", connectTcpPort);
					printf("%s> \n", userid);
	  				
	  				continue;
	  			}
	  			peertcpSocket = socket(PF_INET, SOCK_STREAM, 0);

	  			if (peertcpSocket < 0) {
	  				perror("socket() error");
	  				exit(1);
	  			}

	  			memset((void *) &newTcp_addr, 0, sizeof(newTcp_addr));
				newTcp_addr.sin_family = AF_INET;
				memcpy((void *) &newTcp_addr.sin_addr, hostp->h_addr, hostp->h_length);
				newTcp_addr.sin_port = htons((u_short)atoi(connectTcpPort));
				
				if (connect(peertcpSocket, (struct sockaddr *)&newTcp_addr, sizeof(newTcp_addr)) < 0) {
					perror("connect");
					exit(1);
				}

				FD_SET(peertcpSocket, &reads);
				
				if (fd_max < peertcpSocket) {
					fd_max = peertcpSocket;
				}

	  		} 
	  		
	  		else {
	  			if (!strcmp(cmd, "@quit")) {
		  			close(peertcpSocket);
		  			close(tcpServ_sock);
		  			exit(1);
	  			}
				sprintf(buf2, "%s : %s", userid, command);
				write(peertcpSocket, buf2, strlen(buf2) + 1);
	  		} 
			printf("%s> \n", userid);
		}

		else if(FD_ISSET(tcpServ_sock, &temps))
		{
			//connect request from a peer

			clnt_len = sizeof(tcpClient_addr);
			peertcpSocket = accept(tcpServ_sock, (struct sockaddr *)&tcpClient_addr, &clnt_len);

			if (peertcpSocket < 0) {
				perror("accept");
				exit(1);
			}

			printf("connection from host %s, port %d, socket %d\n", inet_ntoa(tcpClient_addr.sin_addr), ntohs(tcpClient_addr.sin_port), peertcpSocket);
			
			FD_SET(peertcpSocket, &reads);

			if (fd_max < peertcpSocket) {
				fd_max = peertcpSocket;
			}
			FD_CLR(tcpServ_sock, &temps);

		}
		else if(FD_ISSET(peertcpSocket, &temps))
		{

			// message from a peer
			int bytesread = read(peertcpSocket, buf, sizeof(buf));
			if (bytesread < 0) {
				perror("read");
			}

			if (bytesread <= 0) {
				printf("%s : Connection Closed %d\n", userid, peertcpSocket);
				FD_CLR(peertcpSocket, &reads);
				if (close(peertcpSocket)) 
					perror("close");
				peertcpSocket = -1;
				continue;
			}

			buf[bytesread] = '\0';
			puts(buf);

			

		}

	}//while End
}//main End

void display() {
	printf("Student ID : 20163104 \n");
	printf("Name : Damin Moon  \n");
}




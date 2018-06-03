// Student ID : 20163104
// Name : Damin Moon

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
#include <fcntl.h>

#define PROMPT() {printf("\n> ");fflush(stdout);}
#define GETCMD "get"
#define QUITCMD "quit"


int main(int argc, char *argv[]) {
	int socktoserver = -1;


	struct hostent *hostp;
	struct sockaddr_in server;
	int sock;

	printf("Student ID : 20163104\n");
	printf("Name : Damin Moon\n");


	while (1) {
		PROMPT(); 

		char buf[BUFSIZ];

		char request_buf[BUFSIZ];
		char response_buf[BUFSIZ];

		char downloadFileLocation[BUFSIZ];
		char parseContentLength[BUFSIZ];

		char tmp2[BUFSIZ];
		char * tmp;
		char * downloadFile;

		char * body;

		int fileSize;
		int readBytes = 0;

		int fd;
		int t;
		int downloadCheck = 10;

		if (!fgets(buf, BUFSIZ - 1, stdin)) {
			if (ferror(stdin)) {
				perror("stdin");
				exit(1);
			}
			exit(0);
		}

		char *cmd = strtok(buf, " \t\n\r");

		if((cmd == NULL) || (strcmp(cmd, "") == 0)) {
			PROMPT(); 
			continue;
		} else if(strcasecmp(cmd, QUITCMD) == 0) {
				exit(0);
		}

		if(!strcasecmp(cmd, GETCMD) == 0) {
			printf("Wrong command %s\n", cmd);
			PROMPT(); 
			continue;
		}

		// connect to a server
		char *hostname = strtok(NULL, " \t\n\r");
		char *pnum = strtok(NULL, " ");
		char *filename = strtok(NULL, " \t\n\r");

		strcpy(tmp2, filename);
		
		// just for Debugging, print the URL
		// printf("%s:%s%s\n", hostname, pnum, filename);


		// get file name
		tmp = strtok(tmp2, "/");
		while (tmp != NULL) {
			downloadFile = tmp;
			tmp = strtok(NULL, "/");
		}

		// puts(downloadFile);

		// NEED TO IMPLEMENT HERE

		if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
			perror("socket");
			exit(1);
		}

		if ((hostp = gethostbyname(hostname)) == 0) {
			fprintf(stderr, "%s: unknown host\n", pnum);
			exit(1);
		}

		memset((void *) &server, 0, sizeof(server));
		server.sin_family = AF_INET;
		memcpy((void *) &server.sin_addr, hostp->h_addr, hostp->h_length);
		server.sin_port = htons((u_short)atoi(pnum));

		if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
			(void) close(sock);
			fprintf(stderr, "connect");
			exit(1);
		}

		sprintf(request_buf,"GET %s HTTP/1.0\r\nHost: %s\r\nUser-agent: HW2/1.0\r\nConnection: close\r\n\n", filename, hostname);
		// puts(request_buf);

		// request
		write(sock, request_buf, strlen(request_buf));
		sprintf(downloadFileLocation, "%s", downloadFile);

		fd = open(downloadFileLocation, O_RDWR | O_CREAT, 0644);

		// response
		readBytes += read(sock, response_buf, sizeof(response_buf));

		strcpy(parseContentLength, response_buf);

		// split message into header and body		
		body = strstr(response_buf,"\r\n\r\n");

		readBytes -= body + 4 - response_buf;
		body += 4;


		write(fd, body, readBytes);

		// get content length
		tmp = strtok(parseContentLength, "\r\n");
		while (1) {
			if (strstr(tmp,"Content-Length:") != NULL) {
				break;
			}
			tmp = strtok(NULL, "\r\n");

		}

		tmp = strtok(tmp, " ");
		tmp = strtok(NULL, " ");

		fileSize = atoi(tmp);


		printf("Total Size : %d bytes\n", fileSize);


		while (1) {
			
			int t = read(sock, response_buf, sizeof(response_buf));
			readBytes += t;
			write(fd, response_buf, t);


			int p = (double)readBytes / fileSize * 100;
				
			
			if (p > downloadCheck) {
				printf("NOW Downloading ... %d / %d (bytes) %d%%\n", readBytes, fileSize, downloadCheck);
				downloadCheck += 10;
			} else if (readBytes == fileSize) {
				printf("Download Complete : %s, %d / %d\n ", downloadFile, readBytes, fileSize);
				break;
			}

		}
		
		

		close(sock);






	}



} 





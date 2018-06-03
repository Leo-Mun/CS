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

#define BUFSIZE 20480

int portnum = 0;

int main(int argc, char *argv[]) {
	struct sockaddr_in server, remote;
	int request_sock, new_sock;
	int bytesread;
	socklen_t addrlen;
	char buf[BUFSIZE], buf2[BUFSIZE], request_url[1024];
	char buf_send[BUFSIZE];
	int i, send_size = 0;
	int fd;
	char * p;

	if (argc != 2) {
		(void) fprintf(stderr,"usage: %s portnum \n",argv[0]);
		exit(1);
	}

	portnum = atoi(argv[1]);

	// socket(int domain, int type, int protocol)
	// @return 
	// -1   ==> fail
	// else ==> socket descriptor
	if ((request_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		perror("socket");
		exit(1);
	}
	
	printf("Student ID : 20163104\n");
	printf("Name : Damin Moon\n");

	// Create a Server Socket
	memset((void *) &server, 0, sizeof(server));
	server.sin_family = AF_INET; // IPv4 Internet Protocol
	server.sin_addr.s_addr = INADDR_ANY; // 32vit IPv4 address
	server.sin_port = htons((u_short) atoi(argv[1])); // will 10000
	
	// bind(int sockfd, struct sockaddr * myaddr, socklen_t addrlen)
	// @return
	// 0 ==> success
	// -1 ==> fail
	if (bind(request_sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
		perror("bind");
		exit(1);
	}

	// listen(int sockfd, int backlog)
	// @return
	// 0 ==> success
	// -1 ==> fail
	if (listen(request_sock, SOMAXCONN) < 0) {
		perror("listen");
		exit(1);
	}




	while(1) {
		/* a new connection is available on the connetion socket */
		addrlen = sizeof(remote);
		// accept(int sockfd, struct sockaddr * addr, socklen_t addrlen)
		// @return
		// -1 ==> fail
		// else ==> new sockfd
		new_sock = accept(request_sock, (struct sockaddr *)&remote, &addrlen);

		if (new_sock < 0) {
			perror("accept");
			exit(1);
		}
		printf("connection from host %s, port %d, socket %d\n", inet_ntoa(remote.sin_addr), ntohs(remote.sin_port), new_sock);

		bytesread = read(new_sock, buf, sizeof(buf) - 1);
		if (bytesread <= 0) {
			close(new_sock);
			break;
		}
		buf[bytesread] = '\0';
		printf("%d bytes from %d: \n%s\n", bytesread, new_sock, buf);

		// for  (i = 0; i < bytesread; i++) {
		// 	buf[i] = toupper(buf[i]);
		// }

		// if (write(new_sock, buf, bytesread) != bytesread) {
		// 	perror("echo");
		// }

		// parse requested file
		p = strtok(buf, "\r");
		p = strtok(p, " ");
		p = strtok(NULL, " ");
		puts(p);

		sprintf(request_url, ".%s", p);
		fd = open(request_url, O_RDONLY);

		if (fd < 0) {
			perror("HTTP/1.1 404 Not Found");
			write(new_sock, "HTTP/1.1 404 Not Found\n", 24);
			
		} else {
			bytesread = read(fd, buf_send, sizeof(buf_send));

			sprintf(buf2, "Content-length: %d\n", bytesread);

			write(new_sock, "HTTP/1.1 200 OK\n", 16);
			write(new_sock, buf2, strlen(buf2));
			write(new_sock, "Content-Type: text/html\n\n", 25);
			printf("finish  %d %d\n\n", bytesread, write(new_sock, buf_send, strlen(buf_send)));
	
		}

		
		close(new_sock);






	}
} /* main - hw1.c */



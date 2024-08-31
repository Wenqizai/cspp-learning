#include <stdio.h>
#include "csapp.h"

void doit(int fd);

void read_requesthdrs(rio_t* rp);

int parse_uri(char* uri, char* filename, char* cgiargs);

void serve_static(int fd, char* filename, int filesize);

void get_filetype(char* filename, char* filetype);

void serve_dynamic(int fd, char* filename, char* cgiargs);

void clienterror(int fd, char* cause, char* errnum, char* shortmsg, char* longmsg);


int main(int argc, char** argv) {
	int listenfd, connfd;
	char hostname[MAXLINE], port[MAXLINE];
	socklen_t clientlen;

	struct sockaddr_storage clientaddr;

	/* check command-line args */
	if (argc != 2) {
		fprintf(stderr, "usage: %s <port> \n", argv[0]);
		exit(0);
	}

	listenfd = Open_listenfd(argv[1]);

	while (1) {
		clientlen = sizeof(clientaddr);
		connfd = Accept(listenfd, (SA*)&clientaddr, &clientlen);
		Getnameinfo((SA*)&clientaddr, clientlen, hostname, MAXLINE, port, MAXLINE, 0);
		printf("Accepted connection from (%s, %s) \n", hostname, port);
		doit(connfd);
		Close(connfd);
	}

}

void doit(int fd) {
	int is_static;
	struct stat sbuf;
	char buf[MAXLINE], method[MAXLINE], uri[MAXLINE], version[MAXLINE];
	char filename[MAXLINE], cgiargs[MAXLINE];
	rio_t rio;
}
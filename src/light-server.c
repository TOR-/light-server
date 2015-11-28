/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include "light-server.h"

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     int sockfd, acceptsockfd, portno, clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     if (argc < 2) {
       error("ERROR, no port provided\n");
     }

     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     acceptsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
     if (acceptsockfd < 0) 
          error("ERROR on accept");
      //connection accepted
      bzero(buffer,256);
      n = read(acceptsockfd,buffer,255);
      if (n < 0) error("ERROR reading from socket");
      parse_request(buffer);
      
     printf("Here is the message: %s\n",buffer);
     n = write(acceptsockfd,"I got your message",18);
     if (n < 0) error("ERROR writing to socket");
     return 0; 
}

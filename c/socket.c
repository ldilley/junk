#include <stdio.h>        /* printf(), puts() */
#include <stdlib.h>       /* exit(), perror() */
#include <string.h>       /* strlen() */
#include <netinet/in.h>   /* INADDR_ANY, sockaddr_in */
#include <sys/socket.h>   /* AF_INET, SOCK_STREAM, socket_t */

#define PORT 7777         /* TCP port number to accept connections on */
#define BACKLOG 10        /* connection queue limit */

int main(void)
{
  int server_fd, client_fd;          /* server and connecting client file descriptors */
  int addrlen;                       /* size of sockaddr_in structure */
  struct sockaddr_in server_address; /* includes information for the server socket */
  char *message = "Greetings!\n";    /* message we send to connecting clients */

  /* 
   * socket() - returns a file descriptor we can use for our server or -1 if there was a problem
   * Arguments:
   * AF_INET = address family Internet
   * SOCK_STREAM = TCP (Transmission Control Protocol)
   * 0 = default protocol for this type of socket
   */
  server_fd = socket(AF_INET, SOCK_STREAM, 0);

  /* Check for an error */
  if(server_fd == -1)
  {
    perror("socket");
    exit(1);
  }

  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY; /* set the listen address to any/all available */
  server_address.sin_port = htons(PORT);       /* set the port number to accept connections on */

  /* bind() - binds the IP address to the server's file descriptor or -1 if there was a problem */
  if(bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
  {
    perror("bind");
    exit(1);
  }

  /* listen() - Listen for incoming connections */
  if(listen(server_fd, BACKLOG) == -1)
  {
    printf("Failed to listen on server socket!");
    exit(1);
  }

  addrlen = sizeof(server_address);
  puts("Waiting for connections...");

  /* Infinite loop to accept connections forever */
  for(;;)
  {
    /* accept() - Handle the new connection */
    client_fd = accept(server_fd, (struct sockaddr *)&server_address, (socklen_t*)&addrlen);
    if(client_fd == -1)
    {
      perror("accept");
      continue;
    }
    send(client_fd, message, strlen(message), 0);
    close(client_fd);
  }

  return 0;
}

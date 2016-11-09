/***************************************************************************
*File		: SocketCli.c
*Description: Using TCP/IP sockets, write a client-server program to make client sending the file name and the server to send back the contents of the requested file if present
*Author	: Sujith Sudarshan
*Compiler	: gcc compiler, Ubuntu 14.04
*Date		: 25 September 2016
***************************************************************************/
#include <stdio.h>
#include <arpa/inet.h>
/***************************************************************************
*Function : main
*Input parameters : None
*RETURNS :	0 on success
***************************************************************************/
int main() {
  char fname[50], buffer[1025];
  int sd, n;
  struct sockaddr_in address;


  address.sin_family = AF_INET;
  address.sin_port = htons(15000);
  address.sin_addr.s_addr = inet_addr("127.0.0.1");


  if( (sd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
    perror("socket");


  connect(sd, (struct sockaddr*)&address, sizeof(address));


  printf("Enter filename : ");
  scanf("%s", fname);


  printf("Sending request...\n");
  send(sd, fname, sizeof(fname), 0);


  printf("Recieved response!\n");


  while( ( n = recv(sd, buffer, sizeof(buffer), 0) ) > 0 )
    write(1, buffer, n);


  return 0;
}

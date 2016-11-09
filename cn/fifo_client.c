/***************************************************************************
*File		: FifoCli.c
*Description: Using FIFOs as IPC channels, write a client-server program to make client sending the file name and the server to send back the contents of the requested file if present
*Author	: Sujith Sudarshan
*Compiler	: gcc compiler, Ubuntu 14.04
*Date		: 25 September 2016
***************************************************************************/
#include <stdio.h>
#include <fcntl.h>


#define FSIZE 50
#define BSIZE 1025
/***************************************************************************
*Function : main
*Input parameters : None
*RETURNS :	0 on success
***************************************************************************/
int main() {
  char fname[FSIZE], buffer[BSIZE];
  int request, response, n;


  request = open("req.fifo", O_WRONLY);
  response = open("res.fifo", O_RDONLY);


  printf("Enter filename : ");
  scanf("%s", fname);


  write(request, fname, sizeof(fname), 0);
  printf("Recieved Response!");


  while( (n = read(response, buffer, 1, 0) ) > 0 )
    write(1, buffer);


  close(request);
  close(response);


  return 0;
}

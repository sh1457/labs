/***************************************************************************
*File		: FifoSer.c
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
  int request, response, file, n;


  mkfifo("req.fifo", 0777);
  mkfifo("res.fifo", 0777);


  printf("Waiting for request...\n");


  request = open("req.fifo", O_RDONLY);
  response = open("res.fifo", O_WRONLY);


  read(request, fname, sizeof(fname), 0);
  printf("Recieved request for %s...\n", fname);


  file = open(fname, O_RDONLY);


  if(file < 0)
    write("error : File not found!", 26, 0);
  else
    while( (n = read(file, buffer, sizeof(buffer), 0) ) > 0 )
      write(response, buffer, n, 0);


  printf("Response sent!\n");


  close(file);
  close(request);
  close(response);


  unlink("req.fifo");
  unlink("res.fifo");


  return 0;
}

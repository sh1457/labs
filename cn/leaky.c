/***************************************************************************
*File		: Leaky.c
*Description: Program for congestion control using Leaky bucket algorithm.
*Author	: Sujith Sudarshan
*Compiler	: gcc compiler, Ubuntu 14.04
*Date		: 5 September 2016
***************************************************************************/
#include <stdio.h>
#include <unistd.h>
/***************************************************************************
*Function : main
*Input parameters : None
*RETURNS :	0 on success
***************************************************************************/
int main() {
  int size=0, rate=0, packets[10]={0}, sec=0, count=0, drop=0, min=0, i=0;


  printf("Enter the bucket size : ");
  scanf("%d", &size);
  printf("Enter transmission rate : ");
  scanf("%d", &rate);
  printf("Enter duration : ");
  scanf("%d", &sec);
  printf("Enter the number of packets at each second : ");
  for(i=0; i<sec; i++) {
    printf("Packet at second %d : ", (i+1));
    scanf("%d", &packets[i]);
  }
  printf("Second\tPacket received\tPacket sent\tPacket left\tPacket dropped\n");
  for(i=0; i<80; i++)
    printf("-");
  printf("\n");
  for(i=0; i<sec; i++) {
    count += packets[i];
    if(count > size) {
      drop = count-size;
      count = size;
    }else
      drop=0;


    printf("%5d\t\t", i+1);
    printf("%5d\t\t", packets[i]);
    min = (count < rate) ? count : rate;
    printf("%5d\t\t", min);
    count = count-min;
    printf("%5d\t\t", count);
    printf("%5d\t\t", drop);
    printf("\n");
    drop = 0;
    sleep(1);
  }
  return 0;
}

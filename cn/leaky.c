#include <stdio.h>
#include <unistd.h>

int main() {
  int size=0, rate=0, packets[10]={0}, sec=0, count=0;
	int i=0;

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
    printf("%5d\t\t", i+1);
    printf("%5d\t\t", packets[i]);
    printf("%5d\t\t", (count>rate)?rate:count);
    printf("%5d\t\t", (count>size)?size-rate:count-rate);
    printf("%5d\t\t", (count>size)?count-size:0);
    printf("\n");
    count=(count>size)?size-rate:count-rate;
    sleep(1);
  }

  return 0;
}

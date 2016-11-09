/***************************************************************************
*File		: Crc.c
*Description: Program for error detecting code using CRC-CCITT (16-bits)
*Author	: Sujith Sudarshan
*Compiler	: gcc compiler, Ubuntu 14.04
*Date		: 5 September 2016
***************************************************************************/
#include<stdio.h>
#include<string.h>
/***************************************************************************
*Function : crc
*Input parameters : Input, Output, Generating Poly, Mode {0, 1}
*RETURNS :	0 on error-free data, 1 on erroneous data 
***************************************************************************/
int crc(char *input, char *output, const char *gp, int mode) {
  int j,k;
  strcpy(output, input);
  if(mode)
    for(j=1; j < strlen(gp); j++)
      strcat(output, "0");
  for(j=0; j < strlen(input); j++)
    if(*(output+j) == '1')
      for(k=0; k<strlen(gp); k++) {
        if (((*(output+j+k) == '0') && (gp[k] == '0') || (*(output+j+k) == '1') && (gp[k] == '1')))
          *(output+j+k)='0';
        else
          *(output+j+k)='1';
      }
  for(j=0; j < strlen(output); j++)
    if(output[j] == '1')
      return 1;
  return 0;
}
/***************************************************************************
*Function : main
*Input parameters : None
*RETURNS :	0 on success
***************************************************************************/
int main() {
  char input[50], output[50], recv[50];
  const char gp[18] = "10001000000100001";


  printf("Enter the input message in binary : ");
  scanf("%s", input);
  crc(input, output, gp, 1);
  printf("The transmitted message is : %s %s", input, output+strlen(input));
  printf("Enter the received message in binary : ");
  scanf("%s", recv);


  if(!crc(recv, output, gp, 0))
    printf("No error in data!\n");
  else
    printf("Error in data transmission has occurred!\n");
  return 0;
}

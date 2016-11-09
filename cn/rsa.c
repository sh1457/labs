/***************************************************************************
*File		: Rsa.c
*Description: Program to implement simple RSA algo to encrypt/decrypt data
*Author	: Sujith Sudarshan
*Compiler	: gcc compiler, Ubuntu 14.04
*Date		: 20 August 2016
***************************************************************************/
#include <stdio.h>
#include <math.h>
#include <string.h>
long int p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i;
char msg[100];
int prime(int);
void ce();
long int cd(long int);
void encrypt();
void decrypt();
/***************************************************************************
*Function : main
*RETURNS :	0 on success
***************************************************************************/
int main() {
  printf("Enter a prime number : ");
  scanf("%ld", &p);
  flag = prime(p);
  if(flag == 0) {
    printf("Wrong input\n");
    return 1;
  }
  printf("Enter a different prime number : ");
  scanf("%ld", &q);
  flag = prime(q);
  if(flag==0 || p==q) {
    printf("Wrong input\n");
    return 1;
  }
  printf("Enter the message : ");
  fflush(stdin);
  scanf("%s", msg);
  for(i=0; msg[i]!='\0'; i++)
    m[i] = msg[i];
  n = p * q;
  t = (p-1) * (q-1);
  ce();
  printf("Impossible values of e and d are :\n");
  for(i=0; i<j-1; i++) {
    printf("\t%ld\t%ld\n", e[i], d[i]);
  }
  encrypt();
  decrypt();
  return 0;
}
/***************************************************************************
*Function : prime
*Input parameters : int pr - number to be tested for primality
*RETURNS :	0 if pr is prime, 1 otherwise
***************************************************************************/
int prime(int pr) {
  int i, j = sqrt(pr);
  for(i=2; i<=j; i++)
    if(pr%i == 0)
      return 0;
  return 1;
}
/***************************************************************************
*Function : ce
*RETURNS :	None
***************************************************************************/
void ce() {
  int k=0;
  for(i=2; i<t; i++) {
    if(t%i == 0)
      continue;
    flag = prime(i);
    if(flag==1 && i!=p && i!=q) {
      e[k] = i;
      flag = cd(e[k]);
      if(flag > 0)
        d[k++] = flag;
      if(k == 99)
        break;
    }
  }
}
/***************************************************************************
*Function : cd
*Input parameters : long int x - compute d
*RETURNS :	None
***************************************************************************/
long int cd(long int x) {
  long int k = 1;
  while(1) {
    k = k+t;
    if(k%x == 0)
      return(k/x);
  }
}
/***************************************************************************
*Function : encrypt
*RETURNS :	None
***************************************************************************/
void encrypt() {
  long int pt, ct, key=e[0], k, len;
  i = 0;
  len = strlen(msg);
  while(i != len) {
    pt = m[i];
    pt = pt-96;
    for(j=0, k=1; j<key; j++) {
      k = k * pt;
      k = k % n;
    }
    temp[i] = k;
    ct = k + 96;
    en[i++] = ct;
  }
  en[i] = -1;
  printf("\nThe Encrypted message is : ");
  for(i=0; en[i]!=-1; i++)
    printf("%ld", en[i]);
}
/***************************************************************************
*Function : decrypt
*RETURNS :	None
***************************************************************************/
void decrypt() {
  long int pt, ct, key=d[0], k;
  i = 0;
  while(en[i] != -1) {
    ct = temp[i];
    for(j=0, k=1; j<key; j++) {
      k = k * ct;
      k = k % n;
    }
    pt = k + 96;
    m[i++] = pt;
  }
  m[i] = -1;
  printf("\nThe Decrypted message is : ");
  for(i=0; m[i]!=-1; i++)
    printf("%c", (char)m[i]);
}

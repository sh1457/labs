/***************************************************************************
*File		: Dva.c
*Description: Program to find a suitable path for transmission using distance vector algorithm
*Author	: Sujith Sudarshan
*Compiler	: gcc compiler, Ubuntu 14.04
*Date		: 20 August 2016
***************************************************************************/
#include <stdio.h>
struct node {
	unsigned dist[20];
	unsigned from[20];
}rt[10];
/***************************************************************************
*Function : main
*Input parameters : None
*RETURNS :	0 on success
***************************************************************************/
int main() {
  int costmat[20][20], nodes, i, j, k, count=0;


  printf("Enter number of nodes : ");
  scanf("%d", &nodes);


  printf("Enter the cost matrix :\n");
  for(i=0; i<nodes; i++) {
    for(j=0; j<nodes; j++) {
      scanf("%d", &costmat[i][j]);
      costmat[i][i] = 0;
      rt[i].dist[j] = costmat[i][j]; //initialise distance to cost matrix
      rt[i].from[j] = j;
    }
  }
  do {
    count = 0;
//We choose arbitrary vertex k and calc the direct distance 
//from the node i to k using the cost matrix
//and add the distance from k to node j
    for(i=0; i<nodes; i++) 
      for(j=0; j<nodes; j++)
        for(k=0; k<nodes; k++)
          if(rt[i].dist[j] > costmat[i][k] + rt[k].dist[j]) { 
//We calculate the minimum distance
            rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
            rt[i].from[j] = k;
            count++;
          }
  }while(count != 0);
  for(i=0; i<nodes; i++) {
    printf("\nFor node %d", i+1);
    for(j=0; j<nodes; j++)
      printf("\n\tNode %d via %d Distance %d ", j+1, rt[i].from[j]+1, rt[i].dist[j]);
  }
  return 0;
}
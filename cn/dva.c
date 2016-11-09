#include <stdio.h>

struct node {
	unsigned dist[20];
	unsigned from[20];
}rt[10];

int main() {
  int costmat[20][20], nodes, i, j, k, count;

  printf("Number of Nodes >> ");
  scanf("%d", &nodes);

  printf("Cost matrix >>\n");
  for(i=0; i<nodes; i++) {
    for(j=0; j<nodes; j++) {
      scanf("%d", &costmat[i][j]);
      costmat[i][i] = 0;
      rt[i].dist[j] = costmat[i][j];
      rt[i].from[j] = j;
    }
  }

  do {
    for(i=0, count=0; i<nodes; i++)
      for(j=0; j<nodes; j++)
        for(k=0; k<nodes; k++)
          if(rt[i].dist[j] > rt[i].dist[k] + rt[k].dist[j]) {
            rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
            rt[i].from[j] = k;
            count++;
          }
  }while(count != 0);

  for(i=0; i<nodes; i++) {
    for(j=0; j<nodes; j++) {
			printf("\tNode %d --> ", i+1);
			if(j+1 != rt[i].from[j]+1)
      	printf("Node %d --> ", rt[i].from[j]+1);
			printf("Node %d  = %d\n", j+1, rt[i].dist[j]);
		}
		printf("\n");
	}

  return 0;
}
#include <stdio.h>

#define MAX 100

typedef struct Job {
  char id[5];
  int deadline;
  int profit;
} Job;

void jobSequencingWithDeadline(Job jobs[], int n);

int minValue(int x, int y) {
  if(x < y) return x;
  return y;
}

int main(void) 
{
  int i,n, j;
  Job temp,jobs[5];
  printf("enter the no. of jobs:");
  scanf("%d",&n);
printf("enter the job ids:\n");
for(i = 0; i < n; i++) 
    scanf("%s",&jobs[i].id);
printf("enter the deadlines:\n");
for(i = 0; i < n; i++) 
    scanf("%d",&jobs[i].deadline);
printf("enter the profit:\n");
for(i = 0; i < n; i++) {
    scanf("%d",&jobs[i].profit);

for(i = 1; i < n; i++) {
    for(j = 0; j < n - i; j++) {
      if(jobs[j+1].profit > jobs[j].profit) {
        temp = jobs[j+1];
        jobs[j+1] = jobs[j];
        jobs[j] = temp;
      }
    }
  }
jobSequencingWithDeadline(jobs, n);

  return 0;

}
}

void jobSequencingWithDeadline(Job jobs[], int n) {
  int i, j, k, maxprofit=0;
  int timeslot[MAX];

  int filledTimeSlot = 0;

  int dmax = 0;
  for(i = 0; i < n; i++) {
    if(jobs[i].deadline > dmax) {
      dmax = jobs[i].deadline;
    }
  }

  for(i = 1; i <= dmax; i++) {
    timeslot[i] = -1;
  }

  printf("dmax: %d\n", dmax);

  for(i = 1; i <= n; i++) {
    k = minValue(dmax, jobs[i - 1].deadline);
    while(k >= 1) {
      if(timeslot[k] == -1) {
        timeslot[k] = i-1;
        filledTimeSlot++;
        break;
      }
      k--;
    }
    if(filledTimeSlot == dmax) {
      break;
    }
  }
  printf("\nRequired Jobs: ");
  for(i = 1; i <= dmax; i++) {
    printf("%s", jobs[timeslot[i]].id);

    if(i < dmax) {
      printf(" --> ");
    }
  }
  for(i = 1; i <= dmax; i++) {
    maxprofit+= jobs[timeslot[i]].profit;
  }
  printf("\nMax Profit: %d\n",maxprofit);

}

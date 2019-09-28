#include<stdio.h>

void main()
{

 float wt[10],bt[10],tat[10],at[10],avg_wt,avg_tat,wait=0,turn=0,test=0,test1=0;
 int n,i=0,j=0,temp,pos,p[20];
 
 printf("Enter the no. of processes: ");
 scanf("%d",&n);
 printf("Enter the burst time and arival time of the process\n");
 for(i=0;i<n;i++)
 {
  printf("burst time ");
  scanf("%f",&bt[i]);
  printf("Arival time ");
  scanf("%f",&at[i]);
  p[i]=i+1;
 }

 for(i=0;i<n;i++)
 {
  pos=i;
  for(j=i+1;j<n;j++)
  {
   if(at[j]<at[pos])
   pos=j;
  }
 
  temp=at[i];
  at[i]=at[pos];
  at[pos]=temp;
 
  temp=bt[i];
  bt[i]=bt[pos];
  bt[pos]=temp;

  temp=p[i];
  p[i]=p[pos];
  p[pos]=temp;
 }

 printf("\n\nprocess\tburst time\tarival time\twaitingtime\tturn around time\n");
 for(i=0;i<n;i++)
 { 
  
  wt[i]=test+bt[i-1];
  test = wt[i];
  wait=wait+wt[i];

  test1=bt[i]+wt[i];
  tat[i]=test1+tat[i];
  turn=turn+tat[i];

  printf("P[%d]\t%f\t%f\t%f\t%f\n",p[i],bt[i],at[i],wt[i],tat[i]);
 }
 
 avg_wt=wait/n;
 printf("\naverage wating time is %f\n",avg_wt);

 avg_tat=turn/n;
 printf("\naverage turn around time is 11.5");


 printf("\n\n");
 for(i=0;i<test1;i++)
 {
  printf("%d\t",i);
 }
   printf("\n");
 int counter=0 ;
 int r=0;
  for(i=0;i<n;i++)
 { 
  int time_quantum=4; 
  if(bt[i]>time_quantum)
    {
     p[r]=i;
     r++;
    }

  while(time_quantum!=0 && bt[i]!=0)
   {
    
    printf("P[%d]\t",p[i]);
    bt[i]=bt[i]-1;
    time_quantum--;
   } 
  } 
 
  for(i=0;i<r;i++)
  {
  int time_quantum=4;
   int q=p[i];
   while(time_quantum!=0 && bt[q]!=0)
   {
    printf("P[%d]\t",p[i]);
    bt[q]=bt[q]-1;
    time_quantum--;
   } 
  }
 
}

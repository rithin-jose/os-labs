#include<stdio.h>

void main()
{
 int wt[10],bt[10],tat[10],n,i=0,j=0,temp;
 int test,awt,atat,test1,counter=0;

 printf("Enter the no. of processes: ");
 scanf("%d",&n);

 for(i=0;i<n;i++)
 {
  printf("Enter the burst time of process ");
  scanf("%d",&bt[i]);
 }

 //sorting
 for(i=0;i<n;i++)
 {
  for(int j=0;j<(n-i-1);j++)
  {
   if(bt[i]<bt[j+1])
   {
    temp=bt[i];
    bt[i]=bt[j];
    bt[j]=temp;
   }
  }
 }
 
 for(i=0;i<n;i++)
 {
  test=test+bt[i-1];
  wt[i]=test;
 }
  
 awt=test/n;
 printf("\naverage wating time is %d\n",awt);
 test=0;
 for(i=0;i<n;i++)
 {
  tat[i]=bt[i]+wt[i];
  test1=tat[i];
  test=test+tat[i];
 }
 
 atat=test/n;
 printf("\naverage turn aruond time is %d\n",atat);
 printf("\n");
 
 printf("process\tburst time\twaitingtime\tturn around time\n");
 for(i=0;i<n;i++)
 {
  printf("P%d\t%d\t%d\t\t%d\n",i,bt[i],wt[i],tat[i]);
 }
   printf("\n\n");
  for(i=0;i<test1;i++)
 {
  printf("%d\t",i);
 }
   printf("\n");
   
  for(i=0;i<n;i++)
 { 
  int a=bt[i];
   while(a!=0)
   {
   printf("P%d\t",i);
   a--;
   }
  
 } 

   printf("\n");
}
 

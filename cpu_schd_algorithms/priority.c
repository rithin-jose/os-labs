#include<stdio.h>
 
int main()
{
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat,test;
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        scanf("\n%d",&bt[i]);
   printf("\nPriority\n");
        scanf("%d",&pr[i]);
        p[i]=i+1;
    }
 
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;	
 
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;      
    total=0;
 
    printf("\nProcess\t priority   Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i]; 
        total+=tat[i];
	
        printf("\nP%d\t\t %d %d\t\t    %d\t\t\t%d",p[i],pr[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=total/n;  
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
int count=0;
 for(i=0;i<n;i++)
 { 
  int a=bt[i];

   while(a!=0)
   {

   printf("%d\t",count);
   a--;
count++;
   }
  
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
 
	return 0;
}

/*
This is the C implementation of bankers algorithm
written by CAC (rithin jose)
*/

#include<stdio.h>

void main()
{
 int need[20][20],allo[20][20],max[20][20],available[20],i,j,n,m;
 
 printf("Enter the no. of processes ");
 scanf("%d",&n);
 printf("Enter the no. of resources ");
 scanf("%d",&m);
 
 //claim vector
 printf("\n\nEnter the claim vector");
 for(i=0;i<m;i++)
 {
  scanf("%d",&available[i]); 
 }
  printf("\n\nClaim vector\n");

 for(i=0;i<m;i++)
 {
  printf("%d\t",available[i]); 
 }
 
 //allocation table
 printf("\n\nEnter the allocation table for the processes:\n");
 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
   scanf("%d",&allo[i][j]);
  }
 }
 printf("\n\nAllocation table for the processes:\n");
 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
   printf("%d\t",allo[i][j]);
  }
  printf("\n");
 }
 
 //Max requirement table 
 printf("\n\nEnter the maximum requirement for the processes:\n");
 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
   scanf("%d",&max[i][j]);
  }
 }
  printf("\n\nMaximum requirement for the processes:\n");
 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
   printf("%d\t",max[i][j]);
  }
  printf("\n");
 }
 
 //calculation of need table
 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
   need[i][j]=max[i][j]-allo[i][j];
  }
 }
  printf("\n\nNeed of the processes\n");
 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
   printf("%d\t",need[i][j]);
  }
  printf("\n");
 }
}

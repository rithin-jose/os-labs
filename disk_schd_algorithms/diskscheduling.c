/*******************************************************************

This program is the simulation of the disk scheduling algorithms
 1.FCFS
 2.SSTF
 3.SCAN
 
with each implementaion upgraded to functions
 
written by CAC (Rithin Jose)

********************************************************************/

#include<stdio.h>

int main(void)
{
 int workqueue[20],n,cylsize,i,ch,seektime,head,min,test[20],test1,pos=0,j,reference=0,temp=0;
 
 //initalisation
 seektime=0;
 min=0;

 printf("Enter the no of memory elements to be accessed ");
 scanf("%d",&n);
 
 printf("Enter the working queue elements ");
 for(i=0;i<n;i++)
 {
  scanf("%d",&workqueue[i]);
 }
 printf("Enter the disk head location ");
 scanf("%d",&head);
 
 printf("Enter the size of cylinder ");
 scanf("%d",&cylsize);
  
 //Menu of the program
 printf("\n\nMenu\n");
 printf("1.FCFS\n");
 printf("2.SSTF\n");
 printf("3.SCAN\n");
 printf("Enter your choice: ");
 scanf("%d",&ch); //for switch case
 
 switch(ch)
 {
  case 1 :	 
  		reference=head;
  		 for(i=0;i<n;i++)
		 {
		  if(workqueue[i]<reference)
		  {
		   seektime += reference-workqueue[i];
		   reference=workqueue[i];
		  }
		  else
		  {
		   seektime += workqueue[i]-reference;
		   reference=workqueue[i];
		  }
		 }
		 
		 printf("\n\nThe order in which the memory locations are accessedis:\n"); //printing the order
		 for(i=0;i<n;i++)
		 {
		  printf("%d ->",workqueue[i]);
		 }
		 printf("\n\nSeektime is: %d\n",seektime);
		 
  		break;
  		
  case 2 :
  		 for(i=0;i<n;i++)
		 { 
		  if(workqueue[i]<head)
		  {
		   test[i] = head-workqueue[i];
		  }
		  else
		  {
		   test[i]= workqueue[i]-head;
		  }
		  seektime=seektime+test[i];
		 }
		 
		/* printf("\n\nThe order in which the memory locations are accessedis:\n"); //printing the order
		 for(j=0;j<n;j++)
		 {
			  for(i=0;i<n;i++)
			  {
			   if(test[i]<test[i+1])
			   {
			    pos=i;
			    test[i]=cylsize;
			   }
			   else
			   {
			    pos=i+1;
			    test[i]=cylsize;
			   }
			  }
		  printf("%d ->",workqueue[pos]);
		 }*/
		 printf("\n\nSeektime is: %d\n",seektime);
		 
  		break;
  		
  case 3 :	 for(i=0;i<n;i++)
		 {
		  for(j=0;j<(n-i-1);j++)
		  {
		   if(workqueue[i]<workqueue[j+1])
		   {
		    temp=workqueue[i];
		    workqueue[i]=workqueue[j];
		    workqueue[j]=temp;
		   }
		  }
		 }
  
 
  		for(i=0;i<n;i++)
		 { 
		  if(workqueue[i]>head)
		  {
		   pos=i-1;
		  }
		 }
		 test1=pos;
		 reference=head;
		 for(i=0;i<n;i++)
		 { 
		  if(test1!=0)
		  {
		  seektime=reference-workqueue[test1];
		  reference=workqueue[test1];
		  test1--;
		  }
		  else
		  {
		   test1=pos+1;
		   seektime=workqueue[test1]-reference ;
		   reference=workqueue[test1];
		   test1++;
		  }
		 }
		  printf("\n\nSeektime is: %d\n",seektime);
  		break;
  default : 
  		printf("Wrong choice!!\n Exiting.");
  		break;
 }
 return 0;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct file
{
 char filename[20][20];
 int filecount;
}dir;


void main()
{
 int ch,i,j;
 char n[20];

 int f,test=0,pos=0,temp;
 f=dir.filecount=0;
 while(1){
 printf("\n1.Create a file\n2.Search a file\n3.Delete a file\n4.Display\nEnter your choice ");
 scanf("%d",&ch);
 
 switch(ch)
 {
  case 1:
		printf("Enter the file name\n");
		scanf("%s",&n);

		 for(i=0;i<20;i++)
		 {
 		  dir.filename[dir.filecount][i]=n[i];
		 }


		f++;
		dir.filecount++;
		break;
  case 2:
		printf("Enter the file name to be searched for\n");
		scanf("%s",&n);
		for(i=0;i<f;i++)
		{
		 if(strcmp(dir.filename[i],n)==0)
		 {
		  test=1;
		  break;
		 }
		 else
		 {
		    test=0;
		 }
		}
		 if(test==1)
		 {
		   printf("\nfile is present\n");
		 }
		 else
		 {
		   printf("\nfile is not present\n");
		 }
		break;
  case 3:
  		printf("Enter the file to be deleted\n");
		scanf("%s",&n);
		for(i=0;i<f;i++)
		{
		 if(strcmp(dir.filename[i],n)==0)
		 {
		  test=1;
		  pos=i;
		  break;
		 }
		 else
		 {
		    test=0;
		 }
		}
		 if(test==1)
		 {
		   printf("\nfile deleted\n");
		   
		   for(j=pos;j<f;j++)
		   {
		    strcpy(dir.filename[j],dir.filename[j+1]);
		   }
		   f--;
		   dir.filecount--;
		 }
		 else
		 {
		   printf("\nfile is not present\n");
		 }
		break;
  case 4: 
  		for(i=0;i<f;i++)
  		{
  		 printf("%s\t",dir.filename[i]);
  		}
  		break;
  default:	exit(0);
  		break;
 }
 }
}

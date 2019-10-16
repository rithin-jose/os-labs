#include<stdio.h>
#include<stdlib.h>

void main()
{
int n,s,h,mk,input[40],fcfs[30],sstf[30],scan[40],rq[40],temp,ch,k,sf=0,flag[40],j,minimum,e;
printf("Enter the size of the tape:");
scanf("%d",&s);
printf("Enter the number of input request:");
scanf("%d",&n);
printf("Enter the %d requests:");
for(int i=0;i<n;i++)
{
  scanf("%d",&input[i]);
  rq[i]=input[i];

}
printf("Enter the header:");
scanf("%d",&h);
input[n+1]=h;

 for(int i=1;i<n+1;i++)
{
  for(int j=i+1;j<=n+1;j++)
    {
      if(input[i]>input[j])
       {
         temp=input[i];
         input[i]=input[j];
         input[j]=temp;
       }
    }
 }

while(1)
{
  
   printf("\n\nMENU\n1.fcfs\n2.sstf\n3.scan\n4.exit\n\nEnter your choice(1-4):");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:
            

           fcfs[0]=h;
        
           
          for(int i=1;i<n+1;i++)
            {
              fcfs[i]=rq[i-1];
            }
          printf("\nOrder of execution:");
          for(int i=0;i<n+1;i++)
            {
              printf("  %d  ",fcfs[i]);
            }
          sf=0;
         for(int i=0;i<n;i++)
            {
               sf+=abs(fcfs[i+1]-fcfs[i]);
            }
         
          printf("\n\nseek time is %d",sf);
          
         break;


    case 2:


             
             sstf[0]=h;
             for(int i=0;i<n;i++)

              {
                 flag[i]=0;
              }
                
             e=h;
             j=1000;
             minimum=0;


             for(int z=1;z<n+1;z++)
             {
                
             for(int i=0;i<n;i++)

              {

                if((j>abs(e-rq[i]))&&(flag[i]==0))

                 {
                   j=abs(e-rq[i]);
                   minimum=i;
                 }
                
              }
          
            
             j=1000;
             sstf[z]=rq[minimum];
             e=rq[minimum];
             flag[minimum]=1;
           }
             
          printf("\nOrder of execution:");
          for(int i=0;i<n+1;i++)
            {
              printf("  %d  ",sstf[i]);
            }
            
 

            sf=0;
            for(int i=0;i<n;i++)
            {
               sf+=abs(sstf[i+1]-sstf[i]);
            }
         
          printf("\n\nseek time is %d",sf);



          break;

case 3:  

        for(int i=0;i<n+1;i++)
            {
               if(input[i]==h)
                 {
                   mk=i;
                 }
            }
       
        scan[0]=h;
        k=1;
        for(int i=mk+1;i<n+1;i++)
        {

          scan[k]=input[i];
          k++;
        }
       scan[k]=s;
       k++;
       for( int i=mk-1;i>=0;i--)
        {
          scan[k]=input[i];
          k++;
        }
       scan[k]=0;

       printf("\nOrder of execution:");
       for(int i=0;i<n+3;i++)
            {
              printf("  %d  ",scan[i]);
            }
      
       
        sf=0;

       for(int i=0;i<n+3;i++)
         {
               sf+=abs(scan[i+1]-scan[i]);
          }

        printf("\n\nseek time is %d",sf);

       break;


case 4:exit(0);
       

default:printf("Wrong choice!!!");


}
}
}


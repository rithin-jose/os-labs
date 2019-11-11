#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void main()
{
 FILE *f1,*f2,*f3,*f4;
 char lable[20],opcode[20],rest[20],optab[20];
 int LOCCTR,starting_address,address,flag=0;
 
 LOCCTR=0;

 f1=fopen("input.dat","r");
 f2=fopen("symtab.dat","w");
 f3=fopen("optab.dat","r");
 f4=fopen("out.dat","w");
 
 printf("Input File\n");
 while(strcmp(opcode,"END")!=0)
 {
  fscanf(f1,"%s %s %s",lable,opcode,rest);
  printf("%s %s %s\n",lable,opcode,rest);
 
  if(strcmp(opcode,"START")==0 && strlen(rest)>0)
  {
   starting_address=atoi(rest);
   address=starting_address;
   LOCCTR=starting_address;
  }
  

  if(strcmp(opcode,"WORD")==0)
{   address+=3;
   LOCCTR+=3;}
  else if(strcmp(opcode,"BYTE")==0)
 {
   address+=1;
   LOCCTR+=1;
}
  else if(strcmp(opcode,"RESW")==0)
   { address+=(3*atoi(rest));
    LOCCTR+=(3*atoi(rest));}
  else if(strcmp(opcode,"RESB")==0)
{   address+=atoi(rest);
   LOCCTR+=atoi(rest);}
  else if(strcmp(opcode,"START")==0)
{   address=address;
   LOCCTR+=address;}
  else
{   address+=3;
   LOCCTR+=address;
}
  fprintf(f4,"%d %s %s\n",address,opcode,rest);
  
  if(strcmp(lable,"**")==0)
  ;
  else
  {
   fprintf(f2,"%s\n",lable);
  }
  
 }
  printf("\nProcessing input file\n");
  printf("Creating out.bat file\n");
  printf("Creating Symtab.bat\n\n");
  printf("output File\n"); 
  int length;
  length=LOCCTR-starting_address;
  printf("length of file =",length);
}


/*printf("Symbol table\n");
 while(fscanf(f1,"%s",lable)!=EOF)
  {
   printf("%s",lable);
  }
  }*/

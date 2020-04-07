#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
int option;
printf("1.cpu\n2.memory\n3.hard disk\n4.random\n");
scanf("%d",&option);

srand(time(0));
if(option>3)
	option=rand()%3+1;
if(option==1)
{
	printf("Cpu \n");
	int f=0;
	printf("1.fixed\n2.accending\n");
	scanf("%d",&f);
	if(f==1)
	{
	for(int i=0;i<10;i++){
	system("stress -c 2 -t 10 &");
	sleep(10);}
	}
	else
	{
	for(int i=0;i<15;i++){
	system("stress -c 2 -t 13 & ");
	sleep(15-i);
	}		
	}
	

}
else if(option==2)
{

printf("Memory \n");
int f=0;
	printf("1.fixed\n2.accending\n");
	scanf("%d",&f);
	if(f==1)
	{
	for(int i=0;i<10;i++){
	system("stress -m 2 -t 10 &");
	sleep(10);}
	}
	else
	{
	
	for(int i=0;i<15;i++){
	system("stress -m 2 -t 10 &");
	sleep(15-i);
	}		
	}
	
}
else if(option==3)
{

printf("Hard disk :\nWriting Junks and Syncing\n");
system("stress -i 1 -t 30");
FILE* f=fopen("test.txt","w");


for(int i=0;i<10000;i++)
{

char buff[200];
fwrite(buff,200,1,f);

}

}




return 0;



}

#include <stdio.h>
#include <unistd.h>
#include <time.h>
int main()
{
FILE* f;
time_t curtime;
char buffer[100];
while(1)
{
	FILE* f=fopen("/var/log/date.log","a+");
	time(&curtime);
	struct tm* info=localtime(&curtime);
	strftime(buffer,100,"%F_%T",info);
	fprintf(f,"%s\n",buffer);
	sleep(600);
	fclose(f);
}
return 0;
}

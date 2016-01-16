#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylibxxx.h"

char * funenvx (char *pid, char *output, size_t limit)
{
//int funenvx (char *pid, char *output, size_t limit) {
	char str[80];

	strcpy(str, "/proc/");
	strcat(str, pid);
	strcat(str,"/environ");


	printf("%s\n",str);


	char ch;
	FILE *fp;
	fp = fopen(str,"r");

	int count = 0;
	while( ( ch = fgetc(fp) ) != EOF ) {
		if(count == limit)
			continue;
		output[count] = ch;
		count++;
	}

	fclose(fp);

	return 0;
}



int funpwd (char* spid,char * target_path,size_t limit)
{
 char link_path[256]="/proc/";
 int len;
 
 strcat(strcat(link_path,spid),"/cwd");
    
 len = readlink (link_path, target_path, limit);
 printf("link_path='%s',target_path='%s',len=%i\n",link_path,target_path,len);
  target_path[len] = '\0';
    
  return 0;
}

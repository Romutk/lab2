#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "mylibxxx.h"

int main (int argc, char* argv[])
//int main (int argc, char const * argv[])
{

char target_path[256];

if( argc<2 )  return 1;
funpwdx (argv[1],target_path,sizeof(target_path));




//int result = funpwdx();
printf ("%s\n", target_path);
return 0;
}

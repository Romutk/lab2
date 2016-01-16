#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "mylibxxx.h"

int main(int argc, char const *argv[])
//int main (int argc, char const * argv[])
{
if( argc<2 )  return 1;
char output[256];

//int result = funxxx();
funenvx(argv[1], output, sizeof(output));
printf ("%s\n", output);
return 0;
}

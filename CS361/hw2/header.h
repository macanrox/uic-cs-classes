#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <setjmp.h>
#include <limits.h>
#include <setjmp.h>
#include <math.h>   //for the power

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/resource.h>

#define COMMANDS 20
#define MAX_LEN 512

#define TRUE 1
#define FALSE 0
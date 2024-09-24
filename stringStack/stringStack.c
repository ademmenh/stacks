
#ifndef _stringSTACK_C
    #define _stringSTACK_C
#endif

#ifndef _STDBOOL_H
    #include <stdbool.h>
#endif

#ifndef _STDIO_H
    #include <stdio.h>
#endif

#ifndef _STDLIB_H
    #include <stdlib.h>
#endif

#ifndef _stringLIST_C
    #include "stringList.c"
#endif





typedef struct stringStack
{
    stringNode *H;
} stringStack;


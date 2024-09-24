
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


void funcstringStackInit (stringStack *pStack)
{
    pStack->H = NULL;
}

void funcstringStackPush (stringStack *pStack, string value)
{

    stringNode *vpNew, *vpTemp;


    if ( pStack==NULL )
    {
    
        pStack->H = funcstringNodeCreate (value); 
        pStack->H->Next = NULL;
    }
    else
    {
        vpTemp = pStack->H;
        pStack->H = funcstringNodeCreate (value);
        pStack->H->Next = vpTemp;
    }
}

bool funcstringStackEmpty (stringStack Stack)
{
    if ( Stack.H==NULL )
    {
        return true;
    }
    else
    {
        return false;
    }
}


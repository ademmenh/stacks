
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

void funcstringStackPop (stringStack *pStack, string *pholder)
{

    if ( pStack->H==NULL )
    {
        printf ("the stack is alredy empty !");
        exit (1);
    }


    stringNode *vpTemp;
    
    (*pholder) = pStack->H->Value;
    vpTemp = pStack->H;
    pStack->H = pStack->H->Next;

    funcstringNodeFree (vpTemp);
}

void funstringtStackTop (stringStack Stack, string *pholder)
{
    if ( Stack.H==NULL )
    {
        printf ("the stack is already empty !");
        exit (1);
    }

    (*pholder) = (Stack.H)->Value;
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


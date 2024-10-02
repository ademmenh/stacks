
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



void funcstringStackCreate (stringStack *pStack, int stackSize)
{

    string vsInput;
    int viCn;
    for ( viCn=0; viCn<stackSize; viCn++ )
    {
        // printf ("the current size is: %d.\n", pList->length);
        funcstringInput(&vsInput);
        funcstringStackPush (pStack, vsInput);
    }
}

void funcintStackDisplay (stringStack Stack)
{
    stringNode *vpCn;
    int viCn;


    if ( funcstringStackEmpty(Stack) )
    {
        printf ("The List is Empty!");
        return;
    }


    vpCn = Stack.H;
    viCn = 0;
    while ( vpCn!=NULL )
    {
        printf ("The value n %d is: %d.\n", viCn, vpCn->Value);
        viCn++;
        vpCn = vpCn->Next;
    }

}


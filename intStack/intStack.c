
#define _intSTACK_C

#ifndef _STDBOOL_H
    #include <stdbool.h>
#endif

#ifndef _STDIO_H
    #include <stdio.h>
#endif

#ifndef _STDLIB_H
    #include <stdlib.h>
#endif

#ifndef _intLIST_C
    #include "intList.c"
#endif





typedef struct intStack
{
    intNode *H;
} intStack;



void funcintStackInit (intStack *pStack)
{
    pStack->H = NULL;
}

void funcintStackPush (intStack *pStack, int value)
{

    intNode *vpNew, *vpTemp;


    if ( pStack==NULL )
    {
    
        pStack->H = funcintNodeCreate (value); 
        pStack->H->Next = NULL;
    }
    else
    {
        vpTemp = pStack->H;
        pStack->H = funcintNodeCreate (value);
        pStack->H->Next = vpTemp;
    }
}

void funcintStackPop (intStack *pStack, int *pholder)
{

    if ( pStack->H==NULL )
    {
        printf ("the stack is alredy empty !");
        exit (1);
    }


    intNode *vpTemp;
    
    (*pholder) = pStack->H->Value;
    vpTemp = pStack->H;
    pStack->H = pStack->H->Next;

    funcintNodeFree (vpTemp);
}

void funcintStackTop (intStack Stack, int *pholder)
{
    if ( Stack.H==NULL )
    {
        printf ("the stack is already empty !");
        exit (1);
    }

    (*pholder) = (Stack.H)->Value;
}

bool funcintStackEmpty (intStack Stack)
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



void funcintStackCreate (intStack *pStack, int stackSize)
{

    int viInput;
    int viCn;
    for ( viCn=0; viCn<stackSize; viCn++ )
    {
        viInput = funcintInput();
        funcintStackPush (pStack, viInput);
    }
}

void funcintStackDisplay (intStack Stack)
{
    intNode *vpCn;
    int viCn;


    if ( funcintStackEmpty(Stack) )
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

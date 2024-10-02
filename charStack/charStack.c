

#define _charSTACK_C

#ifndef _STDBOOL_H
    #include <stdbool.h>
#endif

#ifndef _STDIO_H
    #include <stdio.h>
#endif

#ifndef _STDLIB_H
    #include <stdlib.h>
#endif

#ifndef _charLIST_C
    #include "charList.c"
#endif





typedef struct charStack
{
    charNode *H;
} charStack;



void funccharStackInit (charStack *pStack)
{
    pStack->H = NULL;
}

void funccharStackPush (charStack *pStack, char value)
{

    charNode *vpNew, *vpTemp;


    if ( pStack==NULL )
    {
    
        pStack->H = funccharNodeCreate (value); 
        // pStack->H->Next = NULL;
    }
    else
    {
        vpTemp = pStack->H;
        pStack->H = funccharNodeCreate (value);
        pStack->H->Next = vpTemp;
    }
}

void funccharStackPop (charStack *pStack, char *pholder)
{

    if ( pStack->H==NULL )
    {
        printf ("the stack is alredy empty !");
        exit (1);
    }


    charNode *vpTemp;
    
    (*pholder) = pStack->H->Value;
    vpTemp = pStack->H;
    pStack->H = pStack->H->Next;

    funccharNodeFree (vpTemp);
}

void funccharStackTop (charStack Stack, char *pholder)
{
    if ( Stack.H==NULL )
    {
        printf ("the stack is already empty !");
        exit (1);
    }

    (*pholder) = (Stack.H)->Value;
}

bool funccharStackEmpty (charStack Stack)
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


#ifndef _func_CHARINPUT
    char funccharInput ()
    {

        char vcChar, vcBuffer;

        printf ("Enter the value: ");
        vcChar = getchar(); // fgetc (stdin)
        vcBuffer = vcChar;
        while (vcBuffer!='\n')
        {vcBuffer = getchar();}

        return vcChar;
    }
#endif

void funccharStackCreate (charStack *pStack, int stackSize)
{

    char vcInput;
    int viCn;
    for ( viCn=0; viCn<stackSize; viCn++ )
    {
        // printf ("the current size is: %d.\n", pList->length);
        vcInput = funccharInput();
        funccharStackPush (pStack, vcInput);
    }
}

void funccharStackDisplay (charStack Stack)
{
    charNode *vpCn;
    int viCn;


    if ( funccharStackEmpty(Stack) )
    {
        printf ("The List is Empty!");
        return;
    }


    vpCn = Stack.H;
    viCn = 0;
    while ( vpCn!=NULL )
    {
        printf ("The value n %d is: %c.\n", viCn, vpCn->Value);
        viCn++;
        vpCn = vpCn->Next;
    }

}


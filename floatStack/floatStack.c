
#ifndef _floatSTACK_C
    #define _floatSTACK_C
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

#ifndef _floatLIST_C
    #include "floatList.c"
#endif





typedef struct floatStack
{
    floatNode *H;
} floatStack;



void funcfloatStackInit (floatStack *pStack)
{
    pStack->H = NULL;
}

void funcfloatStackPush (floatStack *pStack, float value)
{

    floatNode *vpNew, *vpTemp;


    if ( pStack->H==NULL )
    {
        pStack->H = funcfloatNodeCreate (value);
    //  pStack->H->Value = NULL; (done by funcfloatNodeCreate)
    }
    else
    {
        vpTemp = pStack->H;
        pStack->H = funcfloatNodeCreate (value);
        pStack->H->Next = vpTemp;
    }
}

void funcfloatStackPop (floatStack *pStack, float *pholder)
{

    if ( pStack->H==NULL )
    {
        printf ("the stack is alredy empty !");
        exit (1);
    }


    floatNode *vpTemp;
    
    (*pholder) = pStack->H->Value;
    vpTemp = pStack->H;
    pStack->H = pStack->H->Next;

    funcfloatNodeFree (vpTemp);
}

void funcfloatStackTop (floatStack Stack, float *pholder)
{
    if ( Stack.H==NULL )
    {
        printf ("the stack is already empty !");
        exit (1);
    }

    (*pholder) = (Stack.H)->Value;
}

bool funcfloatStackEmpty (floatStack Stack)
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



float funcfloatInput ()
{
    float vfInput;
    printf ("Enter your value: ");
    scanf ("%f", &vfInput);
    
    return vfInput;
}

void funcfloatStackCreate (floatStack *pStack, int stackSize)
{

    float vfInput;
    int viCn;
    for ( viCn=0; viCn<stackSize; viCn++ )
    {
        // printf ("the current size is: %d.\n", pList->length);
        vfInput = funcfloatInput();
        funcfloatStackPush (pStack, vfInput);
    }
}

void funcfloatStackDisplay (floatStack Stack)
{
    floatNode *vpCn;
    int viCn;


    if ( funcfloatStackEmpty(Stack) )
    {
        printf ("The List is Empty!");
        return;
    }


    vpCn = Stack.H;
    viCn = 0;
    while ( vpCn!=NULL )
    {
        printf ("The value n %d is: %f.\n", viCn, vpCn->Value);
        viCn++;
        vpCn = vpCn->Next;
    }

}



int main ()
{

    floatStack vsFloats;
    funcfloatStackInit (&vsFloats);

    
    printf ("Creating intStack:\n");
    funcfloatStackCreate (&vsFloats, 5);
    printf ("\n\n");
    


    printf ("Displaying the Stack:\n");
    funcfloatStackDisplay (vsFloats);
    printf ("\n\n");



    printf ("Pushing some values:\n");
    funcfloatStackPush (&vsFloats, 10);
    funcfloatStackPush (&vsFloats, 11);
    funcfloatStackPush (&vsFloats, 12);
    printf ("\n\n");



    printf ("Displaying the Stack:\n");
    funcfloatStackDisplay (vsFloats);
    printf ("\n\n");


    
    float holder;
    printf ("Poping some values:\n");
    funcfloatStackPop (&vsFloats, &holder);
    funcfloatStackPop (&vsFloats, &holder);
    printf ("\n\n");



    printf ("Displaying the Stack:\n");
    funcfloatStackDisplay (vsFloats);
    printf ("\n\n");



    return 0;
}
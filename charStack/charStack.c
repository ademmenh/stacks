
#ifndef charStackIsImported
    #define charStackIsImported
#endif

#ifndef stdboolIsImported
    #define stdboolIsImported
    #include <stdbool.h>
#endif

#ifndef stdioIsImported
    #define stdioIsImported
    #include <stdio.h>
#endif

#ifndef stdlibIsImported
    #define stdlibIsImported
    #include <stdlib.h>
#endif

#ifndef charListIsImported
    #define charListIsImported
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



int main ()
{

    charStack vsIntigers;
    funccharStackInit (&vsIntigers);

    
    printf ("Creating intStack:\n");
    funccharStackCreate (&vsIntigers, 1);
    printf ("\n\n");
    


    printf ("Displaying the Stack:\n");
    funccharStackDisplay (vsIntigers);
    printf ("\n\n");



    printf ("Pushing some values:\n");
    funccharStackPush (&vsIntigers, 'A');
    funccharStackPush (&vsIntigers, 'B');
    funccharStackPush (&vsIntigers, 'C');
    printf ("\n\n");



    printf ("Displaying the Stack:\n");
    funccharStackDisplay (vsIntigers);
    printf ("\n\n");


    
    char holder;
    printf ("Poping some values:\n");
    funccharStackPop (&vsIntigers, &holder);
    funccharStackPop (&vsIntigers, &holder);
    printf ("\n\n");



    printf ("Displaying the Stack:\n");
    funccharStackDisplay (vsIntigers);
    printf ("\n\n");



    return 0;
}
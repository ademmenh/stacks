
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
        pStack->H = funcharNodeCreate (value);
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



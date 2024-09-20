
#ifndef floatStackIsImported
    #define floatStackIsImported
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

#ifndef floatListIsImported
    #define floatListIsImported
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


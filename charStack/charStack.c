
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

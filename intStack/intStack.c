
#ifndef intListIsImported
    #include "intList.c"
#endif


typedef intNode *intStack;


void funcintStackInit (intStack Stack)
{
    Stack = NULL;
}

void funcintStackPush (intStack *pStack, int value)
{

    intNode *vpNew, *vpTemp;


    if ( pStack==NULL )
    {
    
        (*pStack) = funcintNodeCreate (value); 
        (*pStack)->Next = NULL;
    }
    else
    {
        vpTemp = (*pStack);
        (*pStack) = funcintNodeCreate (value);
        (*pStack)->Next = vpTemp;
    }
}

void funcintStackPop (intStack *pStack, int *pholder)
{

    if ( pStack==NULL )
    {
        printf ("the stack is alredy empty !");
        exit (1);
    }


    intNode *vpTemp;
    
    vpTemp = (*pStack);
    (*pStack) = (*pStack)->Next;
    funcintNodeFree (vpTemp); 

}





int main ()
{
    
    
    return 0;
}
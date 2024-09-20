
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







int main ()
{
    
    
    return 0;
}
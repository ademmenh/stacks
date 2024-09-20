
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

    if ( (*pStack)==NULL )
    {
        printf ("the stack is alredy empty !");
        exit (1);
    }


    intNode *vpTemp;
    
    (*pholder) = (*pStack)->Value;
    vpTemp = (*pStack);
    (*pStack) = (*pStack)->Next;

    funcintNodeFree (vpTemp);
}

void funcintStackTop (intStack Stack, int *pholder)
{
    if ( Stack==NULL )
    {
        printf ("the stack is already empty !");
        exit (1);
    }

    (*pholder) = Stack->Value;
}

bool funcintStackEmpty (intStack Stack)
{
    if ( Stack==NULL )
    {
        return true;
    }
    else
    {
        return false;
    }
}



int funcintInput ()
{
    int viInput;
    printf ("Enter your value: ");
    scanf ("%d", &viInput);
    
    return viInput;
}

void funcintStackCreate (intStack *pStack, int stackSize)
{
    int viInput;
    int viCn;
    
    for ( viCn=0; viCn<stackSize; viCn++ )
    {
        // printf ("the current size is: %d.\n", pList->length);
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


    vpCn = Stack;
    viCn = 0;
    while ( vpCn!=NULL )
    {
        printf ("The value n %d is: %d.\n", viCn, vpCn->Value);
        viCn++;
        vpCn = vpCn->Next;
    }

}



int main ()
{

    // intStack vlIntigers;

    // funcintStackInit (&vlIntigers);


    
    
    return 0;
}

#ifndef _intLIST_C
    #define _intLIST_C
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





typedef struct intNode
{
    int Value;
    struct intNode *Next;
} intNode;

typedef struct intList
{
    intNode *H;
    int length;
} intList;



void funcintNodeInit (intNode *pNode)
{
    pNode->Value = 0;
    pNode->Next = NULL;
}

intNode* funcintNodeCreate (int value)
{

    intNode *vpNew = (intNode*) malloc (sizeof(intNode));
    if ( vpNew == NULL )
    {
        printf ("the allocation has failled !\n");
        exit (1);
    }

    funcintNodeInit (vpNew);
    vpNew->Value = value;

    return vpNew;
}

intNode* funcintNodePointer (intList List, int index)
{
    if ( index<0 )
    {
        printf ("this function do not supports negative indexing !");
        exit (1);
    }

    if ( List.length-1<index )
    {
        printf ("the index is out the scope !");
        exit (1);
    }

    intNode *vpCn = List.H;
    int viCn;

    for ( viCn=0; viCn<index; viCn++ )
    {
        vpCn = vpCn->Next;
    }
    
    return vpCn;
}

intNode* funcintNodePointerBefore (intList List, int index)
{

    intNode *vpCn;
    int viCn;



    if ( index<0 )
    {
        printf ("this function do not supports negative indexing !");
        exit (1);
    }
    


    if ( index==0 || List.length<index )
    {
        printf ("The index is out the range of the List !");
        exit (1);
    }


    vpCn = List.H;
    for ( viCn=0; viCn<index-1; viCn++ )
    {
        vpCn = vpCn->Next;
    }
    
    return vpCn;

}

void funcintNodeFree (intNode *pNode)
{
    pNode->Next = NULL;
    pNode->Value = 0;
    free (pNode);
}



void funcintListInit (intList *pList)
{
    pList->H = NULL;
    pList->length = 0;
}

bool funcintListIsEmpty (intList List)
{
    if ( List.length==0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void funcintListInsert (intList *pList, int index, int value)
{

    intNode *vp, *vpTemp, *vpNew;


    if ( index==0 )
    {
        vpTemp = pList->H;
        vpNew = funcintNodeCreate(value);
            
        pList->H = vpNew;
        vpNew->Next = vpTemp;
    }
    else
    {
        vp = funcintNodePointerBefore (*pList, index);
        vpTemp = vp->Next;
        vpNew = funcintNodeCreate (value);

        vp->Next = vpNew;
        vpNew->Next = vpTemp;
    }



    pList->length++;
}

void funcintListInsertBeging (intList *pList, int value)
{
    funcintListInsert (pList, 0, value);
}

void funcintListInsertEnd (intList *pList, int value)
{
    funcintListInsert (pList, pList->length, value);
}

int funcintListat (intList List, int index)
{
    intNode *vp = funcintNodePointer(List, index);
    return vp->Value;
}

int funcintListIndex (intList List, int value)
{
    intNode *vpCn;
    int viCn;

    viCn = 0;
    vpCn = List.H;
    while ( vpCn!=NULL )
    {
        if ( vpCn->Value==value )
        {
            return viCn;
        }
        
        viCn++;
        vpCn = vpCn->Next;
    }

    printf ("the index is not found !");
    exit (1);
}

int funcintListCount (intList List, int value)
{
    int viCn;
    int viCount;
    intNode *vpCn;

    viCn = 0;
    vpCn = List.H;
    viCount = 0;
    for ( viCn=0; viCn<List.length; viCn++ )
    {
        if ( vpCn->Value==value )
        {
            viCount++;
        }
        
        vpCn = vpCn->Next;
    }
    
    return viCount;
}

void funcintListModify (intList *pList, int index, int value)
{
    intNode *vp = funcintNodePointer (*pList, index);
    vp->Value = value;
}

void funcintListRemove (intList *pList, int index)
{
    intNode *vp, *vpTemp;

    
    // the case that funcintNodePointerBefore do not handle
    if ( index==pList->length )
    {
        printf ("the index is out the range !");
        exit (1);
    }



    if ( index==0 )
    {
        vpTemp = pList->H;
        pList->H = pList->H->Next;

        funcintNodeFree (vpTemp);
    }
    else
    {
        vp = funcintNodePointerBefore (*pList, index);
        vpTemp = vp->Next;

        vp->Next = vp->Next->Next;
        funcintNodeFree (vpTemp);
    }



    pList->length--;
}

void funcintListRemoveBegin (intList *pList)
{
    funcintListRemove (pList, 0);
}

void funcintListRemoveEnd (intList *pList)
{
    funcintListRemove (pList, pList->length-1);
}

void funcintListClear (intList *pList)
{
    while (pList->length>0)
    {
        funcintListRemove (pList, 0);
    }
}



int funcintInput ()
{
    int viInput;
    printf ("Enter your value: ");
    scanf ("%d", &viInput);
    
    return viInput;
}

void funcintListCreateFIFO (intList *pList, int Listsize)
{
    int viInput;
    int viCn;
    
    for ( viCn=0; viCn<Listsize; viCn++ )
    {
        // printf ("the current size is: %d.\n", pList->length);
        viInput = funcintInput();
        funcintListInsertEnd (pList, viInput);
    }
}

void funcintListCreateLIFO (intList *pList, int Listsize)
{
    int viInput;
    int viCn;

    for ( viCn=0; viCn<Listsize; viCn++ )
    {
        // printf ("the current size is: %d.\n", pList->length);
        viInput = funcintInput();
        funcintListInsertBeging (pList, viInput);
    }
}

void funcintListSort (intList *pList)
{
    intNode *vpCn1, *vpCn2, *vpMin;
    int viMin;

    vpCn1 = pList->H;
    while ( vpCn1!=NULL )
    {

        vpMin = vpCn1;
        viMin = vpCn1->Value;
        vpCn2 = vpCn1->Next;
        while ( vpCn2!=NULL )
        {
            if ( vpCn2->Value<viMin )
            {
                vpMin = vpCn2;
                viMin = vpCn2->Value;
            }
 
            vpCn2 = vpCn2->Next;   
        }

        vpMin->Value = vpCn1->Value;
        vpCn1->Value = viMin;

        vpCn1 = vpCn1->Next;
    }
}

void funcintListSortReversed (intList *pList)
{

    intNode *vpCn1, *vpCn2, *vpMax;
    int viMax;

    vpCn1 = pList->H;
    while ( vpCn1!=NULL )
    {

        vpMax = vpCn1;
        viMax = vpCn1->Value;
        vpCn2 = vpCn1->Next;
        while ( vpCn2!=NULL )
        {
            if ( viMax<vpCn2->Value )
            {
                vpMax = vpCn2;
                viMax = vpCn2->Value;
            }

            vpCn2 = vpCn2->Next;
        }

        vpMax->Value = vpCn1->Value;
        vpCn1->Value = viMax;
        
        vpCn1 = vpCn1->Next;
    }
}

void funcintListDisplay (intList List)
{
    intNode *vpCn;
    int viCn;


    if ( List.length==0 )
    {
        printf ("The List is Empty!");
        return;
    }


    vpCn = List.H;
    viCn = 0;
    while ( vpCn!=NULL && viCn<List.length )
    {
        printf ("The value n %d is: %d.\n", viCn, vpCn->Value);
        viCn++;
        vpCn = vpCn->Next;
    }

}


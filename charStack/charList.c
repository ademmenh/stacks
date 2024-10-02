
#define _charLIST_C

#ifndef _STDBOOL_H
    #include <stdbool.h>
#endif

#ifndef _STDIO_H
    #include <stdio.h>
#endif

#ifndef _STDLIB_H
    #include <stdlib.h>
#endif





typedef struct charNode
{
    char Value;
    struct charNode *Next;
} charNode;

typedef struct charList
{
    charNode *H;
    int length;
} charList;



void funccharNodeInit (charNode *pNode)
{
    pNode->Value = ' ';
    pNode->Next = NULL;
}

charNode* funccharNodeCreate (float value)
{

    charNode *vpNew = (charNode*) malloc(sizeof(charNode));
    if ( vpNew == NULL )
    {
        printf ("the allocation has failled !\n");
        exit (1);
    }

    funccharNodeInit (vpNew);
    vpNew->Value = value;

    return vpNew;
}


charNode* funccharNodePointer (charList List, int index)
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

    charNode *vpCn = List.H;
    int viCn;

    for ( viCn=0; viCn<index; viCn++ )
    {
        vpCn = vpCn->Next;
    }
    
    return vpCn;
}

charNode* funccharNodePointerBefore (charList List, int index)
{


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

    charNode *vpCn;
    int viCn;

    vpCn = List.H;
    for ( viCn=0; viCn<index-1; viCn++ )
    {
        vpCn = vpCn->Next;
    }
    
    return vpCn;

}

void funccharNodeFree (charNode *pNode)
{
    pNode->Next = NULL;
    pNode->Value = ' ';
    free (pNode);
}


/*
void funccharListInit (charList *pList)
{
    pList->H = NULL;
    pList->length = 0;
}
*/

bool funccharListIsEmpty (charList List)
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

void funccharListInsert (charList *pList, int index, char value)
{

    charNode *vp, *vpTemp, *vpNew;


    if ( index==0 )
    {
        vpTemp = pList->H;
        vpNew = funccharNodeCreate(value);
            
        pList->H = vpNew;
        vpNew->Next = vpTemp;
    }
    else
    {
        vp = funccharNodePointerBefore (*pList, index);
        vpTemp = vp->Next;
        vpNew = funccharNodeCreate (value);

        vp->Next = vpNew;
        vpNew->Next = vpTemp;
    }



    pList->length++;
}

void funccharListInsertBeging (charList *pList, char value)
{
    funccharListInsert (pList, 0, value);
}

void funccharListInsertEnd (charList *pList, char value)
{
    funccharListInsert (pList, pList->length, value);
}

char funccharListat (charList List, int index)
{
    charNode *vp = funccharNodePointer(List, index);
    return vp->Value;
}

int funccharListIndex (charList List, char value)
{
    charNode *vpCn;
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

    printf ("the value was not found !");
    exit (1);
}

int funccharListCount (charList List, char value)
{
    int viCn;
    int viCount;
    charNode *vpCn;

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

void funccharListModify (charList *pList, int index, char value)
{
    charNode *vp = funccharNodePointer (*pList, index);
    vp->Value = value;
}

void funccharListRemove (charList *pList, int index)
{
    charNode *vp, *vpTemp;

    
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

        funccharNodeFree (vpTemp);
    }
    else
    {
        vp = funccharNodePointerBefore (*pList, index);
        vpTemp = vp->Next;

        vp->Next = vp->Next->Next;
        funccharNodeFree (vpTemp);
    }



    pList->length--;
}

void funccharListRemoveBegin (charList *pList)
{
    funccharListRemove (pList, 0);
}

void funccharListRemoveEnd (charList *pList)
{
    funccharListRemove (pList, pList->length-1);
}

void funccharListClear (charList *pList)
{
    while (pList->length>0)
    {
        funccharListRemove (pList, 0);
    }
}


#ifndef _func_CHARINPUT
    char funccharInput ()
    {
        char vcInput;
        printf ("Enter your value: ");
        scanf ("%c", &vcInput);
    
        return vcInput;
    }
#endif

void funccharListCreateFIFO (charList *pList, int Listsize)
{
    char vcInput;
    int viCn;
    
    for ( viCn=0; viCn<Listsize; viCn++ )
    {
        // printf ("the current size is: %d.\n", pList->length);
        vcInput = funccharInput();
        funccharListInsertEnd (pList, vcInput);
    }
}

void funccharListCreateLIFO (charList *pList, int Listsize)
{
    int vcInput;
    int viCn;

    for ( viCn=0; viCn<Listsize; viCn++ )
    {
        // printf ("the current size is: %d.\n", pList->length);
        vcInput = funccharInput();
        funccharListInsertBeging (pList, vcInput);
    }
}

void funccharListSort (charList *pList)
{
    charNode *vpCn1, *vpCn2, *vpMin;
    char vcMin;

    vpCn1 = pList->H;
    while ( vpCn1!=NULL )
    {

        vpMin = vpCn1;
        vcMin = vpCn1->Value;
        vpCn2 = vpCn1->Next;
        while ( vpCn2!=NULL )
        {
            if ( vpCn2->Value<vcMin )
            {
                vpMin = vpCn2;
                vcMin = vpCn2->Value;
            }
 
            vpCn2 = vpCn2->Next;   
        }

        vpMin->Value = vpCn1->Value;
        vpCn1->Value = vcMin;

        vpCn1 = vpCn1->Next;
    }
}

void funccharListSortReversed (charList *pList)
{

    charNode *vpCn1, *vpCn2, *vpMax;
    char vcMax;

    vpCn1 = pList->H;
    while ( vpCn1!=NULL )
    {

        vpMax = vpCn1;
        vcMax = vpCn1->Value;
        vpCn2 = vpCn1->Next;
        while ( vpCn2!=NULL )
        {
            if ( vcMax<vpCn2->Value )
            {
                vpMax = vpCn2;
                vcMax = vpCn2->Value;
            }

            vpCn2 = vpCn2->Next;
        }

        vpMax->Value = vpCn1->Value;
        vpCn1->Value = vcMax;
        
        vpCn1 = vpCn1->Next;
    }
}

void funccharListDisplay (charList List)
{

    charNode *vpCn;
    char viCn;


    if ( List.length==0 )
    {
        printf ("The List is Empty!");
        return;
    }


    vpCn = List.H;
    viCn = 0;
    while ( vpCn!=NULL && viCn<List.length )
    {
        printf ("The value n %d is: %c.\n", viCn, vpCn->Value);
        viCn++;
        vpCn = vpCn->Next;
    }

}


#ifndef _stringLIST_C
    #define _stringLIST_C
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

#ifndef _STRING_C
    #include "string.c"
#endif





typedef struct stringNode
{
    string Value;
    struct stringNode *Next;
} stringNode;

typedef struct stringList
{
    stringNode *H;
    int length;
} stringList;



void funcstringNodeInit (stringNode *pNode)
{
    funcstringInit (&(pNode->Value));
    pNode->Next = NULL;
}

stringNode* funcstringNodeCreate (string value)
{

    stringNode *vpNew = (stringNode*) malloc(sizeof(stringNode));
    if ( vpNew == NULL )
    {
        printf ("the allocation has failled !\n");
        exit (1);
    }

    funcstringNodeInit (vpNew);
    vpNew->Value = value;

    return vpNew;
}

stringNode* funcstringNodePointer (stringList List, int index)
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

    stringNode *vpCn = List.H;
    int viCn;

    for ( viCn=0; viCn<index; viCn++ )
    {
        vpCn = vpCn->Next;
    }
    
    return vpCn;
}

stringNode* funcstringNodePointerBefore (stringList List, int index)
{

    stringNode *vpCn;
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

void funcstringNodeFree (stringNode *pNode)
{
    funcstringClear (&(pNode->Value));
    pNode->Next = NULL;
    
    free (pNode);
}



void funcstringListInit (stringList *pList)
{
    pList->H = NULL;
    pList->length = 0;
}

bool funcstringListIsEmpty (stringList List)
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

void funcstringListInsert (stringList *pList, int index, string value)
{

    stringNode *vp, *vpTemp, *vpNew;


    if ( index==0 )
    {
        vpTemp = pList->H;
        vpNew = funcstringNodeCreate(value);
            
        pList->H = vpNew;
        vpNew->Next = vpTemp;
    }
    else
    {
        vp = funcstringNodePointerBefore (*pList, index);
        vpTemp = vp->Next;
        vpNew = funcstringNodeCreate (value);

        vp->Next = vpNew;
        vpNew->Next = vpTemp;
    }



    pList->length++;
}

void funcstringListInsertBeging (stringList *pList, string value)
{
    funcstringListInsert (pList, 0, value);
}

void funcstringListInsertEnd (stringList *pList, string value)
{
    funcstringListInsert (pList, pList->length, value);
}

string funcstringListat (stringList List, int index)
{
    stringNode *vp = funcstringNodePointer(List, index);
    return vp->Value;
}

int funcstringListIndex (stringList List, string value)
{
    stringNode *vpCn;
    int viCn;

    viCn = 0;
    vpCn = List.H;
    while ( vpCn!=NULL )
    {
        if ( funcstringCompare(vpCn->Value, value)==0 )
        {
            return viCn;
        }
        
        viCn++;
        vpCn = vpCn->Next;
    }

    printf ("the value is not found !");
    exit (1);
}

int funcstringListCount (stringList List, string value)
{
    int viCn;
    int viCount;
    stringNode *vpCn;

    viCn = 0;
    vpCn = List.H;
    viCount = 0;
    for ( viCn=0; viCn<List.length; viCn++ )
    {
        if ( funcstringCompare(vpCn->Value, value)==0 )
        {
            viCount++;
        }
        
        vpCn = vpCn->Next;
    }
    
    return viCount;
}

void funcstringListModify (stringList *pList, int index, string value)
{
    stringNode *vp = funcstringNodePointer (*pList, index);
    vp->Value = value;
}


void funcstringListRemove (stringList *pList, int index)
{
    stringNode *vp, *vpTemp;

    
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

        funcstringNodeFree (vpTemp);
    }
    else
    {
        vp = funcstringNodePointerBefore (*pList, index);
        vpTemp = vp->Next;

        vp->Next = vp->Next->Next;
        funcstringNodeFree (vpTemp);
    }



    pList->length--;
}

void funcstringListRemoveBegin (stringList *pList)
{
    funcstringListRemove (pList, 0);
}

void funcstringListRemoveEnd (stringList *pList)
{
    funcstringListRemove (pList, pList->length-1);
}

void funcstringListClear (stringList *pList)
{
    while (pList->length>0)
    {
        funcstringListRemove (pList, 0);
    }
}


void funcstringInput_ (string *pString)
{

    char Buffer [STRING_MAX_LENGTH];
    int viBufferSize;
    char vcClearBuffer;

    int viCn;





    // printf ("Enter the String: ");
    fgets (Buffer, STRING_MAX_LENGTH, stdin);



    viBufferSize = strlen (Buffer);
    if ( Buffer[viBufferSize-1] != '\n' )
    {
        do
        {
            vcClearBuffer = getchar();
        } while ( vcClearBuffer!='\n' );
    }

    for ( viCn=0; viCn<viBufferSize; viCn++ )   // viBufferSize won't reach the '\0'
    {
        if ( Buffer[viCn]=='\n' )               // in case of the size is less than STRING_MAX_LENGTH
        {
            break;
        }
        funcstringInsertEnd (pString, Buffer[viCn]);
    }
}

void funcstringListCreateFIFO (stringList *pList, int Listsize)
{
    int viCn;
    string vsInput;
    
    for ( viCn=0; viCn<Listsize; viCn++ )
    {
        funcstringInit (&vsInput);
        printf ("Enter the value %d:", viCn);
        funcstringInput_ (&vsInput);
        funcstringListInsertEnd (pList, vsInput);
    }
}

void funcstringListCreateLIFO (stringList *pList, int Listsize)
{
    string vsInput;
    int viCn;

    for ( viCn=0; viCn<Listsize; viCn++ )
    {
        // printf ("the current size is: %d.\n", pList->length);
        funcstringInput(&vsInput);
        funcstringListInsertBeging (pList, vsInput);
    }
}

void funcstringListDisplay (stringList List)
{
    stringNode *vpCn;
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
        printf ("The value %d is: ", viCn);
        funcstringDisplay (vpCn->Value);
        printf ("\n");
        viCn++;
        vpCn = vpCn->Next;
    }

}


// int main ()
// {

//     stringList vlStrings;
//     funcstringListInit (&vlStrings);

//     printf ("Enter your strings:\n");
//     funcstringListCreateFIFO (&vlStrings, 5);
//     printf ("\n\n");



//     printf ("Displaying the list:\n");
//     funcstringListDisplay (vlStrings);
//     printf ("\n\n");


//     // printf ("inserting in list:\n");
//     // string vsString0, vsString1, vsString10;
//     // funcstringInit(&vsString0);
//     // funcstringInit(&vsString1);
//     // funcstringInit(&vsString10);
//     // funcstringListInsert (&vlStrings, 0, vsString0);
//     // funcstringListInsert (&vlStrings, 1, vsString1);
//     // funcstringListInsert (&vlStrings, vlStrings.length, vsString10);
//     // printf ("\n\n");



//     printf ("Displaying the list:\n");
//     funcstringListDisplay (vlStrings);
//     printf ("\n\n");



//     printf ("Displaying count: \n");
//     string vsString0;
//     funcstringInit(&vsString0);
//     funcstringAssign (&vsString0, "blabla");
//     int viCount = funcstringListIndex (vlStrings, vsString0);
//     printf ("%d", viCount);
//     printf ("\n\n");


//     return 0;
// }
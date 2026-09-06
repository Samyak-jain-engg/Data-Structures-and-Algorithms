#include <iostream>
#include "Server.h"

using std::cout;
using std::endl;

node::node()
{
    pPrev = NULL;
    iData = 0;
    pNext = NULL;
}

node::~node()
{
    pPrev = NULL;
    iData = 0;
    pNext = NULL;
}

list::list()
{
    pFirst = NULL;
}

list::~list()
{
    if (pFirst != NULL)
    {
        DeleteAll();
    }
}

void list::InsertFirst(int iNo)
{
    node *pNewnode = new node;

    pNewnode->iData = iNo;
    pNewnode->pPrev = NULL;

    if (pFirst == NULL)
    {
        pNewnode->pNext = NULL;
        pFirst = pNewnode;
        return;
    }

    pNewnode->pNext = pFirst;
    pFirst->pPrev = pNewnode;
    pFirst = pNewnode;
}

void list::InsertLast(int iNo)
{
    node *pNewnode = new node;

    pNewnode->iData = iNo;
    pNewnode->pNext = NULL;

    if (pFirst == NULL)
    {
        pNewnode->pPrev = NULL;
        pFirst = pNewnode;
        return;
    }

    node *pTemp = pFirst;

    while (pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }

    pNewnode->pPrev = pTemp;
    pTemp->pNext = pNewnode;
}

void list::Display()
{
    node *pTemp = pFirst;

    while (pTemp != NULL)
    {
        cout << "|" << pTemp->iData << "|->";
        pTemp = pTemp->pNext;
    }

    cout<< endl;
}

void list::DeleteAll()
{
    node *pTemp = NULL;

    while (pFirst != NULL)
    {
        pTemp = pFirst;
        pFirst = pFirst->pNext;

        delete pTemp;
    }
    cout<<"All Nodes Deleted";
}

int list ::DeleteFirst()
{
    int iDelData ;

    if(NULL ==pFirst)
        return -1;

    iDelData = pFirst->iData;
    
    if(NULL == pFirst->pNext)
    {
        delete(pFirst);
        pFirst = NULL;
    }
    else
    {
        pFirst = pFirst->pNext;
        pFirst->pPrev->pNext = NULL;

        delete(pFirst->pPrev);
        pFirst->pPrev = NULL;

    }

    return iDelData;

}
int list:: DeleteLast()
{
    int iDelData;
    node *pTemp = pFirst;

    if(NULL == pFirst)
        return-1;

    if(NULL == pTemp->pNext)
        pFirst = NULL;

    else{
        while(pTemp->pNext != NULL)
            pTemp = pTemp->pNext;

        pTemp->pPrev->pNext = NULL;
        pTemp->pPrev = NULL;
    }

    iDelData = pTemp->iData;
    delete(pTemp);

    return iDelData;
}

int list::CountNode()
{
    int iCount =0;
    node *pTemp = pFirst;


    while(pTemp != NULL)
    {
        iCount ++;
        pTemp = pTemp->pNext;
    }
    return iCount;
}

int list::SearchFirstOccurrence(int ikey)
{
    int iCount = 0;
    node *pTemp = pFirst;

    while(pTemp != NULL)
    {
        ++iCount;

        if(pTemp->iData == ikey)
            return iCount;

        pTemp =pTemp->pNext;    
    }    
    return 0;
}

int list::SearchLastOccurrence(int ikey)
{
    int iCount = 0;
    int iLastpos = 0;
    node *pTemp = pFirst;

    while(pFirst != NULL)
    {
        ++iCount;

        if(pFirst->iData == ikey)
            iLastpos = iCount;

        pFirst = pFirst->pNext;

    }
    return iLastpos;
}
int list::SearchAllOccurrence(int iKey)
{
    int iCount = 0;
    node *pTemp = pFirst;

    while(pTemp != NULL)
    {
        iCount ++;
        pTemp = pTemp->pNext;
    }
    return iCount;
}
void list::InsertAtPosition(int iNo, int iPos)
{
    int iCount;
    node *pNewNode = new node;
    node *pTemp = NULL;

    iCount = CountNode();

    if(iPos < 1 || iPos > iCount + 1)
    {
        printf("Position is invalid\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
        return;
    }

    pNewNode->iData = iNo;

    pTemp = pFirst;
    iCount = 1;

    while(iCount < iPos - 1)
    {
        iCount++;
        pTemp = pTemp->pNext;
    }

    pNewNode->pNext = pTemp->pNext;

    if(pTemp->pNext != NULL)
        pTemp->pNext->pPrev = pNewNode;

    pNewNode->pPrev = pTemp;

    pTemp->pNext = pNewNode;
}

int list::DeleteAtPosition(int iPos)
{
    int iCount;
    node *pTemp = NULL;

    iCount = CountNode();

    if(iPos <= 0 || iPos > iCount)
        return -1;

    if(iPos == 1)
        return DeleteFirst();

    pTemp = pFirst;
    iCount = 1;

    while(iCount < iPos)
    {
        iCount++;
        pTemp = pTemp->pNext;
    }

    pTemp->pPrev->pNext = pTemp->pNext;

    if(pTemp->pNext != NULL)
        pTemp->pNext->pPrev = pTemp->pPrev;

    iCount = pTemp->iData;

    pTemp->pNext = NULL;
    pTemp->pPrev = NULL;

    delete pTemp;

    return iCount;
}

void list::ReverseDisplay()
{
    if (NULL ==pFirst)
    {
        cout<<"List is empty";
        return;
    }
    
    while(pFirst->pNext !=NULL)
        pFirst = pFirst->pNext;

    while (pFirst != NULL)
    {
        cout<<"|"<<pFirst->iData<<"|->";
        pFirst =pFirst->pPrev;
    }
    cout<<endl;
        
}

void list::PhysicalReverse()
{
     node *pCurrent = pFirst;
     node *pPrev = NULL;

    while(pCurrent !=NULL)
    {
        pCurrent->pPrev =pCurrent->pNext;
        pCurrent->pNext =pPrev;
        pPrev =pCurrent;
        pCurrent = pCurrent->pPrev;
    }

    pFirst =pPrev;
}

void list::ConcatAtPosition(list &obj, int iPos)
{
    int iCount = CountNode();
    node *pTemp1 = NULL;
    node *pTemp2 = NULL;

    if (iPos <= 0 || iPos > iCount + 1)
    {
        cout << "Invalid Position" << endl;
        return;
    }

    if (obj.pFirst == NULL)
        return;

    if (iPos == 1)
    {
        if (pFirst == NULL)
            pFirst = obj.pFirst;

        else
        {
            pTemp2 = obj.pFirst;

            while (pTemp2->pNext != NULL)
            {
                pTemp2 = pTemp2->pNext;
            }

            pTemp2->pNext = pFirst;
            pFirst->pPrev = pTemp2;

            pFirst = obj.pFirst;
        }

        obj.pFirst = NULL;
        return;
    }

    pTemp1 = pFirst;
    iCount = 1;

    while (iCount < iPos - 1)
    {
        pTemp1 = pTemp1->pNext;
        iCount++;
    }

    pTemp2 = obj.pFirst;

    while (pTemp2->pNext != NULL)
        pTemp2 = pTemp2->pNext;

    pTemp2->pNext = pTemp1->pNext;

    if (pTemp1->pNext != NULL)
        pTemp1->pNext->pPrev = pTemp2;

    pTemp1->pNext = obj.pFirst;
    obj.pFirst->pPrev = pTemp1;

    obj.pFirst = NULL;
}

void list::ConcatList(list &obj)
{
    node *pTemp = NULL;

    if (obj.pFirst == NULL)
        return;

    if (pFirst == NULL)
    {
        pFirst = obj.pFirst;
        obj.pFirst = NULL;
        return;
    }

    pTemp = pFirst;

    while (pTemp->pNext != NULL)
        pTemp = pTemp->pNext;

    pTemp->pNext = obj.pFirst;
    obj.pFirst->pPrev = pTemp;

    obj.pFirst = NULL;
}
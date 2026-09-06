#include<iostream>
#include"server.h"

using std::cout;
using std::endl;

node::node()
{
    
    iData =0;
    pNext =NULL;
}

node:: ~node()
{
    iData =0;
    pNext =NULL;

} 

list ::list()
{
    pFirst =NULL;

}


list ::~list()
{
    if(pFirst != NULL)
        DeleteAll();
}


void list::InsertFrist( int iNo)
{
    node *pNewnode =new node;

    pNewnode->iData = iNo;

    if(NULL == pFirst)
    {
        pNewnode->pNext =NULL;
        pFirst = pNewnode;
        return;
    }
    
    pNewnode->pNext = pFirst;
    pFirst = pNewnode;

}

void list::InsertLast( int iNo)
{
    node *pNewnode = new node;
    node  *pTemp = pFirst;

    pNewnode->iData = iNo;
    pNewnode->pNext = NULL;

    if(pFirst == NULL)
    {
        pFirst =pNewnode;
        return;
    }


    while(pTemp->pNext !=NULL)
        pTemp = pTemp->pNext;

    pTemp->pNext = pNewnode; 

}

void list::Display()
{
    node *pTemp = pFirst;

    if(NULL == pTemp)
        return;

    while(pTemp != NULL)
    {
        cout<< "|" << pTemp->iData << "| -> ";
        pTemp = pTemp->pNext;
    }    

    cout<<endl;
}

void list::DeleteAll()
{
    node *pTemp = NULL;

    while(pFirst != NULL)
    {
        pTemp = pFirst;
        pFirst = pFirst->pNext;
        delete pTemp;
    }

}

int list::DeleteFirst()
{
    node *pTemp = pFirst;

    int iDelData = 0;

    if(NULL == pFirst)
    {
        cout<<"List is Empty";
        return -1;
    }

    pFirst = pTemp->pNext;
    iDelData = pTemp->iData;
    pTemp->pNext = NULL;
    delete(pTemp);

    return iDelData;;

}

int list::DeleteLast()
{
    node *pTemp = pFirst;

    int iDelData = 0;

    if(NULL == pFirst)
    {
        cout<<"List is Empty";
        return -1;
    }

    if(NULL == pFirst->pNext)
    {
        iDelData= pTemp->iData;
        delete(pTemp);
        pFirst = NULL;
    }

    else
    {
        while(pTemp->pNext->pNext != NULL)
            pTemp = pTemp->pNext;

        iDelData = pTemp->pNext->iData; 
        delete(pTemp->pNext);
        pTemp->pNext = NULL;
    }

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

int list::SearchFristOccurance(int ikey)
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

int list::SearchLastOccurance(int ikey)
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
int list::SearchAllOccurance(int iKey)
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
void list::PhysicalReverse()
{
    node *pNext =NULL;
    node *pCurrent = pFirst;
    node *pPrev = NULL;

    if(NULL == pFirst)
    {
        cout<<"list is Empty";
        return;
    }

    while(pCurrent != NULL)
    {
        pNext = pCurrent->pNext;
        pCurrent->pNext = pPrev;
        pPrev = pCurrent;
        pCurrent = pNext;
    }

     pFirst = pPrev;
}

void list::ReverseDisplay()
{
    if(NULL == pFirst)
    {
        cout<<"list is empty";
        return;
    }
    PhysicalReverse();
    Display();
    PhysicalReverse();
}
void list::ConcatAtPosition(list &obj, int iPos)
{
    if(obj.pFirst == NULL)
    {
        return;
    }

    if(iPos <= 1)
    {
        node *pTemp = obj.pFirst;

        while(pTemp->pNext != NULL)
        {
            pTemp = pTemp->pNext;
        }

        pTemp->pNext = pFirst;
        pFirst = obj.pFirst;
        obj.pFirst = NULL;

        return;
    }

    node *pTemp = pFirst;
    int i = 1;

    while(i < iPos - 1 && pTemp != NULL)
    {
        pTemp = pTemp->pNext;
        i++;
    }

    if(pTemp == NULL)
    {
        return;
    }

    node *pLast = obj.pFirst;

    while(pLast->pNext != NULL)
    {
        pLast = pLast->pNext;
    }

    pLast->pNext = pTemp->pNext;
    pTemp->pNext = obj.pFirst;

    obj.pFirst = NULL;
}

void list::ConcatList(list &obj)
{
if(obj.pFirst == NULL)
        return;

if(pFirst == NULL)
{
    pFirst = obj.pFirst;
    obj.pFirst = NULL;
    return;
}

node *pTemp = pFirst;

while(pTemp->pNext != NULL)
    pTemp = pTemp->pNext;

pTemp->pNext = obj.pFirst;

obj.pFirst = NULL;

}
void list::InsertAtPosition(int iNo, int iPos)
{
    if(iPos <= 0)
        return;

    node *pNewnode = new node;

    pNewnode->iData = iNo;
    pNewnode->pNext = NULL;

    if(iPos == 1)
    {
        pNewnode->pNext = pFirst;
        pFirst = pNewnode;
        return;
    }

    node *pTemp = pFirst;
    int iCount = 1;

    while(iCount < iPos - 1 && pTemp != NULL)
    {
        pTemp = pTemp->pNext;
        iCount++;
    }

    if(pTemp == NULL)
    {
        delete pNewnode;
        return;
    }

    pNewnode->pNext = pTemp->pNext;
    pTemp->pNext = pNewnode;
}

void list::DeleteAtPosition(int iPos)
{
    if(pFirst == NULL || iPos <= 0)
    {
        return;
    }

    if(iPos == 1)
    {
        node *pTemp = pFirst;

        pFirst = pFirst->pNext;

        delete pTemp;

        return;
    }

    node *pTemp = pFirst;
    int iCount = 1;

    while(iCount < iPos - 1 && pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;
        iCount++;
    }

    if(pTemp->pNext == NULL)
    {
        return;
    }

    node *pDelete = pTemp->pNext;

    pTemp->pNext = pDelete->pNext;

    delete pDelete;
}
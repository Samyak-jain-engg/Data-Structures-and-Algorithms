#include<iostream>
#include"server.h"

using std::cout;
using std::endl;

node::node()
{
    pNext = NULL;
    iData = 0;
}

node::~node()
{
    iData = 0;
    pNext = NULL;
}

list::list()
{
    pFirst = NULL;
    pTail = NULL;
}
list::~list()
{
    if(pFirst != NULL)
        DeleteAll();
}

void list::InsertFirst(int iNo)
{
    node *pNewNode = new node;

    if(NULL == pNewNode)
    {
        cout<<"List is Empty";
        return;
    }

    pNewNode->iData =iNo;
    
    if(pFirst ==NULL)
    {
       pFirst = pNewNode;
       //new node become first

       pTail = pNewNode;
       (pTail)->pNext=pNewNode;
       return;
    }
    pNewNode->pNext = pFirst;
    pFirst = pNewNode;
    (pTail)->pNext = pFirst;

}

void list::InsertLast(int iNo)
{
    node *pNewNode = new node;

    if(NULL == pNewNode)
    {
        cout<<"List is Empty";
        return;
    }

    pNewNode->iData = iNo;
    if(NULL == pFirst)
    {
        pFirst = pNewNode;
        pTail = pNewNode;
        (pTail)->pNext = pNewNode;
        return ;
    }

    (pTail) ->pNext =pNewNode;
    pTail = pNewNode;
    (pTail)->pNext = pFirst;

}
int list::DeleteFirst()
{
    int iDelData;

    if(NULL == pFirst)
        return -1;
    
    iDelData =(pFirst)->iData;
    
    if(pFirst == pTail)
    {
        delete(pFirst);
        pFirst = pTail = NULL;

    }
    else 
    {
        pFirst = (pFirst)->pNext;
        delete((pTail)->pNext);
        (pTail)->pNext = pFirst;
    }

    return iDelData;
}

int list::DeleteLast()
{
    int iDelData;
    node *pTemp = NULL;

    if(pFirst == NULL)
        return -1;

    iDelData = pTail->iData;

    // Only one node
    if(pFirst == pTail)
    {
        delete pTail;
        pFirst = NULL;
        pTail = NULL;

        return iDelData;
    }

    // Find the node before pTail
    pTemp = pFirst;

    while(pTemp->pNext != pTail)
    {
        pTemp = pTemp->pNext;
    }

    // Delete last node
    delete pTail;

    // Make pTemp the new tail
    pTail = pTemp;

    // Maintain circular link
    pTail->pNext = pFirst;

    return iDelData;
}

void list::DeleteAll()
{
    node *pTemp =NULL;

    (pTail)->pNext =NULL;

    while(pFirst != NULL)
    {
        pTemp =pFirst;
        pFirst = pTemp->pNext;
        delete(pTemp);
    }
     pTail =NULL;

}

void list::Display()
{
    node *pTemp = NULL;

    if(NULL == pFirst)
    {
        cout << "list is empty" << endl;
        return;
    }

    pTemp = pFirst;

    do
    {
        cout << "|" << pTemp->iData << "|->";

        pTemp = pTemp->pNext;

    } while(pTemp != pFirst);

    cout << endl;
}

int list::CountNodes()
{
  int iCount =0;
  node *pTemp = pFirst;

  if(NULL== pTemp)
        return 0;

    do
    {
        iCount++;
        pTemp = pTemp->pNext;

    }while(pTemp != pTail->pNext);

    return iCount;
}
int list::SearchFirstOccurrence(int iKey)
{
    int iCount = 0;
    node *pTemp = pFirst;
    
     if(NULL == pTemp)
       return  iCount;

    do
     {
        ++iCount;
        if(pTemp->iData ==iKey)
            return iCount;
        pTemp = pTemp->pNext;    
     }  while(pTemp != pTail->pNext);
     return iCount;

}
int list::SearchLastOccurrence(int iKey)
{
     int iCount =0;
    int iLastpos =0;

    node *pTemp = pFirst;

      if(NULL == pTemp)
       return  iCount;

    do
    {
        ++iCount;
        if(pTemp->iData ==iKey)
         iLastpos =iCount;
        pTemp= pTemp->pNext;
    } while(pTemp != pTail->pNext);

    return iLastpos;

}
int list::SearchAllOccurrences(int iKey)
{
    int iCount =0;

    node *pTemp = pFirst;

    if(NULL == pTemp)
       return  iCount;

    do
    {
        if(pTemp->iData ==iKey)
            ++iCount;
         pTemp = pTemp->pNext;
      
    }while(pTemp !=pTail->pNext);

    return iCount;
}
void list::ConcatList(list &obj)
{
  
    if(obj.pFirst == NULL)
        return;

   
    if(pFirst == NULL)
    {
        pFirst = obj.pFirst;
        pTail = obj.pTail;

        obj.pFirst = NULL;
        obj.pTail = NULL;

        return;
    }

   
    pTail->pNext = obj.pFirst;

    pTail = obj.pTail;

    pTail->pNext = pFirst;

    obj.pFirst = NULL;
    obj.pTail = NULL;
}

void list::ConcatAtPosition(list &obj, int iPos)
{
    int iCount;
    node *pTemp = NULL;


    if(obj.pFirst == NULL)
        return;

    iCount = CountNodes();

    if(iPos <= 0 || iPos > iCount + 1)
    {
        cout << "Position is invalid" << endl;
        return;
    }

    if(pFirst == NULL)
    {
        if(iPos == 1)
        {
            pFirst = obj.pFirst;
            pTail = obj.pTail;

            obj.pFirst = NULL;
            obj.pTail = NULL;
        }

        return;
    }

    if(iPos == 1)
    {
        obj.pTail->pNext = pFirst;

        pFirst = obj.pFirst;

        pTail->pNext = pFirst;

        obj.pFirst = NULL;
        obj.pTail = NULL;

        return;
    }

    if(iPos == iCount + 1)
    {
        pTail->pNext = obj.pFirst;

        pTail = obj.pTail;

        pTail->pNext = pFirst;

        obj.pFirst = NULL;
        obj.pTail = NULL;

        return;
    }

    pTemp = pFirst;

    iCount = 1;

    while(iCount < iPos - 1)
    {
        iCount++;
        pTemp = pTemp->pNext;
    }

   
    obj.pTail->pNext = pTemp->pNext;

    pTemp->pNext = obj.pFirst;

  
    obj.pFirst = NULL;
    obj.pTail = NULL;
}

void list::PhysicalReverse()
{
    node *pPrev = NULL;
    node *pCurrent = pFirst;
    node *pNext = NULL;

    if(pFirst == NULL || pFirst == pTail)
        return;

    pTail = pFirst;

    do
    {
        pNext = pCurrent->pNext;
        pCurrent->pNext = pPrev;

        pPrev = pCurrent;
        pCurrent = pNext;

    } while(pCurrent != pFirst);

    pFirst = pPrev;

    pTail->pNext = pFirst;
}

void list::ReverseDisplay()
{
    if(pFirst == NULL)
        return;

    node *pTemp = pFirst;

    while(pTemp->pNext != pFirst)
    {
        pTemp = pTemp->pNext;
    }

    node *pCurrent = pFirst;

  
}

void list::InsertAtPosition(int iNo, int iPos)
{
    int iCount;
    node *pNewNode = NULL;
    node *pTemp = NULL;

    iCount = CountNodes();

    if(iPos <= 0 || iPos > iCount + 1)
    {
        cout << "Invalid Position" << endl;
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
        return;
    }

    if(iPos == iCount + 1)
    {
        InsertLast(iNo);
        return;
    }

    pNewNode = new node;

    if(pNewNode == NULL)
        return;

    pNewNode->iData = iNo;

    pTemp = pFirst;

    iCount = 1;

    while(iCount < iPos - 1)
    {
        iCount++;
        pTemp = pTemp->pNext;
    }

    pNewNode->pNext = pTemp->pNext;
    pTemp->pNext = pNewNode;
}

int list::DeleteAtPosition(int iPos)
{
    int iCount;
    int iDelData;
    node *pTemp = NULL;
    node *pDelete = NULL;

    iCount = CountNodes();

    if(iPos <= 0 || iPos > iCount)
        return -1;

  
    if(iPos == 1)
    {
        return DeleteFirst();
    }

    
    if(iPos == iCount)
    {
        return DeleteLast();
    }

    pTemp = pFirst;
    iCount = 1;

    while(iCount < iPos - 1)
    {
        iCount++;
        pTemp = pTemp->pNext;
    }

    pDelete = pTemp->pNext;

    iDelData = pDelete->iData;

    pTemp->pNext = pDelete->pNext;

    delete pDelete;

    return iDelData;
}
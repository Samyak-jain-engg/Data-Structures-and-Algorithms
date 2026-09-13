#include<iostream>
#include"server.h"
#define MAX 10

using std :: cout;
using std :: endl;

node ::node()
{
    iData = 0;
    pNext = NULL;
}

node:: ~node()
{
    iData = 0;
    pNext = NULL;
} 

Queue :: Queue()
{
    pFront = NULL;
    pRear = NULL;
}

Queue ::~Queue()
{
    if(pFront != NULL)
        DeleteAll();
}

 void Queue ::EnQueue(int iNo)
{
    node *pNewnode = new node;

    if(IsFuLL())
    {
        cout<<"Queue is Full";
        return;
    }
    pNewnode->iData = iNo;

    if(pFront == NULL)
    {
        pFront = pNewnode;
        pRear = pNewnode;

        pRear->pNext = pFront;
        return;
    }

    pNewnode->pNext = pFront;
    pRear->pNext = pNewnode;

    pRear = pNewnode;

}
int Queue ::DeQueue()
{
    node *pTemp = NULL;
    int iDelData;

    if(IsEmpty())
    {
        cout<<"Queue is Empty"<<endl;
        return -1;
    }

    iDelData = pFront->iData;

    //1 Node

    if(pFront == pRear)
    {
        delete pFront;

        pFront = NULL;
        pRear = NULL;
        return iDelData;
    }

    pTemp = pFront;

    pFront = pFront->pNext;
    pRear->pNext = pFront;

    pTemp->pNext = NULL;

    delete pTemp;

    return iDelData;
}

bool Queue::IsEmpty()
{
    if(pFront == NULL)
        return-1;
    return  0;
}

bool Queue ::IsFuLL()
{
    if(CountNode() == MAX)
        return 1;
    return 0;    
}

int Queue::CountNode()
{
    int iCount = 0;
    node *pTemp = pFront;

    if(pFront == NULL)
        return 0;

    do
    {
        iCount++;

        pTemp = pTemp->pNext;

    } while(pTemp != pFront);


    return iCount;

}
void Queue::Display()
{
    node *pTemp = pFront;

    if(pFront == NULL)
    {
        cout<<"Queue is Empty"<<endl;
        return;
    }
    do
    {
        cout<<"|"<<pTemp->iData<<"|->";
        pTemp = pTemp->pNext;
    } while (pTemp != pFront);

    cout<<endl;
    
}
void Queue::DeleteAll()
{
    node *pTemp = NULL;

    while(pFront != NULL)
    {
        if(pFront == pRear)
        {
            delete pFront;

            pFront = NULL;
            pRear = NULL;

            break;
        }

        pTemp = pFront;

        pFront = pFront->pNext;

        pRear->pNext = pFront;

        delete pTemp;
    }
}




#include<iostream>
#include"Server.h"

using std:: cout;
using std :: endl;

#define MAX 20

node:: node()
{
    iData = 0;
    pNext = NULL;
}

node ::~node()
{
    iData = 0;
    pNext = NULL;
}

Queue ::Queue()
{
    pQueue = NULL;
}

Queue :: ~Queue()
{
    if(pQueue != NULL)
        DeleteAll();
}

void Queue ::EnQueue(int iNo)
{
    node *pNewNode = new node;
    node *pTemp = NULL;

    if(IsQueueFull())
    {
        cout<<"Queue is Full";
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if(pQueue == NULL)
    {
        pQueue = pNewNode;
        return;
    }

    pTemp =pQueue;

      while(pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }

    pTemp->pNext = pNewNode;
}

int Queue::DeQueue()
{
    int iDelData;
    node *pTemp = NULL;

    if(IsQueueEmpty())
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }

    pTemp = pQueue;

    iDelData = pTemp->iData;

    pQueue = pTemp->pNext;

    pTemp->pNext = NULL;

    delete pTemp;

    return iDelData;
}

int Queue::IsQueueFull()
{
    if(CountNodes() == MAX)
        return 1;

    return 0;
}

int Queue :: IsQueueEmpty()
{
    if(pQueue == NULL)
        return -1;

    return 0;
}


void Queue::DeleteAll()
{
    node *pTemp = NULL;

    while(pQueue != NULL)
    {
        pTemp = pQueue;

        pQueue = pQueue->pNext;

        delete pTemp;
    }
}

int Queue::CountNodes()
{
    int iCount = 0;
    node *pTemp = pQueue;

    while(pTemp != NULL)
    {
        iCount++;

        pTemp = pTemp->pNext;
    }

    return iCount;
}

void Queue::Display()
{
    node *pTemp = pQueue;

    if(pTemp == NULL)
    {
        cout << "Queue is Empty" << endl;
        return;
    }

    while(pTemp != NULL)
    {
        cout << "|" << pTemp->iData << "|->";

        pTemp = pTemp->pNext;
    }

    cout << endl;
}


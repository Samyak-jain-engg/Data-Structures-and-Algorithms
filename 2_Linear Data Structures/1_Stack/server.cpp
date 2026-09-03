
#include<iostream>
#include"server.h"
#define MAX 20

using std :: cout;
using std :: endl;

stack :: stack()
{
    iData = 0;
    pNext = NULL;
}

stack ::~stack()
{
    iData = 0;
    pNext = NULL;
}

list ::list()
{
    pFirst = NULL;
}

list :: ~list()
{
    if(pFirst != NULL)
        DeleteAll();
}
void list ::Push(int iNo)
{
    stack *pNewstack = new stack;

    if(IsFull())
    {
        cout<<"Stack is OverFlow";
        return ;
    }

    
    pNewstack->iData = iNo;

    if(NULL == pFirst)
    {
        pNewstack->pNext =NULL;
        pFirst = pNewstack;
        return;
    }
    
    pNewstack->pNext = pFirst;
    pFirst = pNewstack;

}
int list::Pop()
{
    int iDelData;
    stack *pTemp = NULL;

    if(IsEmpty())
    {
        cout << "Stack is Empty" << endl;
        return -1;
    }

    pTemp = pFirst;

    iDelData = pTemp->iData;

    pFirst = pTemp->pNext;

    pTemp->pNext = NULL;

    delete pTemp;

    return iDelData;
}

int list::IsFull()
{
    if(CountNodes() == MAX)
        return 1;

    return 0;
}

int list ::IsEmpty()
{
    if(NULL == pFirst)
        return 1;

    return 0;
}

int list::CountNodes()
{
    int iCount =0;
    stack *pTemp = pFirst;


    while(pTemp != NULL)
    {
        iCount ++;
        pTemp = pTemp->pNext;
    }
    return iCount;
}

void list::DeleteAll()
{
    stack *pTemp = NULL;

    while(pFirst != NULL)
    {
        pTemp = pFirst;
        pFirst = pFirst->pNext;
        delete pTemp;
    }

}

void list::Display()
{
    stack *pTemp = pFirst;

    if(NULL == pTemp)
        return;

    while(pTemp != NULL)
    {
        cout<< "|" << pTemp->iData << "| -> ";
        pTemp = pTemp->pNext;
    }    

    cout<<endl;
}
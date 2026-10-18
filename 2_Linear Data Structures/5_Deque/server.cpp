#include<iostream>
#include"server.h"

using std::cout;
using  std::endl;

Deque ::Deque()
{
    iRear = 0;
    iFront = 0;
    iCount = 0;
}

bool Deque::Isfull()
{
    return iCount == MAX;
}

bool Deque ::IsEmpty()
{
    return iCount ==0;
}

void Deque::InsertFrist(int iNo)
{
    if(Isfull())
        {
            cout<<"Deque is full"<<endl;
            return;
        }

    if(iCount == 0)
        {
            iRear = 0;
            iFront = 0;
        }

    else
        iFront = (iFront -1 + MAX)%MAX;

    arr[iFront] = iNo;
    iCount++;
}

void Deque::InsertLast(int iNo)
{
    if(Isfull())
        {
            cout<<"Deque is Full";
            return;
        }

    if(IsEmpty())
        {
            iFront = 0;
            iRear = 0;
        }

    else
        iRear = (iRear + 1)%MAX;

    arr[iRear] = iNo;
    iCount++;
}

void Deque::DeleteFrist()
{
    if(IsEmpty())
        {
            cout<<"Deque is Empty"<<endl;
            return;
        }

    cout<<"Remove Element is "<<arr[iFront]<<endl;

    if(iCount == 1)
        {
            iRear = 0;
            iFront = 0;
        }
    else
        iFront = (iFront + 1)%MAX;

    iCount--;
}

void Deque ::DeleteLast()
{
    
    if(IsEmpty())
        {
            cout<<"Deque is Empty"<<endl;
            return;
        }

    cout<<"Remove Element is "<<arr[iRear]<<endl;

    if(iCount == 1)
        {
            iRear = -1;
            iFront = 0;
        }
    else
        iRear = (iRear -1 + MAX)%MAX;

    iCount--;
}

void Deque ::Display()
{
    if(IsEmpty())
        {
            cout<<"Deque is Empty"<<endl;
            return;
        }
    
    int index = iFront;

    for(int iCounter =0 ;iCounter<iCount;iCounter++)
    {
        cout<<arr[index]<<" ";
        index = (index + 1)%MAX;
    }
    cout<<endl;


}
#include<iostream>
#include"Server.h"

using std::endl;
using std::cout;

int main(void)
{
    int iAns;
    int iCount;
    list list1;
    list list2;

    list1.InsertFirst(10);
    list1.InsertFirst(20);
    list1.InsertFirst(30);
    list1.InsertFirst(40);
    list1.InsertFirst(50);

    list1.Display();

    list1.InsertLast(60);
    list1.InsertLast(70);
    list1.InsertLast(60);

    list1.Display();

    iAns = list1.DeleteFirst();
    cout<<iAns<<endl;
    
    iAns = list1.DeleteLast();
    cout<<iAns<<endl;

    list1.Display();

    iAns = list1.DeleteAtPosition(4);
    cout<<iAns<<endl;

    list1.InsertAtPosition(40,4);

    list1.Display();


   iCount = list1.CountNode();
    cout<<endl<<iCount;

    iCount = list1.SearchFirstOccurrence(60);
    cout<<endl<<iCount<<endl;

    iCount = list1.SearchLastOccurrence(60);
    cout<<endl<<iCount;

    iCount = list1.SearchAllOccurrence(60);
    cout<<endl<<iCount<<endl;

    list2.InsertLast(100);
    list2.InsertLast(200);
    list2.InsertLast(300);

    list2.Display();

    list1.ConcatAtPosition(list2, 5);

    list1.Display();

    list1.ConcatList(list2);

    list1.Display();

    return 0;
}

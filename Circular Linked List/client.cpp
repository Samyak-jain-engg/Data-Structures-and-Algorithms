#include<iostream>
#include"server.h"

using std::cout;
using std::endl;

int main(void)
{
    
    int iDel;
    int iCount;

    list list1;
    list list2;


    list1.InsertFirst(10);
    list1.InsertFirst(20);
    list1.InsertFirst(30);
    list1.InsertFirst(40);

    list1.InsertLast(60);
    list1.InsertLast(70);

    list1.Display();

     iDel = list1.DeleteFirst();
    cout<<endl<<iDel;

    iDel =list1.DeleteLast();
    cout<<endl<<iDel<<endl;

    list1.Display();

    iCount = list1.CountNodes();

    cout<<endl<<iCount;

    iCount = list1.SearchFirstOccurrence(60);
    cout<<endl<<iCount<<endl;

    list1.Display();
    
    list1.PhysicalReverse();

    list1.Display();

    list1.ReverseDisplay();

    list1.InsertAtPosition(70,5);

    list1.Display();

    list1.DeleteAtPosition(4);

    list1.Display();


    list2.InsertLast(100);
    list2.InsertLast(200);
    list2.InsertLast(300);

    list2.Display();

    list1.ConcatAtPosition(list2, 3);

    list1.Display();

    list1.ConcatList(list2);

   list1.Display();

   cout<< "No Error";

   return 0;

}
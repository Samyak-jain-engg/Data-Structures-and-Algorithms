class list;

class node
{
    int iData;
    node *pNext;
  
    public:
        node();
        ~node();

    friend class list;    
};

class list
{
    node *pFirst;
    node *pTail;

    public:
        list();
        ~list();

        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPosition(int,int);

        int DeleteFirst();
        int DeleteLast();
        int DeleteAtPosition(int);

        int CountNodes();
        int SearchFirstOccurrence(int);
        int SearchLastOccurrence(int);
        int SearchAllOccurrences(int);

        void ConcatList(list &obj);
        void ConcatAtPosition(list &obj, int iPos);

        void PhysicalReverse();
        void ReverseDisplay();
        void DeleteAll();
        void Display();


};

class list;

class node
{
    node *pPrev;
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

public:
    list();
    ~list();

    void InsertLast(int);
    void InsertFirst(int);
    void DeleteAll();
    void Display();

    int DeleteFirst();
    int DeleteLast();
    int CountNode();
    int SearchFirstOccurrence(int);
    int SearchLastOccurrence(int);
    int SearchAllOccurrence(int);

    void InsertAtPosition(int, int);
    int DeleteAtPosition(int);

    void ConcatList(list &obj);
    void ConcatAtPosition(list &obj, int iPos);

    void ReverseDisplay();
    void PhysicalReverse();
};


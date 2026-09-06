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

    public:
        list();
        ~list();

    void InsertLast(int);
    void InsertFrist(int);
    void DeleteAll();
    void Display();
    int DeleteFirst();
    int DeleteLast();
    int CountNode();
    int SearchFristOccurance(int);
    int SearchLastOccurance(int);
    int SearchAllOccurance(int);
    void InsertAtPosition(int ,int);
    void DeleteAtPosition(int);
    void ConcatList(list &obj);
    void ConcatAtPosition(list &obj, int iPos);
    void ReverseDisplay();
    void PhysicalReverse();



};
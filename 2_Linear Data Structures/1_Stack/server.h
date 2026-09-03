class stack{
    int iData ;
     stack *pNext;

    public:
        stack();
        ~stack();

    friend class list;
};

class list {

    stack *pFirst;

    public:
        list();
        ~list();

        void Push(int);
        int Pop();
        int IsFull();
        int IsEmpty();
        void Display();
        void DeleteAll();
        int CountNodes();

};
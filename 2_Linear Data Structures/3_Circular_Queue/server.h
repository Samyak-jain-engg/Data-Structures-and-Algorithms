class node
{
    int iData;
    node *pNext;

    public:
        node();
        ~node();

        friend class Queue;
};

class Queue
{
    node *pFront;
    node *pRear;

    public:
    Queue();
    ~Queue();

    void EnQueue(int);
    int DeQueue();

    bool IsFuLL();
    bool IsEmpty();

    void Display();
    void DeleteAll();

    int CountNode();
};

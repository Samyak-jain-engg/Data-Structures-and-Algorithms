class Queue ;

class node
{
    int iData;
    node *pNext ;

    public:
        node();
        ~node();

    friend class Queue;
};

class Queue
{
    node *pQueue;

    public:
        Queue();
        ~Queue();

    void EnQueue(int);
    int DeQueue();
    int IsQueueFull();
    int IsQueueEmpty();
    void Display();
    void DeleteAll();
    int CountNodes();

};
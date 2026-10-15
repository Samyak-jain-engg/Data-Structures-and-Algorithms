#define MAX 10

class priorityQueue{
    int arr[MAX];
    int iCount;

    public:
        priorityQueue();
        bool IsFull();
        bool IsEmpty();

        void Enqueue(int);
        void Dequeue();
        void Display();
};
#define MAX 10

class Deque
{
    int iCount;
    int  arr[MAX];
    int iRear;
    int iFront;

    public:
        Deque();
        bool Isfull();
        bool IsEmpty();
        
        void InsertFrist(int);
        void InsertLast(int);
        void DeleteFrist();
        void DeleteLast();
        void Display();


};
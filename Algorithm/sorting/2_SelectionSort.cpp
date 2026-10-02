#include<iostream>

using std ::cout;
using std ::cin;
using std ::endl;
using std::swap;

void Selectionsort(int arr[],int isize)
{
    for(int iCounter = 0; iCounter < isize-1; ++iCounter)
    {
        int iMinIndex = iCounter;

        for(int iCounter2 = iCounter +1; iCounter2 < isize; ++iCounter2)
        {
            if(arr[iCounter2] < arr[iCounter])
                iMinIndex = iCounter2;
        }

        if(iMinIndex != iCounter)
            swap(arr[iCounter],arr[iMinIndex]);

    }

}

void PrintArray(const int arr[],int isize)
{
    for(int iCounter = 0; iCounter < isize; ++iCounter)
        cout<<arr[iCounter]<<" ";
    
    cout<<endl;

}


int main(void)
{
    int arr[100];
    int iSize ,iElement;

    cout<<"Enter the size of array"<<endl;
    cin>>iSize;

    cout<<"Enter the Element"<<endl;

    for(int iCounter = 0; iCounter < iSize; iCounter++)
        cin>>arr[iCounter];

    cout<<"Orignal Array"<<endl;
    PrintArray(arr,iSize);

    Selectionsort(arr,iSize);

    cout<<"Sorted Array"<<endl;
    PrintArray(arr,iSize);

    return 0;
}
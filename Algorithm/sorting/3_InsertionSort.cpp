#include<iostream>

using std::cout;
using std::cin;
using std::endl;
using std::swap;

void PrintArray(const int arr[], int iSize)
{
    for(int iCounter = 0; iCounter <iSize; iCounter++)
        cout<<arr[iCounter]<<" ";

    cout<<endl;
}

void InsertionSort(int arr[],int iSize)
{
    for(int iCounter = 1;iCounter<iSize;iCounter++)
    {
        for(int iCounter2 =iCounter;iCounter2 > 0;iCounter2--)
        {
            if(arr[iCounter2] < arr[iCounter2-1])
                swap(arr[iCounter2],arr[iCounter2-1]);

                else
                    break;

        }
    }
}



int main(void)
{
    int iSize,iElement,iCounter;
    int arr[100];

    cout<<"Enter the size of array"<<endl;
    cin>>iSize;

    cout<<"Enter the element of array"<<endl;
    for(iCounter = 0; iCounter < iSize; iCounter++)
        cin>>arr[iCounter];

    cout<<"Unsorted  Array"<<endl;
    PrintArray(arr,iSize);

    InsertionSort(arr,iSize);

    cout<<"Sorted Array"<<endl;
    PrintArray(arr,iSize);

    return 0;

}


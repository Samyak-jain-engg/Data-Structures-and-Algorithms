#include<iostream>

using std::cout;
using std::cin;
using std::endl;
using std::swap;

void PrintArray(const int arr[], int iSize)
{
    for(int iCounter = 0; iCounter < iSize; ++iCounter)
        cout<<arr[iCounter]<<" ";
    
    cout<<endl;

}

void BubbleSort(int arr[],int iSize)
{
    bool swapped;

    for(int iCounter = iSize-2; iCounter >= 0; iCounter--)
    {
        swapped = false;

        for(int iCounter2 = 0; iCounter2 <= iCounter; iCounter2++)
        {
            if(arr[iCounter2] > arr[iCounter2 +1])
            {
                swapped = true;
                swap(arr[iCounter2],arr[iCounter2+1]);
            }

        }

        if (!swapped)
            break;
        
    }

}

int main(void)
{
    int arr[100];
    int iSize,iElement,iCounter;

    cout<<"Enter the size of Array"<<endl;
    cin>>iSize;

    cout<<"Enter the elements"<<endl;
    
    for(iCounter = 0; iCounter < iSize; ++iCounter)
        cin>>arr[iCounter];

    cout<<"Original array"<<endl;
    PrintArray(arr,iSize);

    BubbleSort(arr,iSize);

    cout<<"Sorted Array"<<endl;
    PrintArray(arr,iSize);

    return 0;
}



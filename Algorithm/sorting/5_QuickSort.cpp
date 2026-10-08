#include<iostream>

using std ::cout;
using std ::cin;
using std ::endl;
using std ::swap;

void printArray(int arr[],int iSize)
{
    for(int iCounter = 0; iCounter < iSize; iCounter++)
        cout<<arr[iCounter]<<" ";

    cout<<endl;
}

int partition(int arr[],int iStart,int iEnd)
{
    int ipos = iStart;

    for(int iCounter = iStart ; iCounter < iEnd;iCounter++)
    {
        if(arr[iCounter]<= arr[iEnd])
        {
            swap(arr[iCounter],arr[ipos]);
            ipos++;
        }
    }

    swap(arr[ipos], arr[iEnd]);
    return ipos;


}

void QuickSort(int arr[],int iStart, int iEnd)
{
    if(iStart >= iEnd)
        return;

    int iPivot = partition(arr,iStart,iEnd);

    QuickSort(arr,iStart,iPivot-1);         //Left side

    QuickSort(arr,iPivot,iEnd);              //Right side


}

int main(void)
{
    int iCounter,iElement,iSize,iEnd,iStart;

    int arr[100];
    cout<<"Enter the Size of array"<<endl;
    cin>>iSize;

    for(iCounter = 0 ; iCounter < iSize; iCounter++)
        cin>>arr[iCounter];

    
    cout<<"Old Array"<<endl;
    printArray(arr,iSize);

    iEnd = iSize-1;
    iStart = 0;

    QuickSort(arr,iStart,iEnd);

    cout<<"New Array"<<endl;
    printArray(arr,iSize);


}


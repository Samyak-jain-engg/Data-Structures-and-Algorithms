#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

void PrintArray(const int arr[],int iSize)
{
    for(int iCounter = 0; iCounter < iSize; iCounter++)
        cout<<arr[iCounter]<<endl;

    cout<<endl;
}
void merge(int arr[], int iStart, int iMid, int iEnd);

void MergeSort(int arr[],int iStart,int iEnd)
{
      if(iStart >= iEnd)
        return;
    int iMid = (iStart + iEnd)/2;

    MergeSort(arr ,iStart, iMid);

    MergeSort(arr ,iMid + 1, iEnd);

    merge(arr,iStart,iMid,iEnd);

}

void merge(int arr[],int iStart ,int iMid,int iEnd)
{
    int iRight = iMid + 1;
    int iLeft = iStart;

    int index = 0;

    vector<int>temp(iEnd-iStart+1);

    while(iRight <= iEnd && iLeft <= iMid)
    {
        if(arr[iLeft]<= arr[iRight])
        {
            temp[index] = arr[iLeft];
            index++,iLeft++;

        }
        else
        {
            temp[index] = arr[iRight];
            index++,iRight++;
        }

    }
    while(iLeft  <= iMid)
    {
        temp[index] = arr[iLeft];
        index++,iLeft++;
    }

    while(iRight <= iEnd)
    {
        temp[index] = arr[iRight];
        index++ , iRight++;
    }

    index = 0;
    while (iStart <=iEnd)
    {
        arr[iStart]=temp[index];
        iStart++,index++;
    }
    
}



int main(void)
{
    int iElement,iSize,iCounter ,iStart ,iEnd;
    int arr[100];

    cout<<"Enter the Size of array";
    cin>>iSize;

    cout<<"Enter the Elements"<<endl;

    for(iCounter = 0; iCounter <iSize; iCounter++)
        cin>>arr[iCounter];

    cout<<"Old array"<<endl;
    PrintArray(arr,iSize);

    iEnd = iSize-1;
    iStart = 0;
    MergeSort(arr,iStart,iEnd);

    cout<<"New array"<<endl;
    PrintArray(arr,iSize);

    return 0;

}
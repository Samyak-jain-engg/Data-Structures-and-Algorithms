
//Find Largest Element in Array Using Recursion

#include<iostream>

using std ::cout;
using std ::cin;
using std ::endl;

int FindMax(int arr[],int iSize,int iIndex)
{

    if(iIndex == iSize-1)
        return arr[iIndex];

    int iMax =  FindMax(arr,iSize,iIndex + 1);

    if(arr[iIndex] > iMax)
        return arr[iIndex];

    return iMax;

}

int main(void)
{
    int iCounter,iSize,iRet,iIndex;
    int arr[100];

    cout<<"Enter The Size of array"<<endl;
    cin>>iSize;

    iIndex = 0;

    cout<<"Enter the Element "<<endl;
    for(iCounter = 0; iCounter < iSize; iCounter++)
        cin>>arr[iCounter];

    iRet = FindMax(arr,iSize,iIndex);


    cout<<"Largest element is "<<iRet<<endl;

    return 0;

}
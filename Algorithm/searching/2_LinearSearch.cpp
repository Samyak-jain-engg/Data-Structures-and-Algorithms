#include<iostream>

using std ::cout;
using std ::cin;
using std ::endl;

int LinearSearch(int arr[],int iNumber,int iKey )
{
    for(int iCounter = 0; iCounter < iNumber; iCounter++)
        if(arr[iCounter]==iKey)
            return iCounter;

    return -1;

}
int main(void)
{
    int arr[100];
    int iNumber;
    int iElements;
    int iKey;

    cout<<"Enter the size of Array "<<endl;
    cin>>iNumber;

    cout<<"Enter the Elements"<<endl;

    for(int iCounter = 0; iCounter <iNumber; iCounter++)
        cin>>arr[iCounter];

    cout<<"Enter the Key"<<endl;
    cin>>iKey;

    int iAns=LinearSearch(arr,iNumber,iKey);

    if(iAns == -1)
        cout<<"Element is not present";

    else
        cout<<"Element is present"<<iAns;

    return 0;

}
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int BinarySearch(int arr[],int n,int Key)
{
    int start = 0 ,end = n-1,mid;
    
    while(start <= end)
    {
        mid = (start+end)/2;

        if(arr[mid]==Key)
            return mid;

        else if(arr[mid]<Key)
            start = mid + 1;

        else
            end = mid - 1;
    }
}

int main(void)
{
    int arr[100];
    int n;
    int Key;

    cout<<"Enter the no of Array :- ";
    cin>>n;

    cout<<"Enter the Elements"<<endl;

    for(int i = 0; i < n; i++)
        cin>>arr[i];

    cout<<"Enter the Key";
    cin>>Key;

    cout<<BinarySearch(arr,n,Key)<<endl;
    

}
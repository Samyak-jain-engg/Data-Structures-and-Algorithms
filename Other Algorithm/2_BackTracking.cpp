
//Given an Array{1,2,3} Generate every possible subset

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void GenerateSubset(int arr[], int iSize, int iIndex,int iSubset[],int iSubsetSize)
{
    if(iIndex == iSize)
    {
        cout<<"{";

        for(int iCounter = 0; iCounter <iSubsetSize; iCounter++)
            cout<<iSubset[iCounter]<<" ";

        cout<<"}"<<endl;

        return ;
    }

    //Exclude the current element
    GenerateSubset( arr,iSize,iIndex + 1,iSubset,iSubsetSize);

    //Include the current element 

    iSubset[iSubsetSize] = arr[iIndex];

    GenerateSubset( arr,  iSize,  iIndex + 1, iSubset, iSubsetSize +1);



}


int main(void)
{
    int arr[3] = {1,2,3};

    int iSubset[3];
    
    GenerateSubset(arr,3,0,iSubset,0);

    return 0;


}
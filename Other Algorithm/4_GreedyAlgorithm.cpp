//Activity Selection Problem
//Suppose you have 6 activities, each with a start time and finish time. You can attend only one activity at a time. 
//Your goal is to select the maximum number of non-overlapping activities.


#include<iostream>

using  std :: cout;
using  std :: endl;

int main(void)
{
    int start[6] = {1,2,4,6,5,8};
    int finish[6] = {3,5,6,7,8,9};

    int iIndex;
    int iCount= 1;
    int iLastFinish = finish[0];

    cout<<"Selected activity :A1"<<endl;

    for(iIndex = 1; iIndex < 6; iIndex++)
    {
        if(start[iIndex] >= iLastFinish)
        {
            cout<<"Selected Activity :A"<<iIndex+1<<endl;

            iLastFinish = finish[iIndex];
            iCount++;
        }

    }

    cout<<"Total activity "<<iCount<<endl;
    
    return 0 ;
}



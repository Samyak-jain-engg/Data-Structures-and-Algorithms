//Let's calculate fibonacci(5) using DP
//Memoization — Top-Down


#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;


int Fibon(int iNo,vector<int>&Dp)
{
    //Base case

    if(iNo <= 1)
        return iNo;

    //Already calculate 

    if(Dp[iNo] != -1)
        return Dp[iNo];

    return Dp[iNo] = Fibon(iNo -1,Dp) + Fibon(iNo-2,Dp);

}

int main(void)
{
    int iNo,iRet;

    cout<<"Enter the Number"<<endl;
    cin>>iNo;

    if(!cin || iNo < 0)
    {
        cout << "Enter a non-negative number" << endl;
        return 1;
    }   

    vector <int>Dp(iNo+1, -1);
    
    iRet = Fibon(iNo,Dp);

    cout<<"Fibonacci No is :-"<<iRet;
}

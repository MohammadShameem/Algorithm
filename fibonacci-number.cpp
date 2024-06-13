#include<iostream>
using namespace std;
//0 1 1 2 3 5
//n = (n-1)+ (n-2)
//dp

int fib(int n, int* ans){
    //base case
    if(n<=1){
        return n;
    }
    //memorization
    if(ans[n] != -1){
        return ans[n];
    }
    ans[n] = fib(n-1,ans) + fib(n-2,ans);
    return  ans[n];
}

int main(){
    int n = 100;
    int* ans = new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i] = -1;
    }
    cout<< fib(n,ans);
    return 0;
}

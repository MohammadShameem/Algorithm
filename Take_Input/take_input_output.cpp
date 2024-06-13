// How to take input from file and write the output into file for character, string, array


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(){
    //file input and output
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    ll n,sum=0;

    char ch;
    //Take a character as input
    cin>>ch;

    string str;
    //take a string line as input
    getline(cin>>ws,str);

    //take an integer as input
    cin>>n;
   
    //take an array as input
    long long arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


    for(int i=0;i<n;i++){
        sum = sum + arr[i];
    }


    int array[3][3],userInput;//row and col
    for (int y =0; y<3; y++) //row
    {
        for (int x =0; x<3; x++) //col
        {
            cin >> userInput;
            array[x][y]= userInput;
        }
    }
    
    //write output
    cout<<ch<<endl;
    cout<<str<<endl;
    cout<<sum<<endl;


    return 0;
}
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    vector<string> subSetString; 
    string mainString = "123"; //2^(n-1)+2

    for(int i=0;i<=mainString.length();i++){ 
        for(int len=1;len<=mainString.length()-i;len++){
            string subString = mainString.substr(i,len);
            subSetString.push_back(subString);
        }
    }

    for(auto s : subSetString){
        cout<<s<<endl;
    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;

void func(string str, int i, int k, string res){
    if(i == str.length()){
        if(res.length() == k){
            cout<<res<<endl;
            // return;
        }
        return;
    }
    char ch = str[i];
    func(str, i+1, k, res+ch);
    func(str, i+1, k, res);
}

int main(){
    string str;
    int k;
    cin>>str>>k;
    set<char>s;
    for(auto i:str){
        s.insert(i);
    }
    string temp;
    for(auto ch : s){
        temp += ch;
    }
    // cout<<temp;
    func(temp, 0, k, "");
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void func(string str, int cs, int k, int lc, string res){
    if(cs > k){
        // if(res.length() == k){
            cout<<res<<endl;
            // return;
        // }
        return;
    }
    for(int i=lc+1;i<str.length();i++){
        char ch = str[i];
        func(str, cs+1, k, i, res+ch);
    }
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
    func(temp, 1, k,-1, "");
    return 0;
}
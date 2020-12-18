#include<bits/stdc++.h>
using namespace std;

int minRemoval(string str, int n){
    stack<char>s;
    for(int i=0;i<n;i++){
        if(str[i]=='('){
            s.push(str[i]);
        } else if(str[i]==')'){
            if(s.empty()){
                s.push(str[i]);
            }
            else if(s.top()=='('){
                s.pop();
            } else if(s.top()==')'){
                s.push(str[i]);
            }
        }
    }
    return s.size();
}

void func(string str, int minar, set<string>&st){
    if(minar==0){
        int minrnow = minRemoval(str, str.length());
        if(minrnow==0){
            if(st.count(str)==0){
                st.insert(str);
                cout<<"Size: "<<st.size()<<endl;
                cout<<str<<endl;
            }
        }

        return;
    }
    for(int i=0;i<str.length();i++){
        string left = str.substr(0,i);
        string right = str.substr(i+1);
        func(left+right, minar-1, st);
    }
}

int main(){
    string str;
    cin>>str;
    set<string>st;
    int minR = minRemoval(str, str.length());
    cout<<minR<<endl;
    func(str, minR, st);
    cout<<st.size();
    return 0;
}
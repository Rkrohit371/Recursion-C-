#include<bits/stdc++.h>
using namespace std;

void func(string word, string pattern, map<char, string>mp, string op){
    if(pattern.length()==0){
        if(word.length()==0){
            set<char>alreadyprinted;
            for(int i=0;i<op.length();i++){
                if(alreadyprinted.count(op[i])==false){
                    cout<<op[i]<<"->"<<mp[op[i]]<<",";
                    alreadyprinted.insert(op[i]);
                }
            }
            cout<<endl;
        }
        return;
    }

    char ch = pattern[0];
    string rop = pattern.substr(1);
    if(mp.count(ch)){
        string pmapping = mp[ch];
        if(word.length() >= pmapping.length()){
            string left = word.substr(0,pmapping.length());
            string right = word.substr(pmapping.length());
            if(pmapping==left){
                func(right, rop, mp, op);
            }
        }
    } else {
        for(int i=0;i<word.length();i++){
            string left = word.substr(0,i+1);
            string right = word.substr(i+1);
            mp[ch] = left;
            func(right, rop, mp, op);
            mp.erase(ch);
        }
    }
}

int main(){
    string word,pattern;
    cin>>word>>pattern;

    map<char, string>mp;
    func(word, pattern, mp, pattern);

    return 0;
}
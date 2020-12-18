#include<bits/stdc++.h>
using namespace std;

void func(int cc, string str, vector<char>&spots, map<char, int>&mp){
    if(cc == str.length()){
        for(int i=0;i<spots.size();i++){
            cout<<spots[i];
        }
        cout<<endl;
        return;
    }

    char ch = str[cc];
    int lo = mp[ch];
    for(int i=lo+1;i<spots.size();i++){
        if(spots[i] == '1'){
            spots[i] = ch;
            mp[ch] = i;
            func(cc+1, str, spots, mp);
            mp[ch] = -1;
            spots[i] = '1';
        }
    }
}

int main(){
    string str;
    cin>>str;
    map<char, int>vis;
    for(auto ch : str){
        vis[ch] = -1;
    }
    vector<char>spots(str.length(), '1');
    func(0, str, spots, vis);

    return 0;
}
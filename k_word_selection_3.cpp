#include<bits/stdc++.h>
using namespace std;

void func(int cc, string str, int ssf, int k, vector<char>&spots){
    if(cc == str.length()){
        if(ssf == k){
            for(int i=0;i<spots.size();i++){
                cout<<spots[i];
            }
        cout<<endl;
        }
        return;
    }
    char ch = str[cc];
    for(int i=0;i<spots.size();i++){
        if(spots[i]=='1'){
            spots[i] = ch;
            func(cc+1, str, ssf+1, k, spots);
            spots[i] = '1';
        }
    }
    func(cc+1, str, ssf, k, spots);
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
    vector<char>spots(k, '1');
    // memset(spots, -1, sizeof)
    func(0, temp, 0, k, spots);
    return 0;
}
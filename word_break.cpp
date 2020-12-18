#include<bits/stdc++.h>
using namespace std;

void func(string word, set<string>st, string result){
    if(word.length()==0){
        cout<<result<<endl;
        return;
    }

    for(int i=0;i<word.length();i++){
        string left = word.substr(0,i+1);
        if(st.count(left)){
            string right = word.substr(i+1);
            func(right, st, result+left +" ");
        }
    }
}

int main(){
    string sent, word;
    getline(cin, sent);
    cin>>word;
    set<string>st;
    string text;
    for(auto w : sent){
        if(w==' '){
            // cout<<text<<endl;
            st.insert(text);
            text = "";
        } else {
            text += w;
        }
    }
    st.insert(text);
    for(auto w : st){
        cout<<w<<" ";
    }
    cout<<endl;
    func(word, st, "");
    return 0;
}
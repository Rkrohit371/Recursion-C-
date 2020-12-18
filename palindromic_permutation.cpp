#include<bits/stdc++.h>
using namespace std;

void func(int cs, int len_string, map<char,int>mp, char oddc, string ans){
    if(cs > len_string){
        // cout<<ans<<endl;
        string res = ans;
        reverse(res.begin(), res.end());
        cout<<ans+oddc+res<<endl;
        return;
    }
    for(char ch = 'a';ch <= 'z';ch++){
        // cout<<ch<<" "<<mp[ch]<<endl;
        if(mp[ch] > 0){
            int freq = mp[ch];
            freq = freq -1;
            mp[ch] = freq;
            func(cs+1, len_string, mp, oddc, ans + (ch));
            mp[ch] = freq+1;
        }
    }
}

int main(){
    string str;
    cin>>str;
    map<char, int>mp;
    for(int i=0;i<str.length();i++){
        mp[str[i]]++;
    }
    char odd;
    int odds = 0;
    int len=0;
    for(char ch = 'a';ch <= 'z';ch++){
        int freq = mp[ch];
        if(freq%2==1){
            odd = ch;
            odds++;
        }
        mp[ch] = freq/2;
        len += freq/2;
    }
    string result;
    
    func(1,len,mp,odd,result);

    return 0;
}
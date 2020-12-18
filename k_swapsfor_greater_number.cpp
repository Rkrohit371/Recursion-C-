#include<bits/stdc++.h>
using namespace std;
string result;

void func(string s, int k){
    if(result < s){
        result = s;
    }
    if(k == 0){
        return;
    }

    for(int i=0;i<s.length()-1;i++){
        for(int j=i+1;j<s.length();j++){
            if(s[j] > s[i]){
                string swapped = s;
                swap(swapped[i], swapped[j]);
                func(swapped, k-1);
            }
        }
    }

}

int main(){
    string n;
    cin>>n;
    int k;
    result = n;
    cin>>k;
    func(n, k);
    cout<<result;
    return 0;
}
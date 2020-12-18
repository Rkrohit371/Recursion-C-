#include<bits/stdc++.h>
using namespace std;

bool isPal(string str){
    int i=0,j=str.length()-1;
    while(i<j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void func(string str, string ssf){
    if(str.length()==0){
        cout<<ssf<<endl;
        return;
    }
    for(int i=0;i<str.length();i++){
        string pal = str.substr(0,i+1);
        str = str.substr(i+1);
        // cout<<str<<" "<<pal<<endl;
        if(isPal(pal)){
            func(str, ssf+"("+pal+")");
        }
    }
}

int main(){
    string str;
    cin>>str;
    func(str, ""); 
    return 0;  
}
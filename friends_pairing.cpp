#include<bits/stdc++.h>
using namespace std;
int counter=1;
void func(int i, int n, bool used[], string asf){
    if(i>n){
        cout<<counter<<"->"<<asf<<endl;
        counter++;
        return;
    }
    if(used[i]==true){
        func(i+1,n,used, asf);
    } else {
        used[i] = true;
        func(i+1, n, used, asf+"("+to_string(i)+")");
        for(int j=i+1;j<=n;j++){
            if(used[j]==false){
                used[j] = true;
                func(i+1, n, used, asf+"("+to_string(i)+","+to_string(j)+")");
                used[j]=false;
            }
        }
        used[i] = false;
    }
}

int main(){
    int n;
    cin>>n;
    bool used[n+1];
    memset(used, false, sizeof(used));
    func(1, n, used, "");
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

bool safe(vector<vector<char>>&arr, int i, int j, int dcol){
    for(int row=i-1, col=j;row >=0;row--){
        if(arr[row][col]=='Q'){
            return false;
        }
    }
    for(int row=i-1, col=j-1;row >=0 && col >= 0;row--, col--){
        if(arr[row][col]=='Q'){
            return false;
        }
    }
    for(int row=i-1, col=j+1;row >=0 && col <= dcol;row--, col++){
        if(arr[row][col]=='Q'){
            return false;
        }
    }
    return true;
}

void func(vector<vector<char>>&arr, int sr, int dr, int dc){
    if(sr == dr+1){
        for(int i=0;i<=dr;i++){
            for(int j=0;j<=dc;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<=dc;i++){
        if(safe(arr, sr, i, dc)==true){
            arr[sr][i] = 'Q';
            func(arr, sr+1, dr, dc);
            arr[sr][i] = '0';
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<char>>arr(n, vector<char>(n,'0'));
    func(arr, 0, n-1, n-1);

}
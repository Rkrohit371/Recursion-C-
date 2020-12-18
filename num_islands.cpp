#include<bits/stdc++.h>
using namespace std;
int n,m;
int row[4] = {1, -1, 0, 0};
int col[4] = {0, 0, 1, -1};

bool safe(vector<vector<int>>&arr, vector<vector<int>>&vis, int i, int j){
        return (i>=0) && (i <= n-1) && (j >=0) && (j <= m-1) && (vis[i][j]==0) && (arr[i][j]==1); 
}

void bfs(vector<vector<int>>&arr, vector<vector<int>>&vis, int i, int j){

    vis[i][j] = 1;
    queue<pair<int, int>>q;
    q.push({i,j});
    while(!q.empty()){
        int first = q.front().first;
        int second = q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            if(safe(arr, vis, row[k]+first, col[k]+second)){
                vis[first+row[k]][second+col[k]] = 1;
                q.push({first+row[k], second+col[k]});
            }
        }
    }
}

void dfs(vector<vector<int>>&arr, vector<vector<int>>&vis, int i, int j){
    if(i < 0 || i > n-1 || j < 0 || j > m-1 || vis[i][j] == 1 || arr[i][j] == 0){
        return;
    }
    vis[i][j] = 1;
    dfs(arr, vis, i+1, j);
    dfs(arr, vis, i-1, j);
    dfs(arr, vis, i, j+1);
    dfs(arr, vis, i, j-1);
}

int main(){
    n=4,m=5;
    vector<vector<int>>arr(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int dcount=0;
    vector<vector<int>>vis(n, vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0 && arr[i][j]==1){
                dfs(arr, vis, i,j);
                dcount++;
            }
        }
    }
    cout<<dcount;
    int bcount=0;
    vector<vector<int>>bvis(n, vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(bvis[i][j]==0 && arr[i][j]==1){
                dfs(arr, bvis, i,j);
                bcount++;
            }
        }
    }
    cout<<endl<<bcount;
}
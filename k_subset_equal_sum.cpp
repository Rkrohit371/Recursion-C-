#include<bits/stdc++.h>
using namespace std;
int total=0;

void func(vector<int>&arr, int vidx, int n, int k, vector<int>&subsetsum, int sssf, vector<vector<int>>&ans){

    if(vidx==arr.size()){
        // cout<<"vidx"<<endl;
        if(sssf==k){
            bool flag=true;
            for(int i=0;i<subsetsum.size()-1;i++){
                if(subsetsum[i]!=subsetsum[i+1]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                for(auto nums : ans){
                    for(auto num: nums){
                        cout<<num<<" ";
                    }
                    cout<<endl;
                }
            }
        }
        return;
    }

    for(int i=0;i<ans.size();i++){
        // cout<<i<<endl;
        if(ans[i].size()>0){
            ans[i].push_back(arr[vidx]);
            subsetsum[i]+=arr[vidx];
            func(arr, vidx+1, n, k, subsetsum, sssf, ans);
            subsetsum[i]-=arr[vidx];
            ans[i].pop_back();
        } else {
            ans[i].push_back(arr[vidx]);
            subsetsum[i]+=arr[vidx];
            func(arr,vidx+1, n, k, subsetsum, sssf+1, ans);
            subsetsum[i] -= arr[vidx];
            ans[i].pop_back();
            break;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        total+=arr[i];
    }
    int k;
    cin>>k;
    vector<vector<int>>ans;
    for(int i=0;i<k;i++){
        vector<int>temp;
        ans.push_back(temp);
    }
    cout<<ans.size()<<" "<<ans[0].size()<<endl;
    vector<int>subsetsum(k);
    if(total%k==0 || k > n){
        func(arr,0, n, k, subsetsum, 0, ans);
    } else {
        cout<<"Not possible";
    }
    return 0;
}
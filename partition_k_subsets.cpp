#include<bits/stdc++.h>
using namespace std;
int counter=0;

void func(int i, int n, int k, int count, vector<vector<int>>&arr){
    if(i > n){
        if(count==k){
            counter++;
            cout<<counter<<"->";
            for(auto nums : arr){
                for(auto k : nums){
                    cout<<k<<" ";
                }
            }
            cout<<endl;
        }
        return;
    }
    for(int j=0;j<arr.size();j++){
        if(arr[j].size()>0){
            arr[j].push_back(i);
            func(i+1,n,k,count, arr);
            arr[j].pop_back();
        } else {
            arr[j].push_back(i);
            func(i+1,n,k,count+1, arr);
            arr[j].pop_back();
            break;
        }
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>>arr;
    for(int i=0;i<k;i++){
        vector<int>temp;
        arr.push_back(temp);
    }
    for(auto nums : arr){
        for(auto k : nums){
            cout<<k;
        }
        cout<<endl;
    }
    func(1,n,k,0,arr);
    return 0;
}
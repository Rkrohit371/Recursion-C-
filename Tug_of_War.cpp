#include<bits/stdc++.h>
using namespace std;
int minDiff = INT_MAX;
string ans;

void func(vector<int>&arr, int index, vector<int>&set1, vector<int>&set2, int s1, int s2){
    if(index==arr.size()){
        int total = abs(s1-s2);
        // cout<<"total: "<<total<<endl;
        if(minDiff > total){
            minDiff = total;
            ans = to_string(s1) + " " + to_string(s2);
        }
        return;
    }

    if(set1.size() < (arr.size()+1)/2){
        set1.push_back(arr[index]);
        func(arr, index+1, set1, set2, s1+arr[index], s2);
        set1.pop_back();
    }
    if(set2.size() < (arr.size()+1)/2){
        set2.push_back(arr[index]);
        func(arr, index+1, set1, set2, s1, s2+arr[index]);
        set2.pop_back();
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>set1,set2;
    int count;
    func(arr, 0, set1, set2, 0, 0);
    cout<<ans;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>&arr, vector<int>&temp, int left, int mid, int right){
    int i,j,k;
    int count=0;
    i = left;
    j = mid;
    k=left;
    while((i <= mid-1) && (j <= right)){
        if(arr[i] <= arr[j]){
            arr[k++] = arr[i++];
        } else {
            temp[k++] =  arr[j++];
            count += (mid-i);
        }
    }
    while(i <= mid-1){
        temp[k++] = arr[i++];
    }
    
    while(j <= right){
        temp[k++] = arr[j++];
    }
    for(i=left;i<=right;i++){
        arr[i] = temp[i];
    }
    cout<<"count: "<<count<<endl;
    return count;
}

int mergresort(vector<int>&arr, vector<int>&temp, int left, int right){
    int mid, count=0;
    if(right > left){
        mid = (right+left)/2;
        count = mergresort(arr, temp, left, mid);
        count += mergresort(arr, temp, mid+1, right);

        count += merge(arr, temp, left, mid+1, right);
    }
    cout<<"Count: "<<count<<endl;
    return count;
}

int inversions(vector<int>&arr, vector<int>&temp, int n){
    
    return mergresort(arr, temp, 0, n-1);
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>temp(n);
    cout<<inversions(arr, temp, n)<<endl;;
    
    for(auto i:temp){
        cout<<i<<" ";
    }
    return 0;
}
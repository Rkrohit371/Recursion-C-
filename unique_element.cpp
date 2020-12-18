#include<bits/stdc++.h>
using namespace std;

int func(int arr[], int n){
    if(arr[0] != arr[1]){
        return arr[0];
    }
    if(arr[n-1] != arr[n-2]){
        return arr[n-1];
    }
    int left=0;
    int right=n-1;
    int mid;
    while(left <= right){
        mid = left + (right-left)/2;
        if(arr[mid]!= arr[mid-1] && arr[mid] != arr[mid+1]){
            return arr[mid];
        }
        if((mid%2 == 0 && arr[mid]==arr[mid+1]) || (mid%2==1 && arr[mid]==arr[mid-1])){
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<func(arr, n);

    return 0;
}
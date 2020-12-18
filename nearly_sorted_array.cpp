#include<bits/stdc++.h>
using namespace std;

int func(int arr[], int n, int target){
    int mid;
    int i=0, j=n-1;
    while(i <= j){
        mid = i + (j-i)/2;
        if(arr[mid] == target){
            return mid;
        } else if(arr[i] <= arr[mid]){
            if(target <= arr[mid] && target >= arr[i]){
                j = mid-1;
            } else {
                i = mid+1;
            }
        } else {
            if(target >= arr[mid] && target <= arr[j]){
                i = mid+1;
            } else {
                j = mid-1;
            }
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
    int target;
    cin>>target;
    cout<<func(arr, n, target);

    return 0;
}
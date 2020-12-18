#include<bits/stdc++.h>
using namespace std;

void func(vector<int>&box, int ci, int ti){
    if(ci > ti){
        for(int i =0;i<box.size();i++){
            cout<<box[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<box.size();i++){
        if(box[i]==0){
            box[i] = ci;
            func(box, ci+1, ti);
            box[i] = 0;
        }
    }
}

int main(){
    int n, items;
    cin>>n>>items;
    vector<int>boxes(n, 0);

    func(boxes, 1, items);

    return 0;
}
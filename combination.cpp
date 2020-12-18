#include<bits/stdc++.h>
using namespace std;

void func(int box, int boxes, int item, int totalItem, string result){
    
    if(box > boxes){
        if(item == totalItem){
            cout<<result<<endl;
        }
        return;
    }
    func(box+1, boxes, item+1, totalItem, result + "i");
    func(box+1, boxes, item, totalItem, result+"_");
}

int main(){
    int n,item;
    cin>>n>>item;
    func(1, n, 0, item, "");

    return 0;
}
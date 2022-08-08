#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int>nums(0);
vector<int>seg(0);
unordered_map<int,int>m;
int n;
void build(int start = 0,int end = n - 1,int idx = 1){
    if(start == end){
        seg[idx] = 1;
        m[idx] = nums[start];
        return;
    }
    int mid = (start + end)/2;
    build(start,mid,idx*2);
    build(mid+1,end,idx*2+1);
    seg[idx] = seg[idx*2]+seg[idx*2+1];
}
int getEle(int pos,int start = 0,int end = n-1,int idx = 1){
    if(start == end){
        seg[idx] = 0;
        return m[idx];
    }
    int a;
    int mid = (start + end)/2;
    if(seg[idx*2]>= pos){
       a  =  getEle(pos,start,mid,idx*2);
    }
    else a = getEle(pos-seg[idx*2],mid+1,end,idx*2+1);
    seg[idx] = seg[idx*2] + seg[idx*2+1];
    return a;
}
int main(){
    cin>>n;
    nums.resize(n,0);
    seg.resize(4*n,0);
    for(int i=0;i<n;i++)cin>>nums[i];
    build();
    for(int i=0;i<n;i++){
        int pos;
        cin>>pos;
        cout<<getEle(pos)<<endl;
    }
    
    
    return 0;
}

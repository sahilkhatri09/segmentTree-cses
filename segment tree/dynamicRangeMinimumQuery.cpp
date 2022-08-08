#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void build(vector<int>&nums,vector<int>&seg,int start,int end,int idx){
    if(start == end){
        seg[idx] = nums[start];
        return;
    }
    int mid = (start + end)/2;
    build(nums,seg,start,mid,idx*2);
    build(nums,seg,mid+1,end,idx*2+1);
    seg[idx] = min(seg[idx*2],seg[idx*2+1]);
}
void update(vector<int>&seg,int start,int end,int pos,int val,int idx){
    if(start > pos || end < pos)return;
    if(start == end){
        seg[idx] = val;
        return;
    }
    int mid = (start + end)/2;
    update(seg,start,mid,pos,val,idx*2);
    update(seg,mid+1,end,pos,val,idx*2+1);
    seg[idx] = min(seg[idx*2] , seg[idx*2+1]);
}
int getMin(vector<int>&seg,int left,int right,int start,int end,int idx){
    if(start > right || end < left)return INT_MAX;
    if(start >= left && end <= right)return seg[idx];
    int mid = (start + end)/2;
    int lm = getMin(seg,left,right,start,mid,idx*2);
    int rm = getMin(seg,left,right,mid+1,end,idx*2+1);
    return min(lm,rm);
}
int main(){

    int n,q;
    cin>>n>>q;
    vector<int>nums(n,0);
    for(int i=0;i<n;i++)cin>>nums[i];
    vector<int>seg(4*n,0);
    build(nums,seg,0,n-1,1);
    for(int i=0;i<q;i++){
        int type;
        cin>>type;
        if(type == 1){
            int pos,val;
            cin>>pos>>val;
            pos--;
            update(seg,0,n-1,pos,val,1);
        }
        else{
            int left,right;
            cin>>left>>right;
            left--,right--;
            cout<<getMin(seg,left,right,0,n-1,1)<<endl;
        }
    }
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
void build(vector<int>&nums,vector<long long>&seg,int start,int end,int idx){
    if(start == end){
        seg[idx] = nums[start];
        return;
    }
    int mid = (start + end)/2;
    build(nums,seg,start,mid,idx*2);
    build(nums,seg,mid+1,end,idx*2+1);
    seg[idx] = seg[idx*2] + seg[idx*2+1];
}
void update(vector<long long>&seg,int start,int end,int pos,int val,int idx){
    if(start > pos || end < pos)return;
    if(start == end){
        seg[idx] = val;
        return;
    }
    int mid = (start + end)/2;
    update(seg,start,mid,pos,val,idx*2);
    update(seg,mid+1,end,pos,val,idx*2+1);
    seg[idx] = seg[idx*2] + seg[idx*2+1];
}

long long getSum(vector<long long>&seg,int left,int right,int start,int end,int idx){
    if(start > right || end < left){
        return 0;
    }
    if(start >= left && end <= right) return seg[idx];
    int mid = (start + end)/2;
    long long ls = getSum(seg,left,right,start,mid,idx*2);
    long long rs = getSum(seg,left,right,mid+1,end,idx*2+1);
    return ls + rs;
}
int main(){
    int n,q;
    cin>>n>>q;
    vector<int>nums(n,0);
    for(int i=0;i<n;i++)cin>>nums[i];
    vector<long long>seg(n*4,0);
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
            cout<<getSum(seg,left,right,0,n-1,1)<<endl;
        }
    }
}
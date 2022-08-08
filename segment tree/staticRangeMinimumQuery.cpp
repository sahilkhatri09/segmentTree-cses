#include<iostream>
#include<climits>
#include<vector>
using namespace std;
void build(vector<long>&nums,vector<long>&seg,int start,int end,int idx){
    if(start == end){
        seg[idx] = nums[start];
        return;
    }
    int mid =(start + end)/2;
    build(nums,seg,start,mid,idx*2);
    build(nums,seg,mid+1,end,idx*2+1);
    seg[idx] = min(seg[idx*2],seg[idx*2+1]);
}
long getMin(vector<long>&seg,int start,int end,int left,int right,int idx){
    if(start > right || end < left)return INT_MAX;
    if(start >= left && end <= right)return seg[idx];
    int mid = (start + end)/2;
    int lm = getMin(seg,start,mid,left,right,idx*2);
    int rm = getMin(seg,mid+1,end,left,right,idx*2+1);
    return min(lm,rm);
}
int main(){
    int n,q;
    cin>>n>>q;
    vector<long > nums(n,0);
    for(int i=0;i<n;i++)cin>>nums[i];
    vector<long>seg(n*4,0);
    build(nums ,seg,0,n-1,1);
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<getMin(seg,0,n-1,a-1,b-1,1)<<endl;
    }

    return 0;
}
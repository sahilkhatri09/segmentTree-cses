#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void build(vector<int>&tree,vector<int>&nums,int start,int end,int node){
    if(start == end){
        tree[node] = nums[start];
        return;
    }
    int mid = (start + end)/2;
    build(tree,nums,start,mid,node*2);
    build(tree,nums,mid+1,end,node*2+1);
    tree[node] = min(tree[node*2],tree[node*2+1]);
}
int get(vector<int>&tree,vector<int>&nums,int left,int right,int start,int end,int node){
    if(start > right || end < left)return INT_MAX;
    if(start >= left && end <= right)return tree[node];
    int mid = (start + end)/2;
    int k = get(tree,nums,left,right,start,mid,node*2);
    int p = get(tree,nums,left,right,mid+1,end,node*2+1);
    return min(k,p);
}
int main(){
    int n;
    cin>>n;
    vector<int>num(n,0);
    for(int i=0;i<n;i++)cin>>num[i];
    int q;
    cin>>q;
    vector<int>left(q,0),right(q,0);
    for(int i=0;i<q;i++){
        cin>>left[i];
        cin>>right[i];
    }
    vector<int>tree(4*n,0);
    build(tree,num,0,n-1,1);
    for(int i=0;i<q;i++){
        // cout<<left[i]<<" "<<right[i]<<endl;
        cout<<get(tree,num,left[i],right[i],0,n-1,1)<<endl;
    }

}
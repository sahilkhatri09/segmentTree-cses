#include<iostream>
#include<vector>
using namespace std;

vector<int>nums(0);
vector<long > seg(0);
vector<long >lazy(0);
int n;
void propagate(int idx,int start,int end){
        seg[idx] += (end-start + 1)*lazy[idx];
        if(start != end){
            lazy[idx*2] += lazy[idx];
            lazy[idx*2+1] += lazy[idx];
        }
        lazy[idx] = 0;
}
void build(int start = 0,int end = n-1,int idx = 1){
    if(start == end){
        seg[idx] = nums[start];
        return;
    }
    int mid = (start + end)/2;
    build(start,mid,idx*2);
    build(mid+1,end,idx*2+1);
    seg[idx] = seg[idx*2]+ seg[idx*2+1];
}
void update(int left,int right,int val,int start = 0,int end = n-1,int idx = 1){
    propagate(idx,start,end);
    if(left > end || right < start)return;
    if(start >= left && end <= right){
        lazy[idx] += val;
        propagate(idx,start,end);
        return;
    }
    int mid = (start + end)/2;
    update(left,right,val,start,mid,idx*2);
    update(left,right,val,mid+1,end,idx*2+1);
    seg[idx] = seg[idx*2] + seg[idx*2+1];
}
long get(int pos,int idx = 1,int start = 0,int end = n-1){
    propagate(idx,start,end);
    if(pos < start || pos > end)return 0;
    if(start == end){
        return seg[idx];
    }

    int mid = (start + end)/2;
    return get(pos,idx*2,start,mid) + get(pos,idx*2+1,mid+1,end);
}
int main(){
    cin>>n;
    int q;
    cin>>q;
    nums.resize(n,0);
    seg.resize(4*n,0);
    lazy.resize(4*n,0);
    for(int i=0;i<n;i++)cin>>nums[i];
    build();
    // for(int i=1;i<4*n;i++)cout<<seg[i]<<" ";
    for(int i=0;i<q;i++){
        int type;
        cin>>type;
        if(type == 1){
            int left,right,val;
            cin>>left>>right>>val;
            left--,right--;
            update(left,right,val);
        }
        else{
            int pos;
            cin>>pos;
            pos--;
            cout<<get(pos)<<endl;
        }
    }
    

    return 0;
}
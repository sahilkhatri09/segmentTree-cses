#include<iostream>
#include<vector>
using namespace std;
vector<int>nums(0);
vector<int>seg(0);
int n;
void build(int start = 0,int end = n - 1,int idx = 1){
    if(start == end){
        seg[idx] = nums[start];
        return;
    }
    int mid = (start + end)/2;
    build(start,mid,idx*2);
    build(mid+1,end,idx*2+1);
    seg[idx] = max(seg[idx*2],seg[idx*2+1]);
}
int getVal(int val,int idx = 1,int start = 0,int end = n-1){
    if(start == end){
        seg[idx] -= val;
        return start + 1;
    }
    int mid = (start + end)/2;
    int a ;
    if(seg[idx*2] >= val){
        a=  getVal(val,idx*2,start,mid);
    }
    else a = getVal(val,idx*2+1,mid+1,end);
    seg[idx] = max(seg[idx*2] , seg[idx*2+1]);
    return a;

}
int main(){
    int q;
    cin>>n>>q;
    nums.resize(n,0);
    seg.resize(4*n,0);
    for(int i=0;i<n;i++)cin>>nums[i];
    build();
    for(int i=0;i<q;i++){
        int val;
        cin>>val;
        if(seg[1] < val){
            cout<<0<<endl;
            continue;;
        }
        cout<<getVal(val) <<endl;
    }
}
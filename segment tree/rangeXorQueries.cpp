#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<int>nums(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>nums[i];
        nums[i] = nums[i]^nums[i-1];
    }
    for(int i=0;i<q;i++){
        int left,right;
        cin>>left>>right;
        cout<<(nums[right] ^ nums[left-1])<<endl;
    }

    return 0;
}
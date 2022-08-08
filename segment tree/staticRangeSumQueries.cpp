#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<long long >sum(n+1,0);
    sum[0] = 0;
    for(int i=0;i<n;i++){
        cin>>sum[i+1];
        sum[i+1] += sum[i];
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        a--;
        cout<<sum[b]-sum[a]<<endl;

    }

    return 0;
}
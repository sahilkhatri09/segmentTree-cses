#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<vector<int> > forest(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char a;
            cin>>a;
            if(a == '*'){
                forest[i][j] = 1;
            }
            forest[i][j] += (forest[i][j-1] + forest[i-1][j] - forest[i-1][j-1]);
        }
    }
    for(int i=0;i<q;i++){
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        cout<<forest[y2][x2] - forest[y2][x1-1] - forest[y1-1][x2] + forest[y1-1][x1-1]<<endl;
    }
}
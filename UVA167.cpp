#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
int save[8][8],ans;
bool queen[8][8];
void solve(int n,int m){
    if(n==8){
        int tmp=0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(queen[i][j])
                    tmp+=save[i][j];
            }
        }
        ans=max(tmp,ans);
        return;
    }
    for(int i=0;i<8;i++){
        if(queen[n][i]||queen[i][m])
            return;
        if(i>0&&n-i>=0&&m-i>=0&&queen[n-i][m-i])
            return;
        if(i>0&&n-i>=0&&m+i<8&&queen[n-i][m+i])
            return;
        if(i>0&&n+i<8&&m-i>=0&&queen[n+i][m-i])
            return;
        if(i>0&&n+i<8&&m+i<8&&queen[n+i][m+i])
            return;
    }
    for(int i=0;i<8;i++){
        queen[n][m]=true;
        solve(n+1,i);
        queen[n][m]=false;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        memset(queen,false,sizeof(queen));
        ans=0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cin>>save[i][j];
            }
        }
        for(int i=0;i<8;i++){
            solve(0,i);
        }
        cout<<setw(5)<<ans<<endl;
    }
}

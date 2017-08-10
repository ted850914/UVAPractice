#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
vector<int> people[30010];
int ans,n,m,cnt;
bool color[30010];
void DFS(int num){
    if(color[num])
        cnt++;
    else
        return;
    if(cnt>ans)
        ans=cnt;
    color[num]=false;
    for(int i=0;i<people[num].size();i++){
        //cout<<"people["<<num<<"]["<<i<<"]="<<people[num][i]<<endl;
        if(color[people[num][i]]){
            DFS(people[num][i]);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<30010;i++)
            people[i].clear();
        memset(color,true,sizeof(color));
        ans=0;

        cin>>n>>m;
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            bool flag=true;
            people[a].push_back(b);
            people[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            cnt=0;
            DFS(i);
        }
        cout<<ans<<endl;
    }
}

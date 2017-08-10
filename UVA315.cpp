#include<iostream>
#include<vector>
#include<string.h>
#include<sstream>
using namespace std;
vector<int> array[110];
int ans,n;
bool color[110];
void DFS(int num){
    if(!color[num])
        return;
    color[num]=false;
    for(int i=0;i<array[num].size();i++){
        if(color[array[num][i]]){
            DFS(array[num][i]);
        }
    }
}
int main(){
	char save[300];
	while(cin>>n&&n!=0){
		int ans=0,goal=0;
		while(cin.getline(save,300)&&save[0]!='0'){
			stringstream line(save);
			int a,b;
			line>>a;
			while(line>>b){
				array[a].push_back(b);
				array[b].push_back(a);
			}
		}
		for(int i=1;i<=n;i++)
			color[i]=true;
		for(int i=1;i<=n;i++){
			if(color[i]){
				goal++;
				DFS(i);
			}
		}
		//cout<<goal<<endl;
		for(int i=1;i<=n;i++){
			int test=0;
			for(int j=1;j<=n;j++)
				color[j]=true;
			color[i]=false;
			for(int j=1;j<=n;j++){
				if(color[j]){
					test++;
					DFS(j);
				}
			}
			if(test>goal)
				ans++;
		}
		cout<<ans<<endl;
		
		for(int i=1;i<=n;i++)
			array[i].clear();
	}
} 

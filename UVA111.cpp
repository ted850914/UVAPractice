#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n,save[30],rank[30],test[30],table[30][30];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>save[i];
		rank[save[i]]=i;
	}
	while(cin>>save[1]){
		memset(table,0,sizeof(table));
		test[save[1]]=1;
		for(int i=2;i<=n;i++){
			cin>>save[i];
			test[save[i]]=i;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(rank[i]==test[j])
					table[i][j]=table[i-1][j-1]+1;
				else
					table[i][j]=max(table[i-1][j],table[i][j-1]);
			}
		}
		cout<<table[n][n]<<endl;
	}
}

#include<iostream>
#include<cstring>
#include<iomanip>
#define maxx 0xfffffff
using namespace std;
int n,m,domino[550][550];
bool used[550];
double second[550][550];
void push(int num){
	used[num]=true;
	for(int i=1;i<=n;i++){
		if(domino[num][i]){
			if(second[i][i]>domino[num][i]+second[num][num]){
				second[i][i]=domino[num][i]+second[num][num];
			} 
		}
	}
	int min=maxx,save=-1;
	for(int i=1;i<=n;i++){
		if(!used[i]&&second[i][i]<min){
			min=second[i][i];
			save=i;
		}
	}
	if(save!=-1)
		push(save);
	else
		return;
}
void refresh_path(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int a=second[i][i],b=second[j][j];
			if(i!=j && a!=maxx && b!=maxx && a<=b){
				if(b-a==domino[i][j]){
					second[i][j]=(b-a)/2.0;
				}
				else{
					second[i][j]=(domino[i][j]-(b-a))/2.0+b;
				}
			}
		}
	}
}
int main(){
	cout<<fixed<<setprecision(1);
	int count=1;
	while(cin>>n>>m){
		if(n==0&&m==0)
			break;
		memset(domino,0,sizeof(domino));
		memset(used,false,sizeof(used));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				second[i][j]=maxx;
			}
		}
		
		for(int i=0;i<m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			domino[a][b]=c;
			domino[b][a]=c;
		}
		
		second[1][1]=0;
		push(1);
		refresh_path();
		double ans_second=-1;
		int ans1,ans2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(second[i][j]!=maxx&&second[i][j]>=ans_second){
					if(second[i][j]==ans_second){
						if(i==j&&ans1>i){
							ans_second=second[i][j];
							ans1=i;
							ans2=j;
						}
					}
					else{
						ans_second=second[i][j];
						ans1=i;
						ans2=j;
					}
				}
			}
		}
		cout<<"System #"<<count++<<endl;
		if(ans1>ans2)
			swap(ans1,ans2);
		if(ans1==ans2){
			cout<<"The last domino falls after "<<ans_second<<" seconds, at key domino "<<ans1<<"."<<endl<<endl;
		}
		else
			cout<<"The last domino falls after "<<ans_second<<" seconds, between key dominoes "<<ans1<<" and "<<ans2<<"."<<endl<<endl;
	}
} 

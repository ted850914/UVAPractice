#include<iostream>
using namespace std;
int main(){
	int length,t,cut[60],value[60],ans[60][60];
	while(cin>>length&&length!=0){
		cin>>t;
		cut[0]=0;
		cut[t+1]=length;
		for(int i=1;i<=t;i++){
			cin>>cut[i];
		}
		for(int i=1;i<=t+1;i++){
			value[i]=cut[i]-cut[i-1];
		}
		for(int i=t+1;i>0;i--){
			for(int j=i;j<=t+1;j++){
				int mini=999999;
				if(i==j)
					ans[i][j]=0;
				else{
					for(int k=i;k<j;k++){
						mini=min(ans[i][k]+ans[k+1][j],mini);
					}
					for(int l=i;l<=j;l++)
						mini+=value[l];
					ans[i][j]=mini;
				}
			}
		}
		cout<<"The minimum cutting is "<<ans[1][t+1]<<"."<<endl;
	} 
}

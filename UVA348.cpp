#include<iostream>
#include<string.h>
using namespace std;
int ans[20][20];
void print(int left,int right){
	if(left==right){
		cout<<"A"<<left;
		return;
	}
	if(left==right-1){
		cout<<"(A"<<left<<" x "<<"A"<<right<<")";
		return;
	}
	int save=ans[left][right];
	cout<<"(";
	print(left,save);
	cout<<" x ";
	print(save+1,right);
	cout<<")";
}
int main(){
	int t,p[20],array[20][20],count=0;
	while(cin>>t&&t!=0){
		count++;
		memset(p,0,sizeof(p));
		memset(array,0,sizeof(array));
		memset(ans,0,sizeof(ans));
		for(int i=0;i<t;i++){
			cin>>p[i]>>p[i+1];
		}
		for(int i=t;i>0;i--){
			for(int j=i;j<=t;j++){
				int mini=99999999;
				for(int k=i;k<j;k++){
					if(mini>array[i][k]+array[k+1][j]+p[i-1]*p[k]*p[j]){
						mini=array[i][k]+array[k+1][j]+p[i-1]*p[k]*p[j];
						ans[i][j]=k;
					}
				}
				if(i==j)
					array[i][j]=0;
				else
					array[i][j]=mini;
			} 
		}
		/*for(int i=1;i<=t;i++){
			for(int j=1;j<=t;j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}*/
		cout<<"Case "<<count<<": ";
		print(1,t);
		cout<<endl;
	}
} 

#include<iostream>
using namespace std;
bool compare(){
	
}
int main(){
	int n,count=1;
	while(cin>>n&&n!=0){
		int a,b,c;
		int array[200][3]={0};
		for(int i=0;i<n*6;i+=6){
			cin>>a>>b>>c;
			array[i][0]=a,array[i][1]=b,array[i][2]=c;
			array[i+1][0]=a,array[i+1][1]=c,array[i+1][2]=b;
			array[i+2][0]=b,array[i+2][1]=a,array[i+2][2]=c;
			array[i+3][0]=b,array[i+3][1]=c,array[i+3][2]=a;
			array[i+4][0]=c,array[i+4][1]=a,array[i+4][2]=b;
			array[i+5][0]=c,array[i+5][1]=b,array[i+5][2]=a;
		}
		for(int i=0;i<n*6;i++){
			for(int j=i+1;j<n*6;j++){
				if(array[i][0]>array[j][0]){
					swap(array[i],array[j]);
				}
				else if(array[i][0]==array[j][0]){
					if(array[i][1]>array[j][1]){
						swap(array[i],array[j]);
					}
				}
			}
		}
		int dp[200]={0},ans=0;
		for(int i=0;i<n*6;i++){
			dp[i]=array[i][2];
			for(int j=0;j<i;j++){
				if(array[i][0]>array[j][0] && array[i][1]>array[j][1] && dp[j]+array[i][2]>dp[i]){
					dp[i]=dp[j]+array[i][2];
				}
			}
			ans=max(ans,dp[i]);
		}
		cout<<"Case "<<count++<<": maximum height = "<<ans<<endl;
	}
}

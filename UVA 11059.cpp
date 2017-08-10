#include<iostream>
using namespace std;
int main(){
	int n,times=0;
	while(cin>>n){
		long long int ans=0,temp=1,save[20];
		for(int i=0;i<n;i++){
			cin>>save[i];
		}
		for(int i=0;i<n;i++){
			temp=1;
			for(int j=i;j<n;j++){
				temp*=save[j];
				ans=max(temp,ans);
			}
		}
		cout<<"Case #"<<++times<<": The maximum product is "<<ans<<"."<<endl<<endl;
	}
} 

#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n&&n!=0){
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=i*i;
		cout<<ans<<endl;
	} 
}

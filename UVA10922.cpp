#include<iostream>
using namespace std;
int ans;
string s;
void solve(int n){
	int temp=0;
	if(n==0){
		for(int i=0;i<s.length();i++){
			temp=temp+s[i]-'0';
		}
	}
	else{
		while(n>0){
			temp+=n%10;
			n/=10;
		}
	}
	if(temp%9!=0){
		ans=-1;
	}
	else if(temp>9){
		ans++;
		solve(temp);
	}
}
int main(){
	while(cin>>s&&s!="0"){
		ans=1;
		solve(0);
		if(ans==-1){
			cout<<s<<" is not a multiple of 9."<<endl;
		}
		else{
			cout<<s<<" is a multiple of 9 and has 9-degree "<<ans<<"."<<endl;
		}
	}
}

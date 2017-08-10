#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		string s[110];
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>s[i];
		}
		sort(s,s+n);
		int ans=s[0].length();
		for(int i=0;i<n-1;i++){
			for(int j=0;j<s[i+1].length();j++){
				if(s[i][j]!=s[i+1][j]){
					ans+=s[i+1].length()-j;
					break;
				}
			}
		}
		cout<<ans<<endl;
		for(int i=0;i<n;i++){
			cout<<s[i]<<endl;
		}
	}
}

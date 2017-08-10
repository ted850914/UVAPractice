#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	while(cin>>s){
		int save=0,num=0;
		bool flag=true;	//true is front, false is back
		string ans="";
		for(int i=0;i<s.length();i++){
			if(s[i]=='['||s[i]==']'){
				if(flag){
					ans.insert(0,s,save,num);
				}
				else{
					ans.insert(ans.length(),s,save,num);
				}
				save=i+1;
				num=0;
				if(s[i]=='['){
					flag=true;
				}
				else{
					flag=false;
				}
			}
			else{
				num++;
			}
		}
		if(num){
			if(flag){
				ans.insert(0,s,save,num+1);
			}
			else{
				ans.insert(ans.length(),s,save,num+1);
			}
		}
		cout<<ans<<endl;
	}
} 

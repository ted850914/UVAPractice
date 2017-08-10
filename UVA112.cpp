#include<iostream>
using namespace std;
int ans;
bool yes;
void solve(int sum){
	bool flag1=false,flag2=false;  // '('=true ')'=false
	char c;
	int num=0;
	while(cin.get(c)){
		if(c=='('){
			solve(sum+num);
			break;
		} 
		if(c==')'){
			flag1=true;
			break;
		}
        if(c>='0'&&c<='9')
        	num=10*num+c-'0';
        if(c=='-'){
        	cin>>num;
        	num*=-1;
		}
    }
    
    while(cin.get(c))
    	if(c=='(')
    		break;
    
    num=0;
    while(cin.get(c)){
		if(c=='('){
			solve(sum+num);
			break;
		} 
		if(c==')'){
			flag2=true;
			break;
		}
        if(c>='0'&&c<='9')
        	num=10*num+c-'0';
        if(c=='-'){
        	cin>>num;
        	num*=-1;
		}
	}
	while(cin.get(c)){
		if(c==')')
			break;
	} 
	if(flag1&&flag2&&sum==ans){
		yes=true;
	}
}
int main(){
	char c;
	while(cin>>ans){
		int num=0;
		yes=false;
		
		while(cin.get(c)){
			if(c=='(')
				break;
		}
		while(cin.get(c)){
			if(c=='('){
				solve(num);
				break;
			} 
			if(c==')'){
				break;
			}
	        if(c>='0'&&c<='9')
	        	num=10*num+c-'0';
	        if(c=='-'){
	        	cin>>num;
	        	num*=-1;
			}
		}
		if(yes)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
}

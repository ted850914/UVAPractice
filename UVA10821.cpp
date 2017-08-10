#include<iostream>
#include<cmath>
using namespace std;
void recursion(int down,int top,int h,bool flag){
	int n=top-down;
	if(n==0)
		return;
	if(flag)
		cout<<" ";
	flag=true;
	if(n<=pow(2,h-1)){
		cout<<down;
		recursion(down+1,top,h-1,flag);
	}
	else{
		int save=n-pow(2,h-1)+down;
		cout<<save;
		recursion(down,save,h-1,flag);
		recursion(save+1,top,h-1,flag);
	}
}
int main(){
	int n,h,count=0;
	while(cin>>n>>h){
		count++;
		if(n==0&&h==0)
			break;
		if(n>pow(2,h)-1)
			cout<<"Case "<<count<<": "<<"Impossible."<<endl;
		else{
			cout<<"Case "<<count<<": ";
			recursion(1,n+1,h,false);
			cout<<endl;
		}
	}
} 

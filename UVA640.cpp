#include<iostream>
#include<string.h>
using namespace std;
bool ans[1000001];
int solve(int i){
	int save=i;
	while(i>0){
		save+=i%10;
		i=i/10;
	}
	return save;
}
int main(){
	memset(ans,true,sizeof(ans));
	for(int i=1;i<=1000000;i++){
		if(solve(i)<=1000000)
			ans[solve(i)]=false;
	}
	
	for(int i=1;i<=1000000;i++){
		if(ans[i])
			cout<<i<<endl;
	}
}

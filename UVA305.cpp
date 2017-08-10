#include<iostream>
#include<string.h>
using namespace std;
int solve(int k){
	int i=k;
	while(i++){
		int num,save=0,people=k*2,dead=0;
		while(1){
			num=(i-save-1)%people+1;
			save=people-num;
			dead++;
			people--;
			if(num<=k)
				break;
			if(dead==k)
				return i;
		}
	}
}
int main(){
	int ans[14],q;
	for(int k=1;k<14;k++){
		ans[k]=solve(k);
	}
	while(cin>>q&&q!=0){
		cout<<ans[q]<<endl;
	}
	
}

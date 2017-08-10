#include<iostream>
using namespace std;
int array[40];
int main(){
	int t;
	array[0]=1;
	array[2]=3;
	for(int i=4;i<=30;i+=2){
		array[i]=4*array[i-2]-array[i-4];
	}
	while(cin>>t&&t!=-1){
		cout<<array[t]<<endl;
	}
}

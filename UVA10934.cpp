#include<iostream>
using namespace std;
int main(){
	long long table[64][64]={0};
	for(int i=1;i<10;i++){
		for(int j=1;j<10;j++){
			table[i][j]=table[i-1][j-1]+table[i][j-1]+1;
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
	long long k,n;
	while(cin>>k>>n && k!=0){
		if(k>63)
			k=63;
		bool flag=false;
		for(int i=1;i<64;i++){
			if(table[k][i]>=n){
				cout<<i<<endl;
				flag=true;
				break;
			}
		}
		if(!flag){
			cout<<"More than 63 trials needed."<<endl;
		}
	}
} 

#include<iostream>
using namespace std;
int main(){
	long long int n,m;
	while(cin>>n>>m){
		if(n>m)
			cout<<n-m<<endl;
		else
			cout<<m-n<<endl;
	}
}

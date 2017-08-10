#include<iostream>
#include<algorithm>
using namespace std;
int n,array[1000],ans;
int solve1(int i){
	return (array[0]+array[1]+array[1]+array[i-1]);
}
int solve2(int i){
	return (array[0]+array[0]+array[i-2]+array[i-1]);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>array[i];
		}
		sort(array,array+n);
		int save=n;
		if(n==1){
			cout<<array[0]<<endl<<array[0]<<endl;
		}
		else{
			while(n>3){
				if(solve1(n)<solve2(n)){
					ans+=(array[0]+array[1]+array[1]+array[n-1]);
					n-=2;
				}
				else{
					ans+=(array[0]+array[0]+array[n-2]+array[n-1]);
					n-=2;
				}
			}
			if(n==2)
				ans+=array[1];
			else if(n==3)
				ans+=(array[0]+array[1]+array[2]);
			
			cout<<ans<<endl;
			n=save;
			
			while(n>3){
				if(solve1(n)<solve2(n)){
					cout<<array[0]<<" "<<array[1]<<endl;
					cout<<array[0]<<endl;
					cout<<array[n-2]<<" "<<array[n-1]<<endl;
					cout<<array[1]<<endl;
					n-=2;
				}
				else{
					cout<<array[0]<<" "<<array[n-2]<<endl;
					cout<<array[0]<<endl;
					cout<<array[0]<<" "<<array[n-1]<<endl;
					cout<<array[0]<<endl;
					n-=2;
				}
			}
			if(n==2){
				cout<<array[0]<<" "<<array[1]<<endl;
			}
			else if(n==3){
				cout<<array[0]<<" "<<array[1]<<endl;
				cout<<array[0]<<endl;
				cout<<array[0]<<" "<<array[2]<<endl;
			}
		}
		if(t>0)
			cout<<endl;
	}
}

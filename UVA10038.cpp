#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		bool jolly[3000]={false};
		int before,after;
		cin>>before;
		for(int i=0;i<n-1;i++){
			cin>>after;
			int save=after-before;
			if(save<0)
				save*=-1;
			if(save<3000)
				jolly[save]=true;
			before=after;
		}
		bool ans=true;
		for(int i=1;i<n;i++){
			if(jolly[i]==false){
				ans=false;
			} 
		}
		if(ans)
			cout<<"Jolly"<<endl;
		else
			cout<<"Not jolly"<<endl;
	}
}

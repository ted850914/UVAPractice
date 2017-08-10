#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int n,x,array[20],times=0;
	bool people[51],flag=false;
	while(cin>>n){
		cin>>x; 
		times++;
		int saven=n;
		flag=false;
		memset(people,true,sizeof(people));
		for(int i=0;i<20;i++){
			cin>>array[i];
		}
		if(n>x){
			for(int i=0;i<20;i++){
				int k=0;
				for(int j=1;j<=n;j++){
					if(people[j])
						k++;
					else
						continue;
					if(k==array[i]){
						people[j]=false;
						saven--;
						k=0;
					}
					if(saven==x){
						flag=true;
						break;
					}
				}
				if(flag)
					break;
			}
		}
		cout<<"Selection #"<<times<<endl;
		bool WTF=true;
		for(int i=1;i<=n;i++){
			if(people[i]&&WTF){
				cout<<i;
				WTF=false;
			}
			else if(people[i]){
				cout<<" "<<i;
			}
		}
		cout<<endl<<endl;
	}
	
} 

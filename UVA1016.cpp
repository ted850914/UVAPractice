#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int n,num[1010],sortnum[1010],shortmin,times,mini;
bool flag[1010];

int search(int i,int total){
	flag[i]=true;
	times++;
	total+=num[i];
	for(int j=0;j<n;j++){
		if(num[i]==sortnum[j]){
			//cout<<"mini="<<mini<<" shortmin="<<shortmin<<" times="<<times<<" total="<<total<<endl;
			if(num[i]<shortmin)
				shortmin=num[i];
			if(flag[j]){
				if(total+(times-2)*shortmin>total+mini*(times+1)+shortmin){
					//cout<<"1 "<<total+mini*(times+1)+shortmin<<endl;
					return total+mini*(times+1)+shortmin;
				}
				else{
					//cout<<"2 "<<total+(times-2)*shortmin<<endl;
					return total+(times-2)*shortmin;
				}
			}
			else
				return search(j,total);
		}
	}
}
int main(){
	int save,number=1;
	while(cin>>n){
		mini=99999999;
		int ans=0;
		memset(flag,false,sizeof(flag));
		if(n==0)
			break;
		for(int i=0;i<n;i++){
			cin>>num[i];
			if(num[i]<mini)
				mini=num[i];
			sortnum[i]=num[i];
		}
		sort(sortnum,sortnum+n);
		for(int i=0;i<n;i++){
			shortmin=999999999;
			times=0;
			if(!flag[i]&&num[i]!=sortnum[i]){
				ans=ans+search(i,0);
			}
		}
		cout<<"Case "<<number<<": "<<ans<<endl<<endl;
		number++;
	}
}

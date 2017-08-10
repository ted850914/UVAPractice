#include<iostream>
#include<string.h>
using namespace std;
int n,h,f[1000],d[1000],lake_time[1000],ans_time[1000],ans;
bool flag=false;
void solve(int end){
	int save_h=h,save_f[1000],save_time[1000],temp=0;
	memcpy(save_f,f,sizeof(f));
	memset(save_time,0,sizeof(save_time));
	
	for(int i=1;i<end;i++)
		save_h-=lake_time[i];
	
	while(save_h>0){
		save_h--;
		int max_f=0,save_i;
		for(int i=1;i<=end;i++){
			if(max_f<save_f[i]){
				max_f=save_f[i];
				save_i=i;
			}
		}
		if(max_f==0){
			save_time[1]+=5;
		}
		else{
			save_f[save_i]-=d[save_i];
			save_time[save_i]+=5;
			temp+=max_f;
		}
	}
	if(temp>ans){
		ans=temp;
		memcpy(ans_time,save_time,sizeof(ans_time)); 
	}
}
int main(){
	while(cin>>n&&n!=0){
		memset(f,0,sizeof(f));
		memset(d,0,sizeof(d));
		memset(lake_time,0,sizeof(lake_time));
		memset(ans_time,0,sizeof(ans_time));
		ans=0;
		cin>>h;
		h*=12;
		for(int i=1;i<=n;i++)
			cin>>f[i];
		for(int i=1;i<=n;i++)
			cin>>d[i];
		for(int i=1;i<=n-1;i++)
			cin>>lake_time[i];
		for(int i=1;i<=n;i++)
			solve(i);
		
		if(flag)
			cout<<endl;	
		flag=false;

		for(int i=1;i<=n;i++){
			if(ans==0&&i==1){
				cout<<h*5;
				flag=true;
				continue;
			}
			if(flag)
				cout<<", ";
			cout<<ans_time[i];
			flag=true;
		}
		cout<<endl<<"Number of fish expected: "<<ans<<endl; 
	}
} 

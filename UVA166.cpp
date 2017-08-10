#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
int dp_back[3501],dp_give[3501],cnum[6],goal,ans;
void back(){
	dp_back[0]=0;
	int coin[6]={5,10,20,50,100,200};
	for(int i=0;i<3501;i+=5){
		for(int j=0;j<6;j++){
			if(i-coin[j]>=0&&dp_back[i-coin[j]]+1<dp_back[i])
				dp_back[i]=dp_back[i-coin[j]]+1;
		}
	}
}
void give(){
	int coin[6]={5,10,20,50,100,200};
	for(int i=0;i<6;i++){
		for(int j=3500;j>=0;j--){
			if(dp_give[j]){
				int savecnum=cnum[i],savej=j;
				while(savej+coin[i]<=3500&&savecnum>0){
					if(dp_give[savej+coin[i]]>dp_give[savej]+1){
						dp_give[savej+coin[i]]=dp_give[savej]+1;
					}
					savej=savej+coin[i];
					savecnum--;
				}
			}
		}
		int count=1;
		for(int j=coin[i];j<3501&&cnum[i]>0;j+=coin[i]){
			dp_give[j]=count;
			count++;
			cnum[i]--;
		}
	}
}
void solve(){
	for(int i=goal;i<3501;i+=5){
		if(dp_give[i]+dp_back[i-goal]<ans)
			ans=dp_give[i]+dp_back[i-goal];
	}
}
int main(){
	memset(dp_back,999999,sizeof(dp_back));
	back();  //建找錢表 
	while(cin>>cnum[0]>>cnum[1]>>cnum[2]>>cnum[3]>>cnum[4]>>cnum[5]){
		ans=999999;
		memset(dp_give,999999,sizeof(dp_give));
		if(cnum[0]==0&&cnum[1]==0&&cnum[2]==0&&cnum[3]==0&&cnum[4]==0&&cnum[5]==0){
			break;
		}
		double what;
		cin>>what;
		goal=(what*1000)/10;
		give();  //建給錢表 
		solve();
		cout<<setw(3)<<ans<<endl;
	}
}

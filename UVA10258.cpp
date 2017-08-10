#include<iostream>
#include<sstream>
using namespace std;
int main(){
	int t;
	cin>>t;
	cin.get();
	cin.get();
	for(int count=0;count<t;count++){
		if(count)
			cout<<endl;
		bool team_submission[110]={false};
		int team_wrong[110][10]={0},team_time[110]={0},team_getAC[110]={0};
		int team,problem,time,count_teamnum=0;
		char ans;
		string s;
		stringstream ss;
		while(getline(cin,s)&&s!=""){
			ss.clear();
			ss.str(s);
			ss>>team>>problem>>time>>ans;
			if(!team_submission[team]){
				team_submission[team]=true;
				count_teamnum++;
			}
			if(ans=='I'&&team_wrong[team][problem]!=-1){
				team_wrong[team][problem]++;
			}
			else if(ans=='C'&&team_wrong[team][problem]!=-1){
				team_time[team]+=team_wrong[team][problem]*20+time;
				team_getAC[team]++;
				team_wrong[team][problem]=-1;				//solved
			}
		}
		for(int i=0;i<count_teamnum;i++){
			int now_team=0,maxAC=-1,mintime=9999999;
			for(int j=1;j<=100;j++){
				if(team_submission[j]){
					if(team_getAC[j]>maxAC||((team_getAC[j]==maxAC)&&team_time[j]<mintime)){
						now_team=j;
						maxAC=team_getAC[j];
						mintime=team_time[j];
					}
				}
			}
			cout<<now_team<<" "<<maxAC<<" "<<mintime<<endl;
			team_submission[now_team]=false;
		}
	}
} 

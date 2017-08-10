#include<iostream>
using namespace std;
bool map[50][50];
int num;
void solve(string s,char c,int x1,int y1,int x2,int y2){
	num++;
	if(c=='p'){
		solve(s,s[num],x1,(y1+y2+1)/2,(x1+x2+1)/2,y2);
		solve(s,s[num],x1,y1,(x1+x2+1)/2,(y1+y2+1)/2);
		solve(s,s[num],(x1+x2+1)/2,y1,x2,(y1+y2+1)/2);
		solve(s,s[num],(x1+x2+1)/2,(y1+y2+1)/2,x2,y2);
	}
	else if(c=='f'){
		for(int j=x1;j<x2;j++){
			for(int k=y1;k<y2;k++){
				map[j][k]=true;
			}
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int ans=0;
		for(int i=0;i<50;i++)
			for(int j=0;j<50;j++)
				map[i][j]=false;
		string s1,s2;
		cin>>s1>>s2;
		num=0;
		solve(s1,s1[0],0,0,32,32);
		num=0;
		solve(s2,s2[0],0,0,32,32);
		for(int i=0;i<32;i++){
			for(int j=0;j<32;j++){
				if(map[i][j]){
					ans++;
				}
			}
		}
		cout<<"There are "<<ans<<" black pixels."<<endl;
	}  
}

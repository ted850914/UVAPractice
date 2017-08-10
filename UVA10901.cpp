#include<iostream>
#include<queue>
using namespace std;
int main(){
	int start;
	cin>>start;
	while(start--){
		int n,t,m,ans[10010]={0};
		queue< pair<int,int> > left,right;
		cin>>n>>t>>m;
		for(int i=0;i<m;i++){
			int time;
			string s;
			pair<int,int> p;
			cin>>time>>s;
			p.first=time;
			p.second=i;
			if(s=="left"){
				left.push(p);
			}
			else{
				right.push(p);
			}
		}
		int time=0;
		bool flag=true;	//true is left  false is right
		
		while(!left.empty()||!right.empty()){
			if(!left.empty()&&!right.empty()&&left.front().first>time&&right.front().first>time){
				if(left.front().first<right.front().first){
					time=left.front().first;
				}
				else{
					time=right.front().first;
				}
			}
			else if(left.empty()&&!right.empty()&&right.front().first>time){
				time=right.front().first;
			}
			else if(right.empty()&&!left.empty()&&left.front().first>time){
				time=left.front().first;
			}
			
			if(flag){
				if(left.empty()||(left.front().first>time&&!right.empty()&&right.front().first<left.front().first)){
					time+=t;
					flag=false;
				}
				else{
					int count=0;
					while(!left.empty()&&time>=left.front().first&&count<n){
						count++;
						ans[left.front().second]=time+t;
						left.pop();
					}
					time+=t;
					flag=false;
				}
			}
			else{
				if(right.empty()||(right.front().first>time&&!left.empty()&&left.front().first<right.front().first)){
					time+=t;
					flag=true;
				}
				else{
					int count=0;
					while(!right.empty()&&time>=right.front().first&&count<n){
						count++;
						ans[right.front().second]=time+t;
						right.pop();
					}
					time+=t;
					flag=true;
				}
			}
		}
		
		for(int i=0;i<m;i++){
			cout<<ans[i]<<endl;
		}
		if(start)
			cout<<endl;
	}
}

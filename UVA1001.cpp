#include<iostream>
#include<cmath>
#include<cstring>
#include<iomanip>
#define maxx 9999999
using namespace std;
struct Point{
	int x,y,z,r;
};
int n;
Point point[150];
double cheese[150][150];
double times[150];
bool used[150];
void build_cheese(){
	for(int i=0;i<n+2;i++){
		for(int j=0;j<n+2;j++){
			cheese[i][j]=sqrt((point[i].x-point[j].x)*(point[i].x-point[j].x)+(point[i].y-point[j].y)*(point[i].y-point[j].y)+(point[i].z-point[j].z)*(point[i].z-point[j].z))-(point[i].r+point[j].r);
			if(cheese[i][j]<0)
				cheese[i][j]=0;
		}
	}
}
void dijkstra(int num){
	used[num]=true;
	for(int i=0;i<n+2;i++){
		if(times[i]>times[num]+cheese[num][i])
			times[i]=times[num]+cheese[num][i];
	}
	int minn=maxx,save=-1;
	for(int i=0;i<n+2;i++){
		if(!used[i]&&minn>times[i]){
			minn=times[i];
			save=i;
		}
	}
	if(save!=-1)
		dijkstra(save);
}
int main(){
	int count=0;
	cout<<fixed<<setprecision(0);
	while(cin>>n&&n!=-1){
		count++;
		memset(cheese,0.0,sizeof(cheese));
		memset(times,maxx,sizeof(times));
		memset(used,false,sizeof(used));
		
		for(int i=0;i<n;i++){
			cin>>point[i].x>>point[i].y>>point[i].z>>point[i].r;
		}
		for(int i=n;i<n+2;i++){
			cin>>point[i].x>>point[i].y>>point[i].z;
			point[i].r=0;
		}
		build_cheese();
		times[n]=0;
		dijkstra(n);
		cout<<"Cheese "<<count<<": Travel time = "<<times[n+1]*10<<" sec"<<endl;
	}
}

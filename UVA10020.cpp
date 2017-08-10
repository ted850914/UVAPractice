#include<iostream>
#include<algorithm>
using namespace std;
struct Line{
    int x,y;
}line[100010];
bool comparison(Line a,Line b){
    return a.x<b.x;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int m,num=0;
        cin>>m;
        while(cin>>line[num].x>>line[num].y){
            if(line[num].x==0&&line[num].y==0)
                break;
            num++;
        }
        sort(line,line+num,comparison);
        
        int now_left=0,now_right=0,savex[100010],savey[100010],save=0;
        for(int i=0;i<num;i++){
        	if(line[i].x<=now_left&&line[i].y>now_right){
        		now_right=line[i].y;
        		savex[save]=line[i].x;
        		savey[save]=line[i].y;
			}
			if(line[i+1].x>now_left||i+1==num){
				now_left=now_right;
				save++;
				if(now_right>=m){
					break;
				}
			}
		}
		if(now_right<m)
			cout<<"0"<<endl;
		else{
			cout<<save<<endl;
			for(int i=0;i<save;i++)
				cout<<savex[i]<<" "<<savey[i]<<endl;
		}
		if(t-1>=0)
			cout<<endl;
    }
}

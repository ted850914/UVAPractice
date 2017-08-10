#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n&&n!=0){
		double maxx=0,tmp;
		int w,h,ans;
		for(int i=1;i<=n;i++){
			cin>>w>>h;
			if(w>h)
				swap(w,h);
			tmp=max(w/2.0,min(h/4.0,(double)w));
			if(tmp>maxx){
				maxx=tmp;
				ans=i;
			}
		}
		cout<<ans<<endl;
	}
}

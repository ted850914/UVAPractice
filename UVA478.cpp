#include <iostream>
#include <math.h>
using namespace std;

double triangle(double x1,double y1,double x2,double y2,double x3,double y3){
	if(fabs(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2)==0)
		return 999999999;
	return fabs(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2);
}

int main(){
	struct Shape{
		char name;
		double x1,x2,x3,y1,y2,y3,r;
	};
	char ch;
	Shape shape[100];
	int num=1,ans=1;
	double x,y;
	while(cin>>ch){
		if(ch=='*'){
			break;
		}
		else if(ch=='r'){
			shape[num].name=ch;
			cin>>shape[num].x1>>shape[num].y1>>shape[num].x2>>shape[num].y2;
		}
		else if(ch=='c'){
			shape[num].name=ch;
			cin>>shape[num].x1>>shape[num].y1>>shape[num].r;
		}
		else if(ch=='t'){
			shape[num].name=ch;
			cin>>shape[num].x1>>shape[num].y1>>shape[num].x2>>shape[num].y2>>shape[num].x3>>shape[num].y3;
		}
		num++;
	}
	while(cin>>x>>y){
		bool flag=true;
		if(x==9999.9&&y==9999.9)
			break;
		else{
			for(int i=1;i<num;i++){
				if(shape[i].name=='r'){
					if(shape[i].x1<x&&x<shape[i].x2&&shape[i].y1>y&&y>shape[i].y2){
						cout<<"Point "<<ans<<" is contained in figure "<<i<<endl;
						flag=false;
					}
				}
				else if(shape[i].name=='c'){
					if(sqrt((x-shape[i].x1)*(x-shape[i].x1)+(y-shape[i].y1)*(y-shape[i].y1))<shape[i].r){
						cout<<"Point "<<ans<<" is contained in figure "<<i<<endl;
						flag=false;
					}
				}
				else if(shape[i].name=='t'){
					if((x==shape[i].x1&&y==shape[i].y1)||(x==shape[i].x2&&y==shape[i].y2)||(x==shape[i].x3&&y==shape[i].y3)){
						continue;
					}
					if(fabs(triangle(x,y,shape[i].x2,shape[i].y2,shape[i].x3,shape[i].y3)+triangle(shape[i].x1,shape[i].y1,x,y,shape[i].x3,shape[i].y3)+triangle(shape[i].x1,shape[i].y1,shape[i].x2,shape[i].y2,x,y)-triangle(shape[i].x1,shape[i].y1,shape[i].x2,shape[i].y2,shape[i].x3,shape[i].y3))<0.000001){
						cout<<"Point "<<ans<<" is contained in figure "<<i<<endl;
						flag=false;
					}
				}
			}
			if(flag){
				cout<<"Point "<<ans<<" is not contained in any figure"<<endl;
			}
		}
		ans++;
	}
} 

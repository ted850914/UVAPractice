#include<iostream>
#include<string.h>
using namespace std;
int bcn[15],wcn[15],bcs[4],wcs[4];
char line[50];
int black,white;// 1=烏龍 2=一對 3=兩對 4=三條 5=順子 6=同花 7=葫蘆 8=四條 9=同花順
void in(){
	for(int i=0;i<=14;i++){
		if(line[i]=='T')
			bcn[10]++;
		if(line[i]=='J')
			bcn[11]++;
		if(line[i]=='Q')
			bcn[12]++;
		if(line[i]=='K')
			bcn[13]++;
		if(line[i]=='A')
			bcn[14]++;
		if(line[i]>='2'&&line[i]<='9')
			bcn[line[i]-'0']++;
		
		if(line[i]=='C')
			bcs[0]++;
		if(line[i]=='D')
			bcs[1]++;
		if(line[i]=='H')
			bcs[2]++;
		if(line[i]=='S')
			bcs[3]++;
	}
	for(int i=15;i<=29;i++){
		if(line[i]=='T')
			wcn[10]++;
		if(line[i]=='J')
			wcn[11]++;
		if(line[i]=='Q')
			wcn[12]++;
		if(line[i]=='K')
			wcn[13]++;
		if(line[i]=='A')
			wcn[14]++;
		if(line[i]>='1'&&line[i]<='9')
			wcn[line[i]-'0']++;
		if(line[i]=='C')
			wcs[0]++;
		if(line[i]=='D')
			wcs[1]++;
		if(line[i]=='H')
			wcs[2]++;
		if(line[i]=='S')
			wcs[3]++;
	}
}
void pairup(){
	int pairb=0,pairw=0;
	bool threeb=false,threew=false;
	bool fourb=false,fourw=false;
	for(int i=2;i<15;i++){
		if(bcn[i]==2)
			pairb++;
		if(bcn[i]==3)
			threeb=true;
		if(bcn[i]==4)
			fourb=true;
		if(wcn[i]==2)
			pairw++;
		if(wcn[i]==3)
			threew=true;
		if(wcn[i]==4)
			fourw=true;
	}
	if(pairb==1)
		black=2;
	if(pairb==2)
		black=3;
	if(threeb){
		if(pairb==1)
			black=7;
		else
			black=4;
	}
	if(fourb)
		black=8;
	
	if(pairw==1)
		white=2;
	if(pairw==2)
		white=3;
	if(threew){
		if(pairw==1)
			white=7;
		else
			white=4;
	}
	if(fourw)
		white=8;
}
void straight_flush(){
	for(int i=2;i<15;i++){
		if(bcn[i]){
			if(bcn[i+1]&&bcn[i+2]&&bcn[i+3]&&bcn[i+4]&&i+4<=14)
				black=5;
			break;
		}
	}
	for(int i=2;i<15;i++){
		if(wcn[i]){
			if(wcn[i+1]&&wcn[i+2]&&wcn[i+3]&&wcn[i+4]&&i+4<=14)
				white=5;
			break;
		}
	}
	for(int i=0;i<4;i++){
		if(bcs[i]==5){
			if(black==5)
				black=9;
			else
				black=6;
		}
		if(wcs[i]==5){
			if(white==5)
				white=9;
			else
				white=6;
		}
	}
}
void cmp(){
	if(black>white){
		cout<<"Black wins."<<endl;
	}
	else if(white>black){
		cout<<"White wins."<<endl;
	}
	else{
			int flag=0;
			for(int j=4;j>0;j--){
				for(int i=14;i>=2;i--){
					if(bcn[i]==j||wcn[i]==j){
						if(bcn[i]>wcn[i]){
							flag=1;
							break;
						}
						else if(wcn[i]>bcn[i]){
							flag=2;
							break;
						}
					}
				}
				if(flag==1||flag==2)
					break;
			}
			if(flag==1)
				cout<<"Black wins."<<endl;
			else if(flag==2)
				cout<<"White wins."<<endl;
			else
				cout<<"Tie."<<endl;
	}
}
int main(){
	while(cin.getline(line,50)){
		black=1,white=1;
		memset(bcn,0,sizeof(bcn));
		memset(wcn,0,sizeof(wcn));
		memset(bcs,0,sizeof(bcs));
		memset(wcs,0,sizeof(wcs));
		in();
		pairup();
		straight_flush();
		/*for(int i=2;i<=14;i++)
			cout<<bcn[i]<<" ";
		cout<<endl;
		cout<<black<<" "<<white<<endl;*/
		cmp();
	}
}

#include<iostream>
#include<string.h>
using namespace std;
int main(){
	char s1[90],s2[90];
	int d[90][90];
	while(cin.getline(s1,90)){
		cin.getline(s2,90);
		int s1_l=strlen(s1),s2_l=strlen(s2);
		for(int i=0;i<=s1_l;i++){
			d[i][0]=i;
		}
		for(int i=0;i<=s2_l;i++){
			d[0][i]=i;
		}
		for(int i=1;i<=s1_l;i++){
			for(int j=1;j<=s2_l;j++){
				if(s1[i-1]==s2[j-1]){
					d[i][j]=d[i-1][j-1];
				}
				else{
					d[i][j]=1+min(min(d[i][j-1],d[i-1][j]),d[i-1][j-1]);
				}
			}
		}
		
		cout<<d[s1_l][s2_l]<<endl;
		int times=1;
		while(s1_l!=0||s2_l!=0){
			if(s1_l==0){
				cout<<times<<" Insert "<<s1_l+1<<","<<s2[s2_l-1]<<endl;
				times++;
				s2_l--;
			}
			else if(s2_l==0){
				cout<<times<<" Delete "<<s1_l<<endl;
				times++;
				s1_l--;
			}
			else if(s1[s1_l-1]==s2[s2_l-1]){
				s1_l--;
				s2_l--;
			}
			else if(d[s1_l][s2_l]-1==d[s1_l-1][s2_l-1]){
				cout<<times<<" Replace "<<s1_l<<","<<s2[s2_l-1]<<endl;
				times++;
				s1_l--;
				s2_l--;
			}
			else if(d[s1_l][s2_l]-1==d[s1_l][s2_l-1]){
				cout<<times<<" Insert "<<s1_l+1<<","<<s2[s2_l-1]<<endl;
				times++;
				s2_l--;
			}
			else if(d[s1_l][s2_l]-1==d[s1_l-1][s2_l]){
				cout<<times<<" Delete "<<s1_l<<endl;
				times++;
				s1_l--;
			}
		}
	}
} 

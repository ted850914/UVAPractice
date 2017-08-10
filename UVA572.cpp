#include<stdio.h>                  
#include<stdlib.h>      
char map[102][102],x[100];
void map2(int b,int a,int ans)
{
  if(map[b-1][a]=='@') { map[b-1][a]=ans;map2(b-1,a,ans); }
  if(map[b-1][a-1]=='@') { map[b-1][a]=ans; map2(b-1,a-1,ans); } 
  if(map[b-1][a+1]=='@') { map[b-1][a+1]=ans; map2(b-1,a+1,ans); } 
  if(map[b][a-1]=='@') { map[b][a-1]=ans; map2(b,a-1,ans); } 
  if(map[b][a+1]=='@') { map[b][a+1]=ans; map2(b,a+1,ans); } 
  if(map[b+1][a]=='@') { map[b+1][a]=ans; map2(b+1,a,ans); } 
  if(map[b+1][a-1]=='@') {map[b+1][a-1]=ans; map2(b+1,a-1,ans); } 
  if(map[b+1][a+1]=='@') {map[b+1][a+1]=ans; map2(b+1,a+1,ans); } 
} 
main()      
{      
 int a,b,c,n,m,time=0;
 while(scanf("%d %d ",&n,&m)==2)
  {
   if(n==0&&m==0) break; 
   for(a=0;a<102;a++)
    for(b=0;b<102;b++)
     map[a][b]='*';
   int ans=0;
   for(b=1;b<=n;b++) 
    {
     scanf("%s",x);
     for(a=1;a<=m;a++)
      map[b][a]=x[a-1];
    } 
    
    for(b=1;b<=n;b++)
      for(a=1;a<=m;a++)
        if(map[b][a]=='@')
         { 
          if(map[b-1][a]<0) {map[b][a]= map[b-1][a];continue;}
          if(map[b-1][a-1]<0) { map[b][a]=map[b-1][a-1];continue;} 
          if(map[b-1][a+1]<0) {map[b][a]= map[b-1][a+1] ;continue; } 
          if(map[b][a-1]<0) { map[b][a]=map[b][a-1];continue; } 
          if(map[b][a+1]<0) { map[b][a]=map[b][a+1] ;continue;} 
          if(map[b+1][a]<0) { map[b][a]=map[b+1][a] ;continue; } 
          if(map[b+1][a-1]<0) {map[b][a]=map[b+1][a-1];continue; } 
          if(map[b+1][a+1]<0) {map[b][a]=map[b+1][a+1]  ;continue;} 
          ans--;
          map[b][a]=ans;
          map2(b,a,ans); 
         }
    printf("%d\n",abs(ans));
  } 
 return 0;      
}

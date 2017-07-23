#include<bits/stdc++.h>
using namespace std;
#define MAXX 10000

vector<long long int>pagla;

long long int parent[MAXX];
long long int Size[MAXX];

void makeset(long long int p){
 parent[p]=p;
}

long long int finding(long long int represent){

   if(parent[represent]==represent)
    return represent;
   else
    return parent[represent]=finding(parent[represent]);
}

void Union(long long int a,long long int b){

 long long int u=finding(a);
 long long int v=finding(b);

  if(u==v){
    return;
  }
  else{
    parent[u]=v;
  }
}

void check(long long int l,long long int k){

  long long int g=finding(l);
  pagla.push_back(g);
}

int main()
{
    string ff;
    char ch;
    long long int a,b,s,t,V;

    cin>>t;

    for(V=1; V<=t; V++){

    cin>>ch;
  for(long long int i=1; i<=(ch-64); i++) makeset(i);
   getchar();

  while(1){
  getline(cin,ff);

  long long int x=ff[0]-64;
  long long int y=ff[1]-64;

  if(ff[0]==0){

    for(long long j=1; j<=(ch-64); j++) check(j,j);
    sort(pagla.begin(),pagla.end());

    vector<long long int>:: iterator it;

    it=unique(pagla.begin(),pagla.end());

    pagla.resize(distance(pagla.begin(),it));

    if(V!=1)cout<<endl;
     cout<<pagla.size()<<endl;;

    pagla.clear();
    long long int x=0,y=0;
    break;
  }

  else  Union(x,y);

  }
  }
  return 0;
}

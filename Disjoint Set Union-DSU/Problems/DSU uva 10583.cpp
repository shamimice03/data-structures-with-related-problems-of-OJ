#include<bits/stdc++.h>
using namespace std;
#define MAXX 50001

int parent[MAXX];
int Size[MAXX];

vector<int>pagla;

void makeset(int p){
 parent[p]=p;
 Size[p]=1;
}

int finding(int represent){

   if(parent[represent]==represent)
    return represent;
   else
    return parent[represent]=finding(parent[represent]);
}

void Union(int a,int b){

 int u=finding(a);
 int v=finding(b);

  if(u==v){
    return;
  }
  else{
    parent[u]=v;
  }
}

void check(int l,int k){

  int g=finding(l);
  pagla.push_back(g);
}

int main()
{

    int a,b,s,n,m;

    for(int j=1; ; j++){

    cin>>n>>m;

    if(n==0 && m==0) break;

  for(int i=1; i<=n; i++) makeset(i);

  for(int i=1; i<=m; i++){
    cin>>a>>b;
    Union(a,b);
  }

  for(int i=1; i<=n; i++) check(i,i);


    sort(pagla.begin(),pagla.end());

    vector<int>::iterator it;
    it=unique(pagla.begin(),pagla.end());

    pagla.resize(distance(pagla.begin(),it));

    cout<<"Case "<<j<<":"<<" "<<pagla.size()<<endl;

    pagla.clear();

    }
  return 0;
}

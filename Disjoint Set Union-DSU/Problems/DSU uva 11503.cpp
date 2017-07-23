#include<bits/stdc++.h>
using namespace std;
#define MAXX 1000000

long long int parent[MAXX];
long long int Size[MAXX];


void makeset(long long  int p){
 parent[p]=p;
 Size[p]=1;
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


  if(u!=v){
    parent[u]=v;
    Size[v]+=Size[u];
  }
  cout<<Size[v]<<endl;
}
int main()
{

    long long int i,a,b,s,n,m,t,c=1;
    map<string,long long int>pagla;
    string ff,ll;

    cin>>t;
  while(t--){

    for( i=1; i<=100000; i++)
    makeset(i);
    pagla.clear();

   cin>>n;

  for(i=1; i<=n; i++){
        cin>>ll>>ff;

  if(pagla.find(ff)==pagla.end()) pagla[ff]=c++;
  if(pagla.find(ll)==pagla.end()) pagla[ll]=c++;

  long long int p=pagla[ff];
  long long int q=pagla[ll];
  Union(p,q);

  }

  c=1;
  long long int p=0,q=0;

  }

return 0;
}


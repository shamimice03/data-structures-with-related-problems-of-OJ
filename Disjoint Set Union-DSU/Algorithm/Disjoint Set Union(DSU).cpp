#include<bits/stdc++.h>
using namespace std;
#define MAXX 10000

int parent[MAXX];
int Size[MAXX];

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
    cout<<"Already Friend"<<endl;
    return;
  }
  else{
    parent[u]=v;
    Size[v]+=Size[u];
  }
}

int main()
{

    int a,b,s,e,n;
  for(int i=1; i<=10; i++) makeset(i);
     cin>>e>>n;
  for(int i=1; i<=e; i++){
    cin>>a>>b;
    Union(a,b);
  }

  cin>>s;

  cout<<Size[finding(s)]<<endl;

}

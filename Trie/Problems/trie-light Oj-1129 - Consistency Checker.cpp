#include<bits/stdc++.h>
#define MAX_node 100005
using namespace std;


int node[MAX_node][15];
int root,nnode;
int isWord[MAX_node];



void initialization(){
    root=0;
    nnode=0;
    memset(isWord,0,sizeof(isWord));
    for(int i=0; i<15; i++) node[root][i]=-1;
}

void Insert(string S){

    int len=S.size();
    int now=root;


    for(int i=0; i<len; i++){

        int p=S[i]-48;
        if(node[now][p]==-1){
            node[now][p]=++nnode;
        }

        for(int j=0; j<15; j++) node[nnode][j]=-1;
        now=node[now][p];
    }

    isWord[now]=1;
}


bool Search(string S){

     int len=S.size();
     int now=root;


     for(int i=0; i<len; i++){

        int p=S[i]-48;
        now=node[now][p];

        if(isWord[now]==1 and i < len-1) {return 1;}
     }

     return 0;
}



int main(){

  int test;

  cin>>test;

  for(int t=1; t<=test; t++){
  int n;
  string str;

  initialization();
  vector<string>ss;

  cin>>n;

  while(n--){
    cin>>str;

    Insert(str);
    ss.push_back(str);
  }

  printf("Case %d: ",t);

  int c=0;
  for(int i=0; i<ss.size(); i++){

    if(Search(ss[i])==1){ c=1; cout<<"NO"<<endl; break;}

  }

  if(c==0) cout<<"YES"<<endl;

  }
  return 0;
}



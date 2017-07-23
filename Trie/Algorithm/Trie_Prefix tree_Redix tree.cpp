#include<bits/stdc++.h>
#define MAX_node 1000000
using namespace std;


int node[MAX_node][130];
/* assuming only small letters 'a'-'z '*/
int root,nnode;
int isWord[MAX_node];



void initialization(){
    root=0;
    nnode=0;
    for(int i=0; i<130; i++) node[root][i]=-1;
}

/// Creating Tree ..

void Insert(string S){

    int len=S.size();
    int now=root;

    for(int i=0; i<len; i++){

        if(node[now][S[i]]==-1){
            node[now][S[i]]=++nnode;
        }

        for(int j=0; j<130; j++) node[nnode][j]=-1;
        now=node[now][S[i]];
    }

    isWord[now]=1;
}

///Searching...

bool Search(string S){

     int len=S.size();
     int now=root;
     int check=0;

     for(int i=0; i<len; i++){
        if(node[now][S[i]]==-1){
            check=1;
        }
        now=node[now][S[i]];
     }

     if(check==0 and isWord[now]==1) return 1;
     else return 0;
}



int main(){

  int n;
  string str;

  initialization();

  cin>>n;
  /// Taking Input
  while(n--){
    cin>>str;

    Insert(str);
  }

  int q;
  ///Searching..
  cin>>q;

  while(q--){
    cin>>str;

    if(Search(str)==1) cout<<"FOUND"<<endl;
    else cout<<"NOT FOUND"<<endl;

  }

  return 0;
}

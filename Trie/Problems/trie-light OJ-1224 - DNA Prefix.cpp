#include<bits/stdc++.h>
#define MAX_node 1000000
using namespace std;


int node[MAX_node][4];
int root,nnode;
int isWord[MAX_node];



void initialization(){
    root=0;
    nnode=0;
    memset(isWord,0,sizeof(isWord));
    for(int i=0; i<4; i++) node[root][i]=-1;
}


void Insert(string S){

    int len=S.size();
    int now=root;


    for(int i=0; i<len; i++){

            int p;
            if(S[i]=='A') p=0;
            else if(S[i]=='C') p=1;
            else if(S[i]=='G') p=2;
            else if(S[i]=='T') p=3;

        if(node[now][p]==-1){
            node[now][p]=++nnode;

        }

         isWord[now]++;
        for(int j=0; j<4; j++) node[nnode][j]=-1;
        now=node[now][p];
    }
      isWord[now]++;
}

int mx =0;
bool Search(string S){

     int len=S.size();
     int now=root;
     int check=0;

     for(int i=0; i<len; i++){

            int p;
            if(S[i]=='A') p=0;
            else if(S[i]=='C') p=1;
            else if(S[i]=='G') p=2;
            else if(S[i]=='T') p=3;

//        if(node[now][p]==-1){
//            check=1;
//        }
        now=node[now][p];
        //cout<<"NOW "<<now<<" "<<isWord[now]<<endl;
        int m=(i+1)*isWord[now];
        if(m>mx) mx=m;
     }

     if(check==0 and isWord[now]==1) return 1;
     else return 0;
}



int main(){


  ios_base::sync_with_stdio(false);
  int test;
  cin>>test;
  for(int t=1; t<=test; t++){
  vector<string>ss;
  int n;
  string str;


  initialization();

  cin>>n;

  while(n--){
    cin>>str;

    Insert(str);
    ss.push_back(str);

  }


   for(int i=0; i<ss.size(); i++){


    Search(ss[i]);


  }



  cout<<"Case "<<t<<": ";
  cout<<mx<<endl;
  mx=0;
  ss.clear();
  }
  return 0;
}



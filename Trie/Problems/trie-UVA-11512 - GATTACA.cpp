#include<bits/stdc++.h>
#define MAX_node 1000000
using namespace std;


int node[MAX_node][4];
int root,nnode;
int isWord[MAX_node];
vector<string>pp;
int mi=MAX_node,length=0,mx=0;




void initialization(){
    root=0;
    nnode=0;
    memset(isWord,0,sizeof(isWord));
    for(int i=0; i<4; i++) node[root][i]=-1;
}



void Insert(string S,int j){

    int len=S.size();
    int now=root;

    for(int i=j; i<len; i++){

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


bool Search(string S,int j){

     int len=S.size();
     int now=root;
     int check=0;

     for(int i=j; i<len; i++){

         int p;
         if(S[i]=='A') p=0;
         else if(S[i]=='C') p=1;
         else if(S[i]=='G') p=2;
         else if(S[i]=='T') p=3;

         now=node[now][p];

         if(isWord[now]>=2){ mi=min(mi,isWord[now]); length++;}

     }
}



int main(){
  ios_base::sync_with_stdio(false);
  int n;
  cin>>n;


  while(n--){

   int ans=0,start=0,End=0,SIZE=0;
   vector<char>line,alt,cmp;
   string str;
   cin>>str;


   initialization();




   for(int i=0; i<str.size(); i++)
       Insert(str,i);

   for(int i=0; i<str.size(); i++){

       Search(str,i);



      if(length>SIZE){
        start=mi;
        SIZE=length;
        line.clear();
        for(int j=i; j<i+length; j++){
            line.push_back(str[j]);
        }

      }

      else if(length==SIZE){
          alt.clear();
        for(int j=i; j<i+length; j++){
            alt.push_back(str[j]);
        }
        if(line>=alt) {cmp.clear(); line.clear(); cmp=alt; line=alt;}
      }


      mi=MAX_node;
      length=0;
      }

     if(cmp.size()==0)cout<<"No repetitions found!"<<endl;
     else{
     for(int i=0; i<cmp.size(); i++){

     cout<<cmp[i];
     }
     cout<<" ";
     cout<<start<<endl;

    }
    }

  return 0;
}



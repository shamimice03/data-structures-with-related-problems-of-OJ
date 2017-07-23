#include<bits/stdc++.h>
#define mx 100005
#define mmx 100007
using namespace std;

int arr[mx],start[mx],End[mx];
int tree[mx*4];
map<int,int>mp;

void init(int node,int b,int e){

    if(b == e){
        tree[node]=mp[arr[b]];
        return;
    }
    int left= node*2;
    int right =node*2+1;
    int mid = (b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    if(tree[left]>tree[right]) tree[node]=tree[left];
    else tree[node]=tree[right];
}

int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);

    if(p1>p2) return p1;
    else return p2;
}


int main(){

    int n,t,a,b,q;

    while(scanf("%d",&n)==1){

     if(n==0) break;

     cin>>q;

    for(int i=1; i<=n; i++) {
            scanf("%d",&arr[i]);
            mp[arr[i]]++;
    }

    init(1,1,n);

    int save;
    for(int i=1; i<=n; i++){

        int s= arr[i];
        start[i]=i;
        save=i;

        i++;

        while(arr[i]==s){
            start[i]=save;
            i++;
            if(i>n) break;
        }
        i--;

        for(int j=save; j<=i; j++) End[j]=i;
    }
    int i,j;
    while(q--){

     scanf("%d %d",&i,&j);

     if(i==1 and j==n)
     printf("%d\n",query(1,1,n,i,j));
     else if(i==j) cout<<1<<endl;
     else{
        int ss=start[i];
        int ss1=End[i];

        if(i>=ss and j<=ss1) cout<<(j-i)+1<<endl;
        else{

        int ans1=0;
        int st=start[i];
        int en=End[i];
        if(st<i) ans1=en-i+1;


        int ans2=0;
        int en1=End[j];

        int st2=start[j];

        if(j<en1) ans2=j-st2+1;
         int q=query(1,1,n,i+ans1,j-ans2);
         int ans=max(ans1,ans2);
         printf("%d\n",max(q,ans));
        }


     }


    }

   mp.clear();

}
}




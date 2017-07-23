#include<bits/stdc++.h>
#define int  long long
#define mx 100005
using namespace std;

int  arr[mx];
int  n,q,c=0;

struct info {
    int  prop, sum;
} tree[mx * 4];

void Clear()
{
    for(int  i=1;i<=n*4;i++){
        tree[i].sum = 0;
        tree[i].prop=0;
    }
}

void build(int  node, int  a, int  b)
{
    if (a == b){
        tree[node].sum = arr[a];
        return;
    }
    int  Left = node << 1;
    int  Right = (node << 1) + 1;
    int  mid = (a + b) >> 1;
    build(Left, a, mid);
    build(Right, mid + 1, b);
    tree[node].sum = tree[Left].sum +  tree[Right].sum;

}

void update(int  node, int  a, int  b, int  i, int  j)
{
    if (i > b || j < a)
        return;
    if (a >= i && b <= j)
    {
        tree[node].prop += 1;
        return;
    }
    int  Left = node << 1;
    int  Right = (node << 1) + 1;
    int  mid = (a + b) >> 1;
    update(Left, a, mid, i, j);
    update(Right, mid + 1, b, i, j);
}

int  query(int  node, int  a, int  b, int  i,int  carry = 0)
{
    if (i > b || i < a)
        return 0;

    if (a >= i and b <= i){

      int c=carry+tree[node].prop;
      if(c==0) printf("%d\n",tree[node].sum);
      else if(c%2==0 and c>=2) printf("%d\n",tree[node].sum);
      else{
      if(tree[node].sum==1) printf("0\n");
      else printf("1\n");
       }


    return carry;

    }

    int  Left = node << 1;
    int  Right = (node << 1) + 1;
    int  mid = (a + b) >> 1;

    query(Left, a, mid, i, carry + tree[node].prop);
    query(Right, mid + 1, b, i,carry + tree[node].prop);

}

main()
{
    ios_base::sync_with_stdio(false);
    int  test;
    cin>>test;
    for(int t=1; t<=test; t++){
    string ss;
    cin>>ss;

    for(int i=0; i<ss.size(); i++){
        arr[i+1]=ss[i]-48;
    }

    n=ss.size();

    build(1,1,n);

    cin>>q;
    char ch;
    int a,b;
    printf("Case %d:\n",t);
    for(int i=0; i<q; i++){
      cin>>ch;
      if(ch=='I'){
        cin>>a>>b;
        update(1,1,n,a,b);
      }
      else{
        cin>>a;
        query(1,1,n,a);
      }
    }

    Clear();
    }
}



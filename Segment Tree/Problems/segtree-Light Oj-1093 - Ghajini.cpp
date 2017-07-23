#include<bits/stdc++.h>
#define mx 100005
#define LL long long
#define mmx 100007
using namespace std;

LL  n,q;
LL  arr[mx];
LL  tree[mx*4],tree1[mx*4];

void init(LL  node,LL  b,LL  e){

    if(b == e){
        tree[node]=arr[b];
        return;
    }
    LL  left= node*2;
    LL  right =node*2+1;
    LL  mid = (b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    if(tree[left]>tree[right]) tree[node]=tree[left];
    else tree[node]=tree[right];
}

LL  query(LL  node, LL  b, LL  e, LL  i, LL  j)
{
    if (i > e || j < b)
        return -1;
    if (b >= i && e <= j)
        return tree[node];
    LL  Left = node * 2;
    LL  Right = node * 2 + 1;
    LL  mid = (b + e) / 2;
    LL  p1 = query(Left, b, mid, i, j);
    LL  p2 = query(Right, mid + 1, e, i, j);

    if(p1>p2) return p1;
    else return p2;
}

//minimum

void init2(LL  node,LL  b,LL  e){

    if(b == e){
        tree1[node]=arr[b];
        return;
    }
    LL  left= node*2;
    LL  right =node*2+1;
    LL  mid = (b+e)/2;

    init2(left,b,mid);
    init2(right,mid+1,e);

    if(tree1[left]<tree1[right]) tree1[node]=tree1[left];
    else tree1[node]=tree1[right];
}

LL  query1(LL  node, LL  b, LL  e, LL  i, LL  j)
{
    if (i > e || j < b)
        return mx;
    if (b >= i && e <= j)
        return tree1[node];
    LL  Left = node * 2;
    LL  Right = node * 2 + 1;
    LL  mid = (b + e) / 2;
    LL  p1 = query1(Left, b, mid, i, j);
    LL  p2 = query1(Right, mid + 1, e, i, j);

    if(p1<p2) return p1;
    else return p2;
}


int main()
{
    ios_base::sync_with_stdio(true);
    LL  test;
    cin>>test;

    for(LL  t=1; t<=test; t++){
    cin>>n>>q;

    for(LL  i=1; i<=n; i++) cin>>arr[i];

    init(1,1,n);
    init2(1,1,n);
    LL  ans=0;
    for(LL  i=1; i<=n; i++){
    LL  s,e;
    s=i;
    ans=max(ans,(query(1,1,n,s,q)-query1(1,1,n,s,q)));
    if(q==n) break;
    q++;
    }
    printf("Case %lld: ",t);
    cout<<ans<<endl;

    }

    return 0;
}


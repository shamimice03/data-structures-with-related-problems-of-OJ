#include<bits/stdc++.h>
#define LL long long
#define mx 500005
LL arr[mx];
LL tree[mx * 4];
using namespace std;

void init(LL node, LL b, LL e)
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    LL Left = node * 2;
    LL Right = node * 2 + 1;
    LL mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = tree[Left] + tree[Right];
}

LL query(LL node, LL b, LL e, LL i, LL j)
{
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return tree[node];
    LL Left = node * 2;
    LL Right = node * 2 + 1;
    LL mid = (b + e) / 2;
    LL p1 = query(Left, b, mid, i, j);
    LL p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2;
}

void update(LL node, LL b, LL e, LL i, LL newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        tree[node] += newvalue;
//        cout<<tree[node]<<endl;
        return;
    }
    LL Left = node * 2;
    LL Right = node * 2 + 1;
    LL mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}


void update2(LL node, LL b, LL e, LL i, LL newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        printf("%lld\n",tree[node]);
        tree[node] = newvalue;

        return;
    }
    LL Left = node * 2;
    LL Right = node * 2 + 1;
    LL mid = (b + e) / 2;
    update2(Left, b, mid, i, newvalue);
    update2(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}

int main()
{
    LL n,test,q,c,m,y;
    scanf("%lld",&test);

    for(int t=1; t<=test; t++){
     scanf("%lld %lld",&n,&q);

    for(LL i=1; i<=n; i++) scanf("%lld",&arr[i]);
    init(1, 1, n);

   printf("Case %d:\n",t);
   while(q--){
    scanf("%lld",&c);

    if(c==1){
        scanf("%lld",&m);
        m++;
        //printf("%lld\n",arr[m]);
        update2(1LL,1LL,n,m,0LL);
    }
    else if(c==2){
     scanf("%lld %lld",&m,&y);
     m++;
     update(1LL,1LL,n,m,y);
    }
    else{

        scanf("%lld %lld",&m,&y);
        m++;
        y++;
        printf("%lld\n",query(1LL,1LL,n,m,y));
    }

   }

    }
    return 0;
}


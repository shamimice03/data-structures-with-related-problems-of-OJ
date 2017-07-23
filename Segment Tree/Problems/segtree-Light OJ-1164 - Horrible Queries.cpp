#include<bits/stdc++.h>
#define LL long long
#define mx 100005
using namespace std;

LL arr[mx];
LL n,q;

struct info {
    LL prop, sum;
} tree[mx * 4];

void Clear()
{
    for(LL i=0;i<=n*4;i++){
        tree[i].sum = 0;
        tree[i].prop=0;
    }
}

void build(LL node, LL a, LL b)
{
    if (a == b) {
        tree[node].sum = 0;
        return;
    }
    LL Left = node << 1;
    LL Right = (node << 1) + 1;
    LL mid = (a + b) >> 1;
    build(Left, a, mid);
    build(Right, mid + 1, b);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
}

void update(LL node, LL a, LL b, LL i, LL j, LL value)
{
    if (i > b || j < a)
        return;
    if (a >= i && b <= j)
    {
        tree[node].sum += ((b - a + 1) * value);
        tree[node].prop += value;
        return;
    }
    LL Left = node << 1;
    LL Right = (node << 1) + 1;
    LL mid = (a + b) >> 1;
    update(Left, a, mid, i, j, value);
    update(Right, mid + 1, b, i, j, value);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (b - a + 1) * tree[node].prop;
}

LL query(LL node, LL a, LL b, LL i, LL j, LL carry = 0)
{
    if (i > b || j < a)
        return 0;

    if (a >= i and b <= j)
        return tree[node].sum + carry * (b - a + 1);

    LL Left = node << 1;
    LL Right = (node << 1) + 1;
    LL mid = (a + b) >> 1;

    LL q1 = query(Left, a, mid, i, j, carry + tree[node].prop);
    LL q2 = query(Right, mid + 1, b, i, j, carry + tree[node].prop);

    return q1 + q2;
}

int main()
{

    ios_base::sync_with_stdio(false);
    LL test;
    scanf("%lld",&test);
    for(LL t=1; t<=test; t++){
    scanf("%lld %lld",&n,&q);
    printf("Case %lld:\n",t);
    build(1,1,n);

    for(int i=1;i<=q;i++){
        LL u;
        scanf("%lld",&u);
        if(u==0){
            LL p,q,v;

            scanf("%lld %lld %lld",&p,&q,&v);
             p++;
             q++;
            update(1,1,n,p,q,v);
        }
        if(u==1){
            LL p,q;
            scanf("%lld %lld",&p,&q);
            p++; q++;
            printf("%lld\n",query(1,1,n,p,q));
        }
    }
    Clear();
    }
    return 0;
}


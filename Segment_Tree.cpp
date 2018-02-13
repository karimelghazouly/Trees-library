#include <bits/stdc++.h>
using namespace std;
vector<int>arr;
long long tree[1 << 19];
long long lazy[1 << 19];
struct segment
{
    // i = node index , l = range start , r = range end
    void build( int i , int l , int r)
    {
        lazy[i]=0;
        if(l==r)
        {
            tree[i]=arr[l];
            return ;
        }
        int mid=(l+r)/2;
        build( i * 2 , l , mid);
        build( i *2 +1 , mid+1,r);
        tree[i]=min(tree[i*2],tree[i*2+1]);
    }
    void propagate(int i , int l , int r)
    {
        if(lazy[i]==0)return;

        tree[i]+=lazy[i];
        if(l != r)
        {
            lazy[i*2]+=lazy[i];
            lazy[i*2+1]+=lazy[i];
        }
        lazy[i]=0;

    }
    void update( int i , int l , int r,int a ,int b, int v)
    {
        propagate(i,l,r);
        if( a > r || b < l )return ;
        if(l>=a && r<=b)
        {
            lazy[i]+=v;
            propagate(i,l,r);
            return ;
        }
        int mid=(l+r)/2;
        update( i * 2 , l , mid, a,b, v);
        update( i * 2 + 1 , mid + 1 ,r, a , b , v);
        tree[i]=min(tree[i*2],tree[i*2+1]);
    }
    long long get(int i,int l , int r, int a,int b)
    {
        //cout<<" i = "<<i<<" l = "<<l<<" r = "<<r<<" a = "<<a<<" b = "<<b<<endl;
        propagate(i,l,r);
        if( a > r || b < l)return 1e17;
        if( l >= a && r <=b )return tree[i];
        int mid = (l+r)/2;
        return min(get(i*2,l,mid,a,b),get(i*2+1,mid+1,r,a,b));

    }
};

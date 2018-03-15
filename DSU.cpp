#include "DSU.h"
#include <iostream>
using namespace std;

DSU::DSU()
{
    for(int i=0;i<100009;i++)
    {
        par[i]=i;
        rankk[i]=0;
    }
}
void DSU::connect(int u,int v)
{
    int uroot=get_par(u);
    int vroot=get_par(v);
    if(rankk[uroot]>rankk[vroot])
    {
        swap(uroot,vroot);
        swap(u,v);
    }
    par[uroot]=vroot;
    if(rankk[uroot]==rankk[vroot])rankk[vroot]++;
}
bool DSU::is_connected(int u,int v)
{
    int uroot=get_par(u);
    int vroot=get_par(v);
    return (uroot==vroot);
}
int DSU::get_par(int u)
{
    if(par[u]==u)return u;
    return par[u]=get_par(par[u]);

}
DSU::~DSU()
{

    //dtor
}

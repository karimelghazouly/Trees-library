#include "Min_Heap.h"
#include<bits/stdc++.h>
using namespace std;

Min_Heap::Min_Heap()
{
    for(int i=0;i<1e5;i++)arr[i]=1e9;
    siz=1;
}

int Min_Heap::find_parent(int idx)
{
    return (idx/2);
}

int Min_Heap::get_min()
{
    if(siz==1)return -1;
    return arr[1];
}
void Min_Heap::move_down(int idx)
{
    if(idx>=siz)return;
    if(arr[idx*2]<arr[(idx*2)+1]&&arr[idx*2]<arr[idx])
    {
        swap(arr[idx],arr[idx*2]);
        move_down(idx*2);
    }
    else if(arr[(idx*2)+1]<arr[idx*2]&&arr[(idx*2)+1]<arr[idx])
    {
        swap(arr[idx],arr[(idx*2)+1]);
        move_down((idx*2)+1);
    }
    return;
}

void Min_Heap::move_up(int idx)
{
    if(idx==1)return;
    int p=find_parent(idx);
    if(arr[p]>arr[idx])
    {
        swap(arr[p],arr[idx]);
        move_down(p);
    }
    return;
}

void Min_Heap::insrt(int v)
{
    arr[siz]=v;
    move_up(siz);
    siz++;
}

void Min_Heap::rem()
{
    swap(arr[1],arr[siz-1]);
    arr[siz-1]=1e9;
    siz--;
    move_down(1);
}

Min_Heap::~Min_Heap()
{
    //dtor
}

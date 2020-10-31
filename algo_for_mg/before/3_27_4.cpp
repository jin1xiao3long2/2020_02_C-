#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MID(a,b) (a+((b-a)>>1))

typedef long long LL;

const int N=1e5+5;

struct P_Tree
{
	int n,order[N];
	int valu[20][N],num[20][N];
	LL sum[N],lsum[20][N],isum;
	void init(int len)
	{
		n=len;	sum[0]=0;
		for(int i=0;i<20;i++) valu[i][0]=0,num[i][0]=0,lsum[i][0]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&order[i]);
			valu[0][i]=order[i];
			sum[i]=sum[i-1]+order[i];
		}
		sort(order+1,order+1+n);
		build(1,n,0);
	}

	void build(int lft,int rht,int ind)
	{
		if(lft==rht) return;
		int mid=MID(lft,rht);
		int same=mid-lft+1,ln=lft,rn=mid+1;
		for(int i=lft;i<=rht;i++)
			if(valu[ind][i]<order[mid]) same--;
		for(int i=lft;i<=rht;i++)
		{
			int flag=0;
			if((valu[ind][i]<order[mid])||(valu[ind][i]==order[mid]&&same))
			{
				flag=1;
				valu[ind+1][ln++]=valu[ind][i];
				lsum[ind][i]=lsum[ind][i-1]+valu[ind][i];
				if(valu[ind][i]==order[mid]) same--;
			}
			else 
			{
				valu[ind+1][rn++]=valu[ind][i];
				lsum[ind][i]=lsum[ind][i-1];
			}
			num[ind][i]=num[ind][i-1]+flag;
		}
		build(lft,mid,ind+1);
		build(mid+1,rht,ind+1);
	}
	
    int query(int st,int ed,int k,int lft,int rht,int ind)
	{
		if(lft==rht) return valu[ind][lft];
		int mid=MID(lft,rht);
		int lx=num[ind][st-1]-num[ind][lft-1];
		int ly=num[ind][ed]-num[ind][st-1];
		int rx=st-1-lft+1-lx;
		int ry=ed-st+1-ly;
		if(ly>=k) return query(lft+lx,lft+lx+ly-1,k,lft,mid,ind+1);
		else 
		{
			isum+=lsum[ind][ed]-lsum[ind][st-1];
			st=mid+1+rx;
			ed=mid+1+rx+ry-1;
			return query(st,ed,k-ly,mid+1,rht,ind+1);
		}
	}
}tree;

int main()
{
	int n, k;
    scanf("%d %d", &n, &k);
    tree.init(n);
    int res = tree.query(1, n, n-k+1, 1, n, 0);
	printf("%d\n",res);
	return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void MergeSort(int list1[],int n);
void MergePass(int x[],int y[],int s, int n);
void Merge(int c[],int d[],int l,int m,int r);

void MergeSort(int a[],int n){
        int *b=new int[n];
        int s=1;
        while(s<n){
            MergePass(a,b,s,n);
            s+=s;
            MergePass(b,a,s,n);
            s+=s;
    }
}

void MergePass(int x[],int y[],int s, int n){
    int i=0;
    while(i<=n-2*s){
        Merge(x,y,i,i+s-1,i+2*s-1);
        i=i+2*s;
    }
    if(i+s<n)
    Merge(x,y,i,i+s-1,n-1);
    else 
    {
        for(int j=i;j<=n-1;j++){
            y[j]=x[j];
        }
    }
    
}

void Merge(int c[],int d[],int l,int m,int r){//合并两个分组
    int i=l,j=m+1,k=l;
    while((i<=m)&&(j<=r))
    {
        if(c[i]<=c[j])
        {
            d[k++]=c[i++];
        }
        else
        {
            d[k++]=c[j++];
        }
        
    }
    if(i>m)
        {
            for(int q=j;q<=r;q++)
            {
                d[k++]=c[q];
            }
        }
        else
        {
            for(int q=i;q<=m;q++)
            {
                d[k++]=c[q];
            }
        }

}

int main(){

    int x=0,l=0;
    int save[20];
    vector<vector<int>> v={};
    while(cin>>x){
        save[l]=x;
        vector<int> v1={};
        v.push_back(v1);
        for(int count=0;count<x;count++)
        {
            int y=0;
            cin>>y;
            v[l].push_back(y);
        }
        l++;
    }
    for(int k=0;k<l;k++){
        int n=save[k];
        int size=v[k].size();
        int list[size]={0};
        for(int i=0;i<size;i++)
        {
            list[i]=v[k][i];
        }
        MergeSort(list,n);
        for(int i=0;i<n;i++)
        {
           cout<<list[i]<<" ";
        }
        cout<<endl;
    }  
    return 0;
}
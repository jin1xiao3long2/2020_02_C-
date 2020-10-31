#include<stdio.h>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
struct list{
    int L=0;
    int R=0;
};
bool comp(struct list a,struct list b){
    return a.R<b.R;
}
int main(){
    int count=0;
    //scanf("%d",&count);
    cin>>count;
    int answer[count]={};
    for(int i=0;i<count;i++){
        
        
        //scanf("%d",&n);
        int n=0;
        cin>>n;
        list structs[n];
        for(int j=0;j<n;j++)
        {
            cin>>structs[j].L>>structs[j].R;
            //scanf("%d%d",&structs[j].L,&structs[j].R);
        }
        
        sort(structs,structs+n,comp);
        /*for(int j=0;j<n;j++){
            cout<<structs[j].L<<" "<<structs[j].R<<endl;
        }*/
        int save=structs[0].R;
        //cout<<"answer["<<i<<"]="<<answer[i]<<endl;
        answer[i]=1;
        for(int k=1;k<n;k++){
            if(structs[k].L>=save)
            {
                answer[i]=answer[i]+1;
                save=structs[k].R;
            }
        }
        //cout<<"answer["<<i<<"]="<<answer[i]<<endl;
    }
    for(int i=0;i<count;i++)
    {
        //printf("%d\n",answer[i]);
        cout<<answer[i]<<endl;
    }
    return 0;
}
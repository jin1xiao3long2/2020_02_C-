#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
    int x,y;
}s[120];
bool cmp(node a,node b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int main()
{
    int count=0;
    cin>>count;
    for(int m=0;m<count;m++){
        int n=0,len=0;
        cin>>n>>len;
        //cout<<"n="<<n<<" len="<<len<<endl;
        for(int i=0;i<n;i++)//x代表左区间，y代表右区间
        {
            cin>>s[i].x>>s[i].y;
        }
        sort(s,s+n,cmp);//按左区间大小排序
        //cout<<"paixu:"<<endl;
        //for(i=0;i<n;i++)
        //printf("%d %d\n",s[i].x,s[i].y);//输出排序结果
        int answer=0,save=0;
        int right=s[0].y;
        int left=s[0].x;
        int nowlength=0,max=0,newsave=0,flag=0;
        if(right>=len&&s[0].x==1)//第一段区间直接全覆盖
        {
            answer=1;
            flag=1;
            //cout<<"answer="<<answer<<endl;
        }
        else{
            answer=1;
            save=right;
        }
        if(flag==0)
        {
            for(int i=1;i<n;i++){
                //cout<<"i="<<i<<endl;
                //cout<<"save="<<save<<endl;
                //cout<<"s[i].x="<<s[i].x<<endl;
                //cout<<"s[i].y="<<s[i].y<<endl;
                if(s[i].x<=save+1)//有交集
                {
                    //cout<<"have it"<<endl;
                    nowlength=s[i].y-s[i].x;
                    //cout<<"nowlength="<<nowlength<<endl;
                    if(max<=nowlength)
                    {
                        //cout<<"change!!"<<endl;
                        max=nowlength;
                        //cout<<"max="<<max<<endl;
                        newsave=s[i].y;
                        //cout<<"newsave="<<newsave<<endl;
                    }
                }
                else
                {
                    if(newsave==0)
                    {
                        answer=-1;
                        break;
                    }
                    else
                    {
                        //cout<<"dont have it"<<endl;
                        save=newsave;
                        //cout<<"save="<<save<<endl;
                        max=0;
                        i--;
                        answer++;
                        //cout<<"answer="<<answer<<endl;
                        if(save>=len)
                        {
                            break;
                            //cout<<"break;"<<endl;
                        }
                        newsave=0;
                    }
                }
            }
            if(newsave>=len)
            {
                answer++;
            }
            else{
                answer=-1;
            }
        }
        cout<<answer<<endl;
    }
    return 0;
}

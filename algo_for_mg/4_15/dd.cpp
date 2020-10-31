#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int calculate(vector<int> a);
int main(){
    int n;//有几组数据
    cin>>n;
    int answer[n];
    for(int i=0;i<n;i++)
    {
        int num=0;
        cin>>num;//顾客数
        vector<int> a={};
        for(int k=0;k<num;k++)
        {
            int x;
            cin>>x;//每位顾客等待的时间
            a.push_back(x);
        }
        answer[i]=calculate(a);
    }
    for(int i=0;i<n;i++)
    {
        cout<<answer[i]<<endl;
    }
    return 0;
}
int calculate(vector<int> a)
{
    sort(a.begin(),a.end());
    int count[a.size()]={};
    int answer=0;
    for(int i=1;i<a.size();i++)
    {
        count[i]=count[i-1]+a[i-1];
        answer+=count[i];
    }
    return answer;
}
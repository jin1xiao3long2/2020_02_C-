//A:调度大师丁丁妹
#include <iostream>
using namespace std;
int main(){
    int n=0;
    cin>>n;
    int R[n]={},O[n]={};
    for(int i=0;i<n;i++)
    {
        cin>>R[i];
        cin>>O[i];
    }//输入结束
    int max=0,newmax=0,save=0;
    //遍历数组
    for(int i=0;i<n;i++)
    {
        newmax=save+R[i];
        save=save+O[i];
        if(max<newmax)
        max=newmax;
    }
    cout<<max;
    return 0;
}
#include<stdio.h>   
//int x[5];  
//int c=10;
void package0_1(int w[],int v[],int V,int N)//n代表物品的个数   
{      
    int m[N][V]={0};
    int i, j;
/*********************************最后一个物品单独放置*********************************/      
    for(j = 0; j < V; j++)  	
    {       
        if(j <= w[N-1]) /*背包容量<最后一个物品的重量时*/		   
        m[N-1][j] = 0;          
        else /*背包能够放下最后一个物品时*/        		   
        m[N-1][j] = v[N-1];  	
    }         
/*********************************放置前n-1个物品*********************************/      
    for(i = N-1; i >= 0; i--)
    {
        for(j = 0; j < V; j++) 		
        {           
            if(j <= w[i])                  
            m[i][j] = m[i+1][j];//如果j < w[i]则，当前位置就不能放置，它等于上一个位置的值            
            else //否则，就比较到底是放置之后的值大，还是不放置的值大，选择其中较大者			   
            m[i][j] = m[i+1][j] > m[i+1][j-w[i]]+v[i] ? m[i+1][j] : m[i+1][j-w[i]]+v[i];		
        }
    }
    for(i = 0; i<N; i++)  
    {  
       for(j = 0; j <V; j++)  
       printf("%3d ",m[i][j]);  
       printf("\n");
    }             
    printf("%d",m[0][V-1]);
} 

int main()  {   
    int n=0;
    scanf("%d",&n);//有多少组数据
    for(int k=0;k<n;k++)
    {
        int N=0,V=0;
        scanf("%d %d",&N,&V);//物品数量和背包容量
        int w[N]={0};
        int v[N]={0};
        for(int i=0;i<N;i++)
        {
            scanf("%d",&w[i]);
        }
        for(int i=0;i<N;i++)
        {
            scanf("%d",&v[i]);
        }
        printf("N=%d,V=%d",N,V);
        package0_1(w,v,V,N); 
    }
    
    return 0;  
}  
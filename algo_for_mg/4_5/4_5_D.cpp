#include<stdio.h>
const int MAX_N = 1000000;
int s1[MAX_N]={};
int s2[MAX_N]={};
int lcs[1000][1000]={};

int main(){
    int n=0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d",&s1[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d",&s2[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0;j < n; j++){
            if(i == 0 || j == 0){
                lcs[i][j] = 0;
            }
            if(s1[i] == s2[j]){
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }
            else{
                lcs[i][j] = lcs[i-1][j]>lcs[i][j-1]?lcs[i-1][j]:lcs[i][j-1];
            }
        }
    }
    printf("%d\n",lcs[n-1][n-1]);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ",lcs[i][j]);
        }
        printf("\n");
    }
    return 0;
} 
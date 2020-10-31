#include<bits/stdc++.h>
using namespace std;

int flg,cnt;
int n,m,sx[1000],sy[1000];

void fuck(int start, int time, vis[21][])
{
    
        int j = 3;
        for(int i = 0; i < time; i++)
        {
            while(j--)
            {

                for(int i = 1; i < 21; i++)
                {
                    if(vis[start][i] == 1 && vis[0][i])
                }
            }
        }
}

int main()
{
    int vis[21][21];
    for(int i = 1; i < 21; i++)
        for(int j = 0; j < 21; j++)
            vis[i][j] = 0;
    for(int i = 1; i <21; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        vis[i][a] = vis[i][b] = vis[i][c] = 1;
    }
    int start = 0;
    scanf(%d, &start);
    fuck(start, 20, vis);
    return 0;
}
#include <stdio.h>
#include <vector>







int main()
{
    int time = 0;
    scanf("%d",&time);
    for(int i = 0 ; i < time; i++)
    {
        int master, saber;
        scanf("%d %d", &saber, &master);
        int magic[saber], summon[saber];
        for(int j = 0; j < saber; j++)
        {
            scanf("%d", magic[j]);
        }
        for(int j = 0; j < saber; j++)
        {
            scanf("%d", summon[saber]);
        }
    }
}
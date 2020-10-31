#include <iostream>
#include <stdio.h>

int n, flag = 0;
int primehuan[20], mark[20]; //标记作用;

int isprime(int n) //判断是否为素数
{
    int i, flag = 1;
    if (n == 1)
        return 0;
    for (i = 2; i < n; i++)
        if (n % i == 0)
        {
            flag = 0;
            break;
        }
    return flag;
}

void f(int a)
{
    int i;
    if (a == n) //递归终止条件
    {
        if (isprime(primehuan[n - 1] + 1)) //如果，最后一个数加1为素数，可构成素数环然后输出
        {
            for (i = 0; i < n; i++)
                printf("%d ",primehuan[i]);
            printf("\n");
            flag++;
        }
    }
    else
    {
        for (i = 1; i < n; i++)
        {
            if (mark[i] == 0 && isprime(primehuan[a - 1] + i + 1)) //未标记，且当前数与前一个数相加可构成素数
            {
                mark[i] = 1;
                primehuan[a] = i + 1;
                f(a + 1);
                mark[i] = 0;
            }
        }
    }
}

int main()
{

    int c = 1;
    scanf("%d",&n);
    for(int i = 0; i < 20; i++)
    {
        primehuan[i] = mark[i] = 0;
    }
    primehuan[0] = 1; //素数环起始位置为1
    mark[0] = 1;      //标记数组相应标记
    if (n == 1)       //若n为1，直接输出1即可
        printf("1\n");
    f(1);
    return 0;
}

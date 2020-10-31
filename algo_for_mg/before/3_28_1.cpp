#include <stdio.h>
#include <vector>
#include <iostream>

long count = 0;
    //合并数组A的左半边和右半边元素，并按照非降序序列排列


void mergeArray(std::vector<int> &v, std::vector<int> &lv, std::vector<int> &rv) {
        int len = 0;
        int i = 0;
        int j = 0;
        int lenL = lv.size();
        int lenR = rv.size();
         while(i < lenL && j < lenR) {
             if(lv[i] > rv[j]) {
                 v[len++] = rv[j++]; //将rightA[j]放在leftA[i]元素之前，那么leftA[i]之后lenL - i个元素均大于rightA[j]
                 count += (lenL - i);   //合并之前，leftA中元素是非降序排列，rightA中元素也是非降序排列。所以，此时就新增lenL -　i个逆序对
             } else {
                 v[len++] = lv[i++];
             }
         }
         while(i < lenL)
             v[len++] = lv[i++];
         while(j < lenR)
             v[len++] = rv[j++];

}
    //获取一个随机数数组

//使用归并排序方法计算数组A中的逆序对数
void getReverseCount(std::vector<int> &v) {
    if(v.size() > 1) {
        std::vector<int> lv(v.begin(), v.begin()+v.size()/2); //数组A的左半边元素
        std::vector<int> rv(v.begin()+v.size()/2, v.end());  //数组A的右半边元素
        getReverseCount(lv);
        getReverseCount(rv);
        mergeArray(v, lv, rv);
    }

    
}

int main()
{
    int num = 0;
    while(scanf("%d", &num) != EOF)
    {
        std::vector<int> v;
        for(int i = 0; i < num; i++)
        {
            int n = 0;
            scanf("%d", &n);
            v.push_back(n);
        }
        count = 0;
        getReverseCount(v);
        printf("%ld\n", count);
    }
    return 0;
}
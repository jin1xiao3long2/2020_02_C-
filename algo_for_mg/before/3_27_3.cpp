#include <iostream>
#include <vector>


void insertSort(std::vector<int> &v, int low, int high) {    //插入排序
       for(int i = low + 1; i <= high; i++) {  
           int key = v[i];  
           int j = i - 1;  
           while (j >= low && v[j] > key) {  
               v[j + 1] = v[j];  
               j--;  
           }  
           v[j + 1] = key;  
       }  
}

int partition(std::vector<int> &v,int l,int r,int pivot){   //适用于线性时间选择的partition方法
    int i = l;
    int j = r;
    while(true){
        while(v[i] <= pivot && i < r)
            ++i;   //i一直向后移动，直到出现a[i]>pivot
        while(v[j] > pivot)
            --j;   //j一直向前移动，直到出现a[j]<pivot
        if(i >= j) break;
        std::swap(v[i], v[j]);
    }
    v[l] = v[j];
    v[j] = pivot;
    return j;
}


int select(std::vector<int> &v,int l,int r,int k){
    if(r - l < 100){
        insertSort(v, l, r);    //用快速排序进行排序
        return v[l + k - 1];
    }
    int group = (r - l + 10) / 10;
    for(int i = 0;i<group;i++){
        int left = l + 10 * i;
        int right = (l + i * 10 + 9) > r ? r : l + i * 10 + 9;  //如果超出右边界就用右边界赋值
        int mid = (left+right)/2;
        insertSort(v, left, right);
        std::swap(v[l+i], v[mid]);     // 将各组中位数与前i个 
    }
    int pivot = select(v,l,l+group-1,(group+1)/2);  //找出中位数的中位数
    int p = partition(v,l,r,pivot);    //用中位数的中位数作为基准的位置
    int leftNum = p - l;       //leftNum用来记录基准位置的前边的元素个数
    if (k == leftNum + 1)
        return v[p];
    else if (k <= leftNum)
        return select(v, l, p - 1, k);
    else                    //若k在基准位子的后边，则要从基准位置的后边数起，即第（k - leftNum - 1）个
        return select(v, p + 1, r, k - leftNum - 1);
}


int main(){
    int n = 0, k = 0;
    std::cin >> n >> k;
    std::vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int a = 0;
        std::cin >> a;
        v.push_back(a);
    }
    std::cout << select(v, 0, v.size()-1, v.size()-k+1) << std::endl;
    return 0;
}

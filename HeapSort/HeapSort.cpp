#include<iostream>
#include<vector>
using namespace std;

void adjustHeap(vector<int>& a, int i, int len){
    int maxIndex = i;
    //如果有左子树，且左子树大于父节点，则将最大左指针指向左子树
    if(i * 2 + 1 < len && a[i * 2 + 1] > a[maxIndex])
        maxIndex = i *2 + 1;
    //如果有右子树，且右子树大于父节点和左节点，则将最大左指针指向右子树
    if(i*2+2 < len && a[i*2+2]>a[maxIndex])
        maxIndex = i*2+2;
    //如果父节点不是最大值，则将父节点与最大值交换，并且递归调整与父节点交换的位置
    if(maxIndex != i){
        swap(a[maxIndex],a[i]);
        adjustHeap(a, maxIndex, len);
    }
}

void heapsort(vector<int>& a){
    int len = a.size();
    //1. 构建一个最大堆
    for(int i=len/2-1; i>=0; i--)//从最后一个非叶子节点开始
    {
        adjustHeap(a, i, len);
    }

    //2. 循环将堆首位（最大值）与末位交换，然后再重新调整最大堆，这样得到的是递增序列
    for(int i = len-1; i>0; i--){
        swap(a[0],a[i]);
        adjustHeap(a, 0, i);
    }
}

int main(){
    int s;
    vector<int> a;
    for(int i=0;;i++){
        cin >> s;
        a.push_back(s);
        if(cin.get()=='\n')
            break;
    }

    heapsort(a);

    for(int i:a)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
    
}
#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int> &a){
    int len=a.size();
    for(int i=0; i<len-1; i++){//需要循环次数
        for(int j=0; j<len-1; j++){//每次需要比较的个数
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);//不满足偏序，交换
            }
        }
    }
}

int main(){
    vector<int> a{1,3,23,12,15,3};
    // int s;

    // for(int i=0;; i++){
    //     cin >> s;
    //     a.push_back(s);
    //     if(cin.get()=='\n'){
    //         break; 
    //     }
    // }
    
    bubbleSort(a);

    for(int i=0; i<a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;

    
}

#include<iostream>
#include<vector>
using namespace std;

void insertionsort(vector<int> &a){
    int len = a.size();
    for(int i=0, j, temp; i<len-1; i++){//需要循环次数
        j = i;
        temp = a[i+1]; 
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}


int main(){
    vector<int> a;
    int s;
    for(int i=0;; i++){
        cin >> s;
        a.push_back(s);
        if(cin.get()=='\n'){
            break;
        }
    }

    // insertionsort(a);

    for(int i=0; i<a.size(); i++){
        cout << a[i] << " "; 
    }


}
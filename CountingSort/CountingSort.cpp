#include<iostream>
#include<vector>
using namespace std;

void CountingSort(vector<int>& a){
    int len =  a.size();

    if(len == 0){
         return;
     }

    int Min = a[0], Max = a[0];

    for(int i = 1; i < len;++i){
        Max = max(Max, a[i]);
        Min = min(Min, a[i]);
    }

    int bias = 0-Min;
    vector<int> bucket(Max-Min+1, 0);
    for(int i=0;i<len;++i){
        bucket[a[i]+bias]++;
    }

    int index = 0, i=0;
    while(index<len){
        if(bucket[i]){
            a[index] = i - bias;
            bucket[i]--;
            index++;
        }else{
            i++;
        }
    }
}

int main(){
    int s;
    vector<int> a;

    for(int i=0;;++i){
        cin >> s;
        a.push_back(s);
        if(cin.get()=='\n'){
            break;
        }
    }

    CountingSort(a);

    for(int i:a){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
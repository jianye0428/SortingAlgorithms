#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void BucketSort(vector<int>& a, int bucketSize){
    int len = a.size();
    if(len<2){
        return;
    }
    int Min = a[0], Max = a[0];

    for(int i=1; i<len; i++){
        Max = max(Max, a[i]);
        Min = min(Min, a[i]);
    }

    int bucketCount = (Max - Min)/bucketSize + 1;
    //这个区间是max-min+1，但是为了向上取整，就是+bucketSize-1，和上面的形式一样
    vector<int> bucketArr[bucketCount];
    for(int i=0; i<bucketCount; i++){
        bucketArr[(a[i]-Min)/bucketSize].push_back(a[i]);
    }

    a.clear();

    for(int i=0; i<bucketCount; i++){
        int tlen = bucketArr[i].size();
        //sort(bucketArr[i].begin(),bucketArr[i].end());
        for(int j=0; j<tlen; j++){
            a.push_back(bucketArr[i][j]);
        }
    }
}

int main(){

    int s;
    vector<int> a;
    
    for(int i=0;;++i){
        cin >> s;
        a.push_back(s);
        if(cin.get() == '\n')
            break;
    }


    BucketSort(a,1);

    for(int i:a){
        cout << i << " "; 
    }
    cout << endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

void RadixSort(vector<int>& a){
    int len = a.size();
    if(len<2){
        return;
    }

    int Max = a[0];
    for(int i=1; i<len;++i){
        Max = max(Max, a[i]);
    }

    int maxDigit = log10(Max) + 1;
    int mod = 10, div = 1;

    vector<int> bucketList[10];
    for(int i=0; i<maxDigit; i++, mod *= 10, div *= 10){
        for(int j = 0; j<len; ++j){
            int num = (a[j]%mod)/div;
            bucketList[num].push_back(a[j]);
        }
        int index = 0;
        for(int j = 0; j<10; j++){
            int tlen = bucketList[j].size();
            for(int k=0; k<tlen;k++){
                a[index++] = bucketList[j][k];
            }
            bucketList[j].clear();
        }
    }

}
int main(){
    int s;
    vector<int> a;

    for(int i=0; ; ++i){
        cin >> s;
        a.push_back(s);
        if(cin.get() == '\n'){
            break;
        }
    }

    RadixSort(a);

    for(int i:a){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
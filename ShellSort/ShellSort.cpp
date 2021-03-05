void shellsort(vector<int> &a){
    int len = a.size();
    for(int gap=len/2; gap>0; gap/=2){
        for(int j=i+gap, temp, preIndex;j<len;j = j+gap){
            temp = a[j];
            preIndex = j-gap;
            while(preIndex >= 0 && a[preIndex]>temp){
                a[preIndex+gap] =a[preIndex]; //被替换
                preIndex -= gap;
            }
            a[preIndex+gap] =  temp;//恢复被替换的值 
        }
    }
}
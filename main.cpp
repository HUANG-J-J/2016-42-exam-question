#include <iostream>

int setPartition(int* A,int len);

int main() {
    const int length=10;
    int A[length]={4,1,12,18,7,13,18,16,2,15};
    int difference=setPartition(A,length);
    printf("%d",difference);
    return 0;
}

int setPartition(int* A,int len){
    int pivot,low=0,low0=0,high=len-1,high0=len-1,i=0;
    int sum1=0,sum2=0;
    bool flag=true;
    while(flag){
        pivot=A[low];
        while(low<high){
            while(low<high&&A[high]>=pivot)
                high--;
            A[low]=A[high];
            while(low<high&&A[low]<=pivot)
                low++;
            A[high]=A[low];
        }
        A[low]=pivot;
        if(low==len/2-1){
            flag= false;
        }else if(low<len/2-1){
            low0=++low; //暂存low的位置
            high=high0;
        }else {
            high0 = --high; //暂存high位置
            low = low0;
        }
    }
    while(i<len){
        if(i<len/2){
            sum1+=A[i++];
        }else{
            sum2+=A[i++];
        }
    }
    return sum2-sum1;
}
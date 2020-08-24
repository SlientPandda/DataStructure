#include <iostream>
#define MAXSIZE  50

using namespace std;

struct sqlist
{
    int data[MAXSIZE];
    int length;
};

int main(){

}
void Reverse(sqlist &l){ //逆置 线性2.2
    int temp = 0;
    for (int i = 0; i < l.length / 2;i++){
        temp = l.data[i];
        l.data[i] = l.data[l.length - 1 - i];
        l.data[l.length - 1 - i]=temp;
    }
    
}

void delete_x(sqlist &l,int x){ //删除x 线性2.3
    int k = 0;
    for (int i = 0; i < l.length;i++){
        if(l.data[i]!=x){
            l.data[k] = l.data[i];
            k++;
        }
    }
    l.length = k;
}

bool deletes_t(sqlist &l,int s,int t){     //2.4有序表删除st
    if(s>=t||l.length==0){
        cout << "error";
        return false;
    }
    int i,j;
    for (i = 0; i < l.length&&l.data[i]<s;i++);
    if(i>=l.length)
        return false;
    for (j = i; j < l.length && l.data[j]<=t;j++);
    for (; j < l.length;i++,j++)
        l.data[i] = l.data[j];
    l.length = i;
    return true;
}

bool deletes_t(sqlist &l,int s,int t){  //2.5删除st
    if(s>=t||l.length==0){
        cout << "error";
        return false;
    }
    int k = 0;
    for (int i = 0; i < l.length;i++){
        if (l.data[i]>=s&&l.data[i]<=t)
        {
            k++;
        }
        else
            l.data[i - k] = l.data[i];
    }
    l.length -= k;
    return true;
}

bool delete_duplicate(sqlist &l){ //2.6
    int i, j;
    for (i = 0, j = 1; j < l.length;j++)
        if(l.data[i]!=l.data[j])
            l.data[++i] = l.data[j];
    l.length=i+1;
    return true;
}

bool Merge(sqlist &a,sqlist &b,sqlist &l){//2.7
    int i = 0, j = 0, k = 0;
    while(i<a.length&&j<b.length){
        if(a.data[i]<b.data[j]){
            l.data[k++] = a.data[i++];
        }
        else{
            l.data[k++] = b.data[j++];
        }
    }
    while (i<a.length)
    {
        l.data[k++] = a.data[i++];
    }
    while (j<b.length)
    {
        l.data[k++] = b.data[j++];
    }
    return true;
}

void reverse2(sqlist &l,int left,int right){//2.8
    int temp = 0;
    int mid = (right + left) / 2;
    for (int i = 0; i <=mid-left; i++)
    {
        temp = l.data[left+i];
        l.data[left+i] = l.data[right - i];
        l.data[right - i] = temp;
    }
}
void exchange(sqlist &l,int m,int n)
{
    reverse2(l, 0, l.length - 1);
    reverse2(l, 0, n-1);
    reverse2(l, n, l.length - 1);
}

void binarysearch(sqlist &l,int x){ //2.9折半查找
    int low = 0, high = l.length - 1, mid,temp;
    while(low<=high){
        mid = (low + high) / 2;
        if(l.data[mid]==x)
            break;
        else if(l.data[mid]<x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if(l.data[mid]==x&&mid!=l.length-1){
        temp = l.data[mid];
        l.data[mid] = l.data[mid + 1];
        l.data[mid + 1] = temp;
    }
    if(low>high){
        for (int i = l.length - 1; i > high;i--){
            l.data[i + 1] = l.data[i];
            l.data[i + 1] = x;
        }
    }
        
}

void reverseR(int a[],int left,int right){//2.10R
    int temp,i;
    int mid = (left + right) / 2;
    for (i = 0; i <=mid - left;i++){
        temp = a[left + i];
        a[left+i] = a[right-i];
        a[right-i] = temp;
    }

    
}
void exchangeR(int p)
{

    int n;
    int a[10];
    reverseR(a, 0, p-1);
    reverseR(a, p, n-1);
    reverseR(a, 0, n-1);
}


int minipositiveinteger(int a[],int n){//2.13
    int *b = new int[n];
    int i;
    b[n] = {0};
    for ( i = 0; i < n;i++){
        if(a[i]>0&&a[i]<=n)
            b[a[i] - 1] = 1;
    }
    for ( i = 0; i < n;i++)
    if(b[i]==0)
        break;
    return i + 1;
}


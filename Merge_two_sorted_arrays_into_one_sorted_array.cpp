#include<iostream>
using namespace std;

int main(){
    int a[7]={4,6,8};
    int m=3;

    int b[4]={1,2,5,9};
    int n=4;

    int k=m+n-1;

    int i, j;
    i=m-1;
    j=n-1;

    while(i>=0 && j>=0){
        if(a[i]<b[j]){
            a[k]=b[j];
            k--;
            j--;
        }
        else{ //when a[i]>b[j]
            a[k]=a[i];
            k--;
            i--;
        }
    }

    while(j>=0){// a similar loop for i isnt required as a[k] would already be = a[i]
        a[k]=b[j];
        k--;
        j--;
    }

    for(i=0;i<m+n;i++){
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}

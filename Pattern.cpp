#include<iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    int row;
    row=1;

    int i;
    int a;
    int no;
    a=4*((n-1)/2);

    for(row=1;row<=((n+1)/2);row++){

        for(i=1;i<=a;i++){
            cout << " ";
        }
        a=a-4;

        for(no=row;no>=1;no--){
            cout << no << " ";
        }

        for(i=1;i<=(4*row-6);i++){
            cout << " ";
        }

        if(row>=2){
            for(i=1;i<=row;i++){
                cout << i << " ";
            }
        }

        cout << endl;
    }

    int no1;
    int no2;

    for(row=1;row<=((n-1)/2)-1;row++){

        for(i=1;i<=4*row;i++){
            cout << " ";
        }

        no1=(n-(2*row-1))/2;

        while(no1>=1){
            cout << no1 << " ";
            no1--;
        }

        no2=(2*n + 2*n-3 - ( 1 + 2*(n-2*row) + 8*row)); // ((2*(1 2 3 4) + (spaces bw the pair of 1 2 3 4) - (extra space by previous loop + pair of (3 2 1) + pair of spaces before and after 3 2 1))

        while(no2>=1){
            cout << " ";
            no2--;
        }

        i=1;
        while(i<=((n-(2*row-1))/2)){
            cout << i << " ";
            i++;
        }

        cout << endl;
    }


    if(n>1){
        for(i=1;i<=2*(n-1);i++){
            cout << " ";
        }

        cout << "1";
    }
}

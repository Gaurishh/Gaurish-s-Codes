#include<iostream>
using namespace std;

void pattern(int n){

    int i;
    int row;

    for(i=1;i<=2*n-1;i++){
        cout << "*";
    }
//

    cout << endl;

    for(row=1;row<=n-1;row++){

        for(i=1;i<=n-row;i++){
            cout << "*";
        }

        for(i=1;i<=2*row-1;i++){
            cout << " ";
        }

        for(i=1;i<=n-row;i++){
            cout << "*";
        }
        cout << endl;
    }

    int a;
    for(row=1;row<=n-2;row++){

        for(i=1;i<=row+1;i++){
            cout << "*";
        }

        a=n-(row+1);

        for(i=1;i<=2*a-1;i++){
            cout << " ";
        }

        for(i=1;i<=row+1;i++){
            cout << "*";
        }

        cout << endl;
    }

    for(i=1;i<=2*n-1;i++){
        cout << "*";
    }

}

int main(){

    int n;
    cin >> n;

    pattern(n);

}

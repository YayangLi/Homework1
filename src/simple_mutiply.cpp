#include<iostream>
using namespace std;

int* transferBinary(int x){

    int* binaryArray = new int[32];

    for(int i = 31; i >= 0; i--){
        int bit = (x>>i)&1;
        binaryArray[i] = bit;
    }
    return binaryArray;
}

int multiple(int *a, int b){
    int result = 0;
    for(int i = 31; i >= 0; i--){
        if(a[i] == 1){
            result += (b<<i);
        }
    }

    return result;
}

int main(int argc, char* argv[]){
    int m1, m2, i;
    cout<<"Please input the first number:"<<endl;
    cin>>m1;
    cout<<"Please input the second number:"<<endl;
    cin>>m2;

    int *a;
    a = transferBinary(m1);

    for(i = 31; i >= 0; i --){
        cout<<a[i];
        if(i % 4 == 0)
            cout<<' ';
    }
    cout<<endl;

    int result = multiple(a,m2);
    cout<<m1<<'*'<<m2<<'='<<result<<endl;
    return 0;
}

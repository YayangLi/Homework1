#include<iostream>
#include<stdlib.h>
using namespace std;

int binaryGCD(int a, int b){

    int k = 0;
    a = abs(a), b = abs(b);

    if(a ==0 || b == 0)
        return a + b;

    if(a == b)
        return a;

    while(((a & 1) | (b & 1)) == 0){
        k ++;
        a = a >> 1;
        b = b >> 1;
    }

    while(a != 0){

        while((a & 1) == 0)
            a = a >> 1;

        if(b > a){
            int temp = b;
            b = a;
            a = temp;
        }
        a = a - b;
    }

    return b * (1 << k);

}

int main(){

    int a , b, result;

    cout<<"Please input the first number:"<<endl;
    cin>>a;
    cout<<"Please input the second number:"<<endl;
    cin>>b;

    result = binaryGCD(a, b);
    cout<<"GCD is:"<<result<<endl;

}

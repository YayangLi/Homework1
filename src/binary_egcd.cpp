#include<iostream>
#include<cmath>
using namespace std;

int* extendBinaryGCD(int a, int b){

    int* resultArray = new int[3];

    int r0, r1, s0, s1, k;
    r0 = 1, r1 = 0, s0 = 0, s1 = 1, k = 0;

    if(a == 0){
        resultArray[0] = 0;
        resultArray[1] = 1;
        resultArray[2] = b;

        return resultArray;
    }

    if(b == 0){
        resultArray[0] = 1;
        resultArray[1] = 0;
        resultArray[2] = a;

        return resultArray;
    }

    if(a == b){
        resultArray[0] = 1;
        resultArray[1] = 0;
        resultArray[2] = a;

        return resultArray;
    }

    while(((a % 2 ) == 0) &&(((b % 2)) == 0)){

        a = a / 2;
        b = b / 2;
        k ++;
    }
    int alpha, beta;
    alpha = a, beta = b;

    while((a % 2) == 0){

        a = a / 2;

    }

    if((r0 % 2 == 0) && (r1 % 2 == 0))

        r0 = r0 / 2, r1 = r1 / 2;

    else

        r0 = (r0 + beta) / 2, s0 = (s0 - alpha) / 2;

    while(a != b){

        if(b % 2 == 0){

            b = b / 2;
            if((s0 % 2 == 0) && (s1 % 2 == 0))

                s0 = s0 / 2, s1 = s1 / 2;

            else

                s0 = (s0 + beta) / 2, s1 = (s1 - alpha) / 2;

        }
        else if(b < a){

            int temp1, temp2;
            temp1 = b, b = a, a = temp1;  //swap a,b

            temp1 = r0, temp2 = r1;

            r0 = s0, r1 = s1, s0 = temp1, s1 = temp2;     //swap uvst


        }
        else{
            b = b - a;
            s0 = s0 - r0;
            s1 = s1 - r1;
        }

    }

    resultArray[0] = s0;
    resultArray[1] = s1;
    resultArray[2] = a * pow(2, k);

    return resultArray;
}

int main(){

    int a , b, *result;

    cout<<"Please input the first number:"<<endl;
    cin>>a;
    cout<<"Please input the second number:"<<endl;
    cin>>b;

    result = extendBinaryGCD(a, b);
    //cout<<"s0:"<<result[0]<<" ,s1:"<<result[1]<<endl;
    cout<<"GCD is:"<<result[2]<<endl;
}

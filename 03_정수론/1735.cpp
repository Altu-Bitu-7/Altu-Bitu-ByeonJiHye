#include <iostream>
#include <algorithm>

using namespace std;

// 최대공약수 계산 함수
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//분수 합을 구하는 함수
void add_and_reduce_fractions(int a1, int b1, int a2, int b2, int &numerator, int &denominator) {
    // 공통 분모를 사용하여 두 분수의 합 계산
    numerator = a1 * b2 + a2 * b1; 
    denominator = b1 * b2;      
    
    //분자와 분모의 최대공약수 계산
    int gcd_value = gcd(numerator, denominator);
    
    //최대공약수로 분자와 분모를 나누어 기약분수로 변환
    numerator /= gcd_value;
    denominator /= gcd_value;
}

int main() {
    int a1, b1, a2, b2;
    
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    
    int numerator, denominator;
    
    //분수 합을 계산하고 기약분수로 변환
    add_and_reduce_fractions(a1, b1, a2, b2, numerator, denominator);

    cout << numerator << " " << denominator << endl;
    
    return 0;
}

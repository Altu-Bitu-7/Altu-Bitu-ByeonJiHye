#include <iostream>
#include <vector>

using namespace std;

int solution(int n){
    for (int i=1; i<n;i++){
        int sum = i;
        int tmp = i;

        while (tmp){
            sum += tmp % 10;
            tmp /= 10;
        }

        if (sum == n) {
            return i;
        }
    }
    return 0;
}

int main(){
    //입력
    int n;
    cin >> n;

    //연산
    solution(n);

    //출력
     cout << solution(n);
}
#include <iostream>

using namespace std;
typedef long long ll;

const int MAX = 60;
//10^ 3 = 1000 / 2^10 = 1024
//10^18 ~ 2^60

pair<int,int> solution(ll m){
    //1) m이 2의 제곱수인 경우
    //m을 2진수로 표현했을 때 1이 한 개인 경우
    //10000
    //00001 00010 00100 01000 10000
    for (int i =0; i<MAX; i++){
        //m이 2의 제곱수인지 확인
        if (m==((ll)1 << i)){
            return { i-1, i-1};
        }
    }

    //2) m이 2의 제곱수가 아닌 경우
    //m을 2진수로 표현했을 때 1이 2개
    //1010
    //0001 0010 0100 1000
    //and 연산을 했을 때 1이 나오는 값이 우리가 찾는 1이 있는 위치이다!!
    int x, y;
    for (x=0; x<MAX; x++){
        if ( m& ((ll)1 << x)){
            m -= ((ll)1 << x);
            break;
        }
    }

        for (y=0; y<MAX; y++){
        if ( m& ((ll)1 << y)){
            break;
        }
    }


}

int main() {
    //입력
    int n;
    ll m;
    cin >> n;

    while (n--) {
        cin >> m;
    }
    pair<int,int> answer = solution(m);

        //출력
        cout << answer.first << ' ' << answer.second << endl;
    return 0;
}

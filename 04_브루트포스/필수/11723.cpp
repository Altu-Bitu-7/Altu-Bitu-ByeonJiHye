#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);  //입출력 속도 향상
    cin.tie(0);  //입출력 비동기화 해제
    
    int m, s = 0;  //s는 비트마스크로 사용
    cin >> m;

    while (m--) {
        string command;
        int x;
        cin >> command;

        if (command == "add") {
            cin >> x;
            s |= (1 << (x - 1));  //x번째 비트를 1로 설정
        } else if (command == "remove") {
            cin >> x;
            s &= ~(1 << (x - 1));  //x번째 비트를 0으로 설정
        } else if (command == "check") {
            cin >> x;
            cout << ((s & (1 << (x - 1))) ? 1 : 0) << '\n';  //x번째 비트가 1이면 1, 아니면 0
        } else if (command == "toggle") {
            cin >> x;
            s ^= (1 << (x - 1));  //x번째 비트를 반전
        } else if (command == "all") {
            s = (1 << 20) - 1;  //모든 비트를 1로 설정
        } else if (command == "empty") {
            s = 0;  //모든 비트를 0으로 설정
        }
    }

    return 0;
}

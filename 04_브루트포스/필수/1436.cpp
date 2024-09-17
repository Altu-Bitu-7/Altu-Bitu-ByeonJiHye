#include <iostream>
#include <string>

using namespace std;

bool isEndnumber(int num) {
    //숫자를 문자열로 변환 후 "666"이 포함되어 있는지 확인
    return to_string(num).find("666") != string::npos;
}

int findEndnumber(int n) {
    int count = 0;
    int number = 666;  //첫 번째 종말의 수는 666

    //n번째 종말의 수를 찾을 때까지 반복
    while (true) {
        if (isEndnumber(number)) {  //666이 포함된 숫자인지 확인
            count++;
        }

        //n번째 종말의 수를 찾으면 반환
        if (count == n) {
            return number;
        }

        number++;  //다음 숫자로 넘어가기
    }
}

int main() {
    int n;
    cin >> n;

    //N번째 종말의 수를 찾고 출력
    cout << findEndnumber(n) << endl;

    return 0;
}

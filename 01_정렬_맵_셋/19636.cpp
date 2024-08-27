#include <iostream>
#include <map>
#include <cmath>
using namespace std;

// 다이어트 체계 순서
//  체중 += 에너지 섭취량 - (기초 대사량  + 활동 대사량 )
// | (기초 대사량 + 활동 대사량) | > T ➡️ T = 체중 /2 의 정수값

// 데시가 죽는 경우
// 체중 <= 0 or 기초 대사량 <= 0

// 구해야 할 것 (출력값)
// 1. 기초 대사량 안 변했을 때의 예상 체중 & 일일 기초 대사량 or Danger Diet
// 2-1. 기초 대사량 변했을 때의 예상 체중 & 일일 기초 대사량
// 2-2. 요요 현상 여부


map<string, int> diet(int w0, int i0, int i, int a, int d, int t) {
    int w1 = w0, m1 = i0; // 기초대사량 변화 고려 X
    int w2 = w0, m2 = i0; // 기초대사량 변화 고려 O
    map<string, int> result;

    for (int k = 0; k<d; k++) {
        w1 += i - (m1 + a);
        w2 += i - (m2 + a);

        if (abs(i - (m2 + a)) > t) {
            m2 += float(i - (m2 + a)) / 2.0;
        }

    }

    //결과값 map에 저장
    result["w1"] = w1;
    result["w2"] = w2;
    result["m2"] = m2;

    return result;
}

int main() {
    int w0, i0, t;
    int d, i, a;

    cin >> w0 >> i0 >> t;
    cin >> d >> i >> a;

    map<string, int> results = diet(w0, i0, i, a, d, t);

    int w1 = results["w1"], m1 = i0; 
    int w2 = results["w2"], m2 = results["m2"];

    //첫째줄 출력값
    if (w1 <= 0) {
        cout << "Danger Diet\n";
    } else {
        cout << w1 << " " << m1 << "\n";
    }
    //둘째줄 출력값
    if (w2 <= 0 || m2 <= 0) {
        cout << "Danger Diet";
    } else {
        cout << w2 << " " << m2 << " ";
        if (m2 < i0) {
            cout << "YOYO";
        } else {
            cout << "NO";
        }
    }
    return 0;

}
#include <iostream>
#include <vector>

using namespace std;

//최소 속도 계산 함수
long long calcMinSpeed(const vector<long long>& v) {
    long long minV = 0;

    for (long long speed : v) {
        if (speed > minV) {  //최소 속도보다 클 때
            minV = speed;    //최소 속도 갱신
        } else {
            minV = ((minV - 1) / speed + 1) * speed;  //최소 속도보다 큰 speed의 배수 중 가장 작은 값을 대입
        }
    }

    return minV;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n; //행성 개수

    vector<long long> v(n);

    //입력 (거꾸로 받음)
    for (int i = n - 1; i >= 0; i--) {
        cin >> v[i];
    }

    //최소 속도 계산
    long long result = calcMinSpeed(v);

    cout << result << endl;
}

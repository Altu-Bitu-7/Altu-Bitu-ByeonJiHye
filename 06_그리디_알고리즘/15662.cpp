#include <iostream>
#include <vector>
#include <string>

using namespace std;

//톱니바퀴 회전 함수 (시계방향: 1, 반시계방향: -1)
void rotateWheel(vector<int>& wheel, int direction) {
    if (direction == 1) {  //시계 방향 회전
        int temp = wheel[7];
        for (int i = 7; i > 0; --i)
            wheel[i] = wheel[i - 1];
        wheel[0] = temp;
    } else if (direction == -1) {  //반시계 방향 회전
        int temp = wheel[0];
        for (int i = 0; i < 7; ++i)
            wheel[i] = wheel[i + 1];
        wheel[7] = temp;
    }
}

//톱니바퀴의 상태에 따라 인접한 톱니바퀴의 회전 여부 결정
void decideRotation(vector<vector<int>>& wheels, int wheelIndex, int direction, vector<int>& rotations) {
    int t = wheels.size();

    //회전 방향 저장
    rotations[wheelIndex] = direction;

    //왼쪽 톱니바퀴 확인
    for (int i = wheelIndex; i > 0; --i) {
        if (rotations[i] == 0) break;  //회전하지 않으면 멈춤
        if (wheels[i][6] != wheels[i - 1][2])  //극이 다르면 반대 방향 회전
            rotations[i - 1] = -rotations[i];
        else break;
    }

    //오른쪽 톱니바퀴 확인
    for (int i = wheelIndex; i < t - 1; ++i) {
        if (rotations[i] == 0) break;
        if (wheels[i][2] != wheels[i + 1][6])  //극이 다르면 반대 방향 회전
            rotations[i + 1] = -rotations[i];
        else break;
    }
}

int main() {
    int t, k;  //톱니바퀴의 개수와 회전 횟수
    cin >> t;

    vector<vector<int>> wheels(t, vector<int>(8));  //톱니바퀴 저장

    //톱니바퀴 상태 입력
    for (int i = 0; i < t; ++i) {
        string state;
        cin >> state;
        for (int j = 0; j < 8; ++j) {
            wheels[i][j] = state[j] - '0';  // N극은 0, S극은 1로 저장
        }
    }

    cin >> k;  //회전 횟수

    //회전 명령 입력 및 처리
    for (int i = 0; i < k; ++i) {
        int wheelIndex, direction;
        cin >> wheelIndex >> direction;
        wheelIndex -= 1;  //0-based index로 변환

        vector<int> rotations(t, 0);  //각 톱니바퀴의 회전 방향 저장
        decideRotation(wheels, wheelIndex, direction, rotations);

        //모든 톱니바퀴 회전
        for (int j = 0; j < t; ++j) {
            if (rotations[j] != 0)
                rotateWheel(wheels[j], rotations[j]);
        }
    }

    //12시 방향이 S극인 톱니바퀴의 개수 출력
    int result = 0;
    for (int i = 0; i < t; ++i) {
        if (wheels[i][0] == 1)  //12시 방향이 S극인지 확인
            result++;
    }

    cout << result << endl;

    return 0;
}

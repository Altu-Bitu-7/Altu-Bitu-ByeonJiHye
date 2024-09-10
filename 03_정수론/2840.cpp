#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, char> Operation;
const int ALPHABET_COUNT = 26;

//시계방향으로 바퀴의 상태를 문자열 반환 함수
string getWheelState(int n, int start_index, const vector<char>& wheel) {
    string state = "";
    for (int i = start_index + n; i > start_index; i--) {
		state += wheel[i % n];
	}
    return state;
}

//행운의 바퀴를 만드는 함수
string bulidWheel(int n, int k, const vector<Operation>& operations) {
    vector<char> wheel(n, '?');  // 바퀴의 모든 칸을 '?'로 초기화
    vector<bool> used_letters(ALPHABET_COUNT, false);  // 알파벳 사용 여부 체크

    int current_position = 0;  //현재 화살표가 가리키는 위치

    for (const auto& op : operations) {
        int steps = op.first;  
        char letter = op.second;  

        //바퀴를 시계방향으로 회전
        current_position = (current_position + steps) % n;

        //현재 위치가 이미 다른 문자로 채워져 있거나 해당 문자가 이미 사용된 경우
        if (wheel[current_position] != '?' && wheel[current_position] != letter) {
            return "!";
        }
        if (wheel[current_position] == '?' && used_letters[letter - 'A']) {
            return "!";
        }

        wheel[current_position] = letter;
        used_letters[letter - 'A'] = true;
    }

    //최종 상태를 시계방향으로 출력
    return getWheelState(n, current_position, wheel);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<Operation> operations(k);
    for (int i = 0; i < k; ++i) {
        cin >> operations[i].first >> operations[i].second;
    }

    cout << bulidWheel(n, k, operations) << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

//팰린드롬을 만들 수 있는지 판단하는 함수
bool canMakePalindrome(const string& name, char& oddChar) {
    vector<int> freq(26, 0); //알파벳 빈도 수 저장
    for (char c : name) {
        freq[c - 'A']++; //각 알파벳의 빈도 증가
    }

    int oddCount = 0; //홀수 개수의 알파벳 카운트
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) { //홀수 빈도인 알파벳
            oddCount++;
            oddChar = i + 'A'; //홀수인 알파벳 저장
        }
    }

    //홀수 빈도의 문자가 2개 이상이면 팰린드롬 불가능
    return oddCount <= 1;
}

//팰린드롬 생성 함수
string createPalindrome(const string& name, char oddChar) {
    vector<int> freq(26, 0); //알파벳 빈도 수 저장
    for (char c : name) {
        freq[c - 'A']++; //각 알파벳의 빈도 증가
    }

    string firstHalf = ""; //팰린드롬의 절반
    string secondHalf = ""; //팰린드롬의 두번째 절반 (firstHalf의 역순이 될 예정)
    
    //알파벳 순서대로 짝수 빈도 문자를 팰린드롬의 양 끝에 추가
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            firstHalf += string(freq[i] / 2, i + 'A'); //절반만큼 추가
        }
    }

    secondHalf = firstHalf; //두번째 절반은 첫번째 절반의 역순
    reverse(secondHalf.begin(), secondHalf.end());

    //홀수 빈도의 문자가 있으면 중간에 추가
    if (oddChar != 0) {
        return firstHalf + oddChar + secondHalf;
    } else {
        return firstHalf + secondHalf;
    }
}

int main() {
    string name;
    cin >> name;

    char oddChar = 0; //홀수 빈도의 알파벳을 저장할 변수
    if (canMakePalindrome(name, oddChar)) {
        //팰린드롬을 만들 수 있을 경우
        string result = createPalindrome(name, oddChar);
        cout << result << endl;
    } else {
        //팰린드롬을 만들 수 없을 경우
        cout << "I'm Sorry Hansoo" << endl;
    }

    return 0;
}

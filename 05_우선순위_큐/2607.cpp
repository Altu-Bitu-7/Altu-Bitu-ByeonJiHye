#include <iostream>
#include <vector>

using namespace std;
const int ALPHA_SIZE = 26; 

//단어의 알파벳 빈도를 계산
void calcFreq(const string &word, vector<int> &freq) {
    for (char c : word) {
        freq[c - 'A']++;  //해당 알파벳에 대한 빈도 증가
    }
}

//알파벳 빈도 차이를 계산
int getDiff(const string &word, const vector<int> &orig_freq) {
    vector<int> freq(ALPHA_SIZE, 0);
    int diff = 0;

    calcFreq(word, freq);

    //각 알파벳의 빈도 차이를 누적
    for (int i = 0; i < ALPHA_SIZE; i++) {
        diff += abs(orig_freq[i] - freq[i]);
    }

    return diff;
}

int main() {
    int n, similar_count = 0;
    string original;

    cin >> n >> original;

    //원본 단어의 알파벳 빈도를 저장
    vector<int> orig_freq(ALPHA_SIZE, 0);
    calcFreq(original, orig_freq);

    //나머지 단어들과 비교
    for (int i = 1; i < n; i++) {
        string word;
        cin >> word;

        //현재 단어와 원본 단어의 빈도 차이 계산
        int diff = getDiff(word, orig_freq);

        //비슷한 단어를 판별
        if (diff == 0 || diff == 1 || (diff == 2 && original.length() == word.length())) {
            similar_count++;
        }
    }

    cout << similar_count << endl;

    return 0;
}

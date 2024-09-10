#include <iostream>
#include <string>
using namespace std;

//체스판 범위 내에 있는지 확인하는 함수
bool isBounded(char col, int row) {
    return col >= 'A' && col <= 'H' && row >= 1 && row <= 8;
}

//좌표 이동 함수
void move(char &col, int &row, const string &direction) {
    if (direction == "R") {
        col += 1;   
    } else if (direction == "L") {
        col -= 1;  
    } else if (direction == "B") {
        row -= 1;    
    } else if (direction == "T") {
        row += 1;    
    } else if (direction == "RT") {
        row += 1;    
        col += 1;   
    } else if (direction == "LT") {
        row += 1;    
        col -= 1;   
    } else if (direction == "RB") {
        row -= 1;    
        col += 1;   
    } else if (direction == "LB") {
        row -= 1;    
        col -= 1;   
    }
}

int main() {
    string k_pos, s_pos;
    int n;

    //입력
    cin >> k_pos >> s_pos >> n;

    //k와 s의 좌표
    char k_col = k_pos[0];
    int k_row = k_pos[1] - '0';
    char s_col = s_pos[0];
    int s_row = s_pos[1] - '0';

    //n번의 이동에 대한 처리
    for (int i = 0; i < n; ++i) {
        string move_dir;
        cin >> move_dir;

        char next_k_col = k_col;
        int next_k_row = k_row;
        move(next_k_col, next_k_row, move_dir);

        //k가 이동할 좌표가 유효한지 확인
        if (isBounded(next_k_col, next_k_row)) {
            //k가 이동할 위치에 s가 있는 경우, s도 같은 방향으로 이동해야 함
            if (next_k_col == s_col && next_k_row == s_row) {
                char next_s_col = s_col;
                int next_s_row = s_row;
                move(next_s_col, next_s_row, move_dir);

                //s의 이동 위치도 유효한 경우에만 s와 k를 함께 이동
                if (isBounded(next_s_col, next_s_row)) {
                    k_col = next_k_col;
                    k_row = next_k_row;
                    s_col = next_s_col;
                    s_row = next_s_row;
                }
            } else {
                //s가 없으면 k만 이동
                k_col = next_k_col;
                k_row = next_k_row;
            }
        }
    }

    //출력
    cout << k_col << k_row << '\n';
    cout << s_col << s_row << '\n';

    return 0;
}

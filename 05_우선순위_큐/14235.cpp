#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//최대 힙을 이용해 선물 관리
priority_queue<int> gifts;

//거점지에서 선물 충전
void addGifts(const vector<int>& new_gifts) {
    for (int gift : new_gifts) {
        gifts.push(gift); //선물의 가치를 최대 힙에 추가
    }
}

//아이에게 선물 전달
int giveGift() {
    if (gifts.empty()) {
        return -1; //줄 선물이 없으면 -1 반환
    }
    int best_gift = gifts.top();
    gifts.pop(); //가장 큰 가치를 가진 선물을 제거
    return best_gift;
}

int main() {
    int n;
    cin >> n; //아이들과 거점지 방문 횟수

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;

        if (a == 0) {
            //아이를 만난 경우
            cout << giveGift() << '\n'; 
        } else {
            //거점지에서 선물 충전
            vector<int> new_gifts(a);
            for (int j = 0; j < a; ++j) {
                cin >> new_gifts[j];
            }
            addGifts(new_gifts);
        }
    }

    return 0;
}

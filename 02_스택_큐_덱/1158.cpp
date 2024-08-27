#include <iostream>
#include <queue>
#include <vector>

std::vector<int> josephus(int n, int k) {
    std::queue<int> q;
    std::vector<int> result;

    //큐에 1부터 n까지 입력
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        for (int i = 0; i < k - 1; i++) {
            q.push(q.front()); //제일 앞에 있는 원소를 뒤에 추가
            q.pop(); //새로 추가한 원소를 삭제함으로써 중복 방지
        }
        result.push_back(q.front());
        q.pop();
        // k번째 원소를 큐에서 빼고 결과에 추가
    }

    return result;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> result = josephus(n, k);

    std::cout << "<";
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i != result.size() - 1) { // 마지막 요소가 아니라면 ,와 공백을 출력
            std::cout << ", ";
        }
    }
    std::cout << ">" << std::endl;

    return 0;
}

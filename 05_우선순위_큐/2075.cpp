#include <iostream>
#include <queue>

using namespace std;

/*
n개 이상일 때 가장 작은 값을 삭제할 수 있는 구조여야 함
-> 가장 큰 값, 가장 작은 값을 빠르게 찾고 삭제할 수 있는 최소힙 사용
-> 입력을 최소힙에 push하고 힙의 사이즈가 n보다 크다면 top값을 제거
*/

int main() {
	ios::sync_with_stdio(false);
    //성능 최적화
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	priority_queue<int, vector<int>, greater<int>> pq; //최소힙

	//입력
	cin >> n;

	//연산
	for (int i = 0; i < n * n; i++) {
		cin >> num;
		pq.push(num);

		//pq의 size를 n개 이하로 유지하여 메모리 초과 방지
		if (pq.size() > n) {
			pq.pop(); //pq에서 가장 작은 값 제거
		}
	}

	//출력
	//pq에 n * n개의 수 중 가장 큰 n개가 남았으므로 그 중 가장 작은 값이 n번째 큰 수
	cout << pq.top();

	return 0;
}

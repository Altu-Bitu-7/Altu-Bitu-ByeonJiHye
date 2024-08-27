#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxEmploy(vector<pair<int, int>> candidates) {
	// 서류 심사 1등은 다른 모든 지원자들보다 서류 점수가 높으므로 자동 합격.
	int result = 1, highest_score = candidates[0].second;
	//서류 점수 기준으로 오름차순으로 정렬된 배열
	// 고로 나보다 앞선 순서 사람 중 최고 면접 점수보다 내 면접접수가 높아야 합격 가능함.
	for (int i = 1; i < candidates.size(); i++) {
		if (highest_score > candidates[i].second) {
			highest_score = candidates[i].second; // 가장 높은 면접 점수 갱신
			result++; // 합격자 추가
		}
	}
	return result;
}

int main()
{
	int test_case, n, results;

	cin >> test_case;
	while (test_case--) {
		cin >> n;
		vector<pair<int, int>> candidates(n, pair<int, int>(0, 0)); 
		//지원자를 (서류점수, 면접점수) 형태로 담을 동적 배열 생성
		for (int i = 0; i < n; i++) {
			cin >> candidates[i].first >> candidates[i].second; //입력 받기
		}

		sort(candidates.begin(), candidates.end()); // 서류 심사 순위 순서대로 오름차순 정렬
		results = maxEmploy(candidates);

		cout << results << '\n';
	}
	return 0;
}
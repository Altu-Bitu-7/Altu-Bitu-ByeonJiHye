#include <iostream>
#include <set>

using namespace std;

int main()
{
	int n, m, sum = 0;
	set<string> s; //검색에 사용할 예정이므로 set 사용
	string input;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> input;
		s.insert(input); 
	}

	for (int i = 0; i < m; i++) {
		cin >> input;
        sum += s.count(input); 
        //set에서 input 값이 나타나는 여부를 판단해서 더함
        //set은 중복된 값이 존재하지 않으므로 count 함수 사용 가능
	}

	cout << sum << '\n';
	return 0;
}
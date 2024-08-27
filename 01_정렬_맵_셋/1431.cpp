#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calNum(string number_str) {
	int sum = 0;
	for (int i = 0; i < number_str.size(); i++) {
		if (number_str[i] >= '0' && number_str[i] <= '9') { 
			sum += number_str[i] - '0'; 
		}
	}
	return sum;
}

bool cmp(const string& s1, const string& s2)
{
	if (s1.size() != s2.size()) { 
		return s1.size() < s2.size();
	}
	if (calNum(s1) != calNum(s2)) { 
		return calNum(s1) < calNum(s2);
	}
	return s1 < s2; //사전순 정렬
}

int main()
{
	int n;
	cin >> n;

	vector<string> arr(n, "");

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}
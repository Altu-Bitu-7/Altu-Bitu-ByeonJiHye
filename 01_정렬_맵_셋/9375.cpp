#include <iostream>
#include <map>

using namespace std;

//의상의 이름과 의상의 종류 중 개수를 좌우하는 것은 종류.
//따라서 종류를 map의 key로 삼아야 함.

int main()
{
	int test, n;
	string outfit_name, outfit_type;

	cin >> test;
	while (test--) {
		int coordi = 1;
		cin >> n;
		map<string, int> clothes;
		while (n--) {
			cin >> outfit_name >> outfit_type;
			clothes[outfit_type]+= 1; 
		}

		for (auto keys : clothes) { // map의 key 값으로 interate
			coordi *= keys.second + 1;
		}
		coordi-= 1; // 알몸인 경우를 제외해야 하므로 1을 뺌.

		cout << coordi << '\n';
	}
	return 0;
}
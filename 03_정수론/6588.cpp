#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> 

using namespace std;

// 에라토스테네스의 체를 이용해 소수를 구하는 함수
vector<bool> getPrime(int max) {
    vector<bool> is_prime(max + 1, true);
    is_prime[0] = is_prime[1] = false;  // 0과 1은 소수가 아님

    // max의 제곱근까지만 확인하여 시간 복잡도 ⬇️
    int limit = static_cast<int>(sqrt(max));
    for (int i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

// 구한 소수를 뺀 값도 소수인지 판단하는 함수
int goldbach(int n, const vector<bool>& is_prime) {
    for (int a = 3; a <= n / 2; a += 2) {
        if (is_prime[a] && is_prime[n - a]) {
            return a;
        }
    }
    return 0;
}

int main() {
    vector<int> arr;
    int input;

    while (true) {
        cin >> input;
        if (input == 0) {
            break;
        }
        arr.push_back(input);
    }

    int max_num = *max_element(arr.begin(), arr.end());
    vector<bool> is_prime = getPrime(max_num);

    for (int i = 0; i < arr.size(); i++) {
        int a = goldbach(arr[i], is_prime);

        if (a != 0) {
            cout << arr[i] << " = " << a << " + " << arr[i] - a << "\n";
        } else {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }

    return 0;
}

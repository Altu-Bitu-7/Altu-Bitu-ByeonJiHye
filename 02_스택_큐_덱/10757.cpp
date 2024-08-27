#include <iostream>
#include <string>
#include <algorithm>

std::string addNumber(const std::string& a, const std::string& b) {
    std::string result;
    int carry = 0;
    int idx_a = a.length() - 1;
    int idx_b = b.length() - 1;

    // 두 문자열을 뒤에서부터 차례로 더함
    while (idx_a >= 0 || idx_b >= 0 || carry) {
        int sum = carry;
        if (idx_a >= 0) {
            sum += (a[idx_a] - '0');
            --idx_a;
        }
        if (idx_b >= 0) {
            sum += (b[idx_b] - '0');
            --idx_b;
        }
        carry = sum / 10;  // 자리올림 처리
        result.push_back((sum % 10) + '0');  // 현재 자리의 결과 저장
    }

    // 결과가 거꾸로 되어 있으므로 뒤집기
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    std::string a, b;
    std::cin >> a >> b;

    std::string result = addNumber(a, b);
    std::cout << result << std::endl;

    return 0;
}

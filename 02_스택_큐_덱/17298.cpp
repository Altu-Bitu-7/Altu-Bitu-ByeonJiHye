#include <iostream>
#include <vector>
#include <stack>

std::vector<int> calNge(const std::vector<int>& a) {
    int n = a.size();
    std::vector<int> nge(n, -1); 
    std::stack<int> s; 


    for (int i = 0; i < n; ++i) {
        // 스택이 비어 있지 않고, 스택 top이 가리키는 값보다 현재 수열의 값이 큰 경우
        while (!s.empty() && a[s.top()] < a[i]) {
            nge[s.top()] = a[i];  // 현재 수열의 값을 스택 top의 오큰수로 설정
            s.pop();  // 스택에서 제거
        }
        s.push(i);  // 현재 인덱스를 스택에 추가
    }

    return nge;  
}

int main() {
    int n;
    std::cin >> n;
    
//입력
    std::vector<int> a(n);  
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> nge = calNge(a);

//출력
    for (int i = 0; i < n; ++i) {
        std::cout << nge[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

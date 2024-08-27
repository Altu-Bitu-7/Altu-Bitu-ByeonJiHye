#include <iostream>
#include <stack>
#include <string>

bool isBalanced(const std::string& str) {
    std::stack<char> s;  // 괄호를 저장하는 데 사용할 스택

    for (char ch : str) {
        if (ch == '(' || ch == '[') {
            s.push(ch);
        } else if (ch == ')') {
            if (s.empty() || s.top() != '(') {
                // 스택이 비어 있거나, 스택의 최상단이 '('가 아니라면 균형이 맞지 않음
                return false;
            }
            // 균형이 맞다면 스택에서 '('를 제거
            s.pop();
        } else if (ch == ']') {
            if (s.empty() || s.top() != '[') {
                // 스택이 비어 있거나, 스택의 최상단이 '['가 아니라면 균형이 맞지 않음
                return false;
            }
            // 균형이 맞다면 스택에서 '['를 제거
            s.pop();
        }
    }

    // 모든 문자를 확인한 후 스택이 비어 있어야 참으로, 균형이 이루어졌음을 알 수 있음!
    return s.empty();
}

int main() {
    std::string line;
    
    while (true) {
        std::getline(std::cin, line); 
        
        if (line == ".") {
            break;
        }
        
        if (isBalanced(line)) {
            std::cout << "yes" << std::endl;  
        } else {
            std::cout << "no" << std::endl; 
        }
    }
    
    return 0;
}

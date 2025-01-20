#include <iostream>
#include <cstring>
#include <map>
#include <stack>

class Solution {
    public:
        bool isValid(std::string str) {
            std::stack<char> _stack;

            for (auto c : str) {
                if (_stack.empty() && (c == ')' || c == '}' || c == ']'))
                    return false;

                if (c == '(' || c == '{' || c == '[') {
                    _stack.push(c);
                } else {
                    auto top = _stack.top();
                    if (c == _map[top]) {
                        _stack.pop();
                        continue;
                    }
                    else
                        return false;
                }

            }

            return _stack.empty();
        }

    private:
        std::map<char, char> _map =  { {'(', ')'}, { '{', '}' }, { '[', ']' } };
};

int main(int argc, char* argv[]) {
    Solution soln;
    std::string str = "()";
    std::cout << soln.isValid(str) << std::endl;

    str = "()[]{}";
    std::cout << soln.isValid(str) << std::endl;

    str = "(]";
    std::cout << soln.isValid(str) << std::endl;

    str = "([])";
    std::cout << soln.isValid(str) << std::endl;

    str = "[";
    std::cout << soln.isValid(str) << std::endl;

    return 0;
}

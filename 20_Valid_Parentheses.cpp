#include <iostream>
#include <cstring>
#include <map>

class Solution {
    public:
        bool isValid(std::string str) {
            for (auto c : str) {}
            return false;
        }

    private:
        std::vector<char> characters = { '(', ')', '{', '}', '[', ']' };
        std::map<char, char> _map =  { {'(', ')'}, { '{', '}' } };
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

    std::cout << true << std::endl;

    return 0;
}

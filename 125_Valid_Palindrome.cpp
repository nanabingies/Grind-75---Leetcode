#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string temp = s;

        int left = 0;
        int right = temp.length() - 1;
        while (left < right) {
            if (!std::isalnum(s[left])) {
                ++left;
                continue;
            }
            if (!std::isalnum(s[right])) {
                --right;
                continue;
            }

            if (std::tolower(temp[left]) == std::tolower(temp[right])) {
                ++left;
                --right;
            } else {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution soln = Solution();

    string s = "A man, a plan, a canal: Panama";
    //soln.isPalindrome(s);
    string output = soln.isPalindrome(s) == true ? "true" : "false";
    std::cout << output << endl;

    s = "race a car";
    output = soln.isPalindrome(s) == true ? "true" : "false";
    std::cout << output << endl;

    return 0;
}
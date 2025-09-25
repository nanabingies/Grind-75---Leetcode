#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) { return false; }

        string temp{};
        for (int i = 0; i != s.length(); ++i) {
            if (find(temp.begin(), temp.end(), s[i]) != temp.end()) { continue; }
            if (std::count(s.cbegin(), s.cend(), s[i]) != count(t.cbegin(), t.cend(), s[i])) {
                return false;
            }
            temp.push_back(s[i]);
        }

        return true;
    }
};

int main() {
    Solution soln = Solution();

    string s = "anagram", t = "nagaram";
    cout << soln.isAnagram(s, t) << endl;

    s = "rat", t = "car";
    cout << soln.isAnagram(s, t) << endl;

    return 0;
}

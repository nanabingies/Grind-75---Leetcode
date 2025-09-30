#include <iostream>
using namespace std;

void printResult(vector<vector<int>>&);

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        std::function<void(vector<vector<int>>&, int, int, int, int)> fillIndex;
        int interestVar = image[sr][sc];
        if (interestVar == color) { return image; }

        fillIndex = [&](vector<vector<int>>& image, int sr, int sc, int color, int interestVar) -> void {
            int rows = image.size();
            int cols = image[0].size();

            if (sr < 0 || sc < 0 || sr >= rows || sc >= cols || image[sr][sc] != interestVar) { return; }

            image[sr][sc] = color;

            fillIndex(image, sr - 1, sc, color, interestVar);
            fillIndex(image, sr + 1, sc, color, interestVar);
            fillIndex(image, sr, sc - 1, color, interestVar);
            fillIndex(image, sr, sc + 1, color, interestVar);
        };

        fillIndex(image, sr, sc, color, interestVar);

        return image;
    }
};

int main() {
    Solution soln = Solution();

    vector<vector<int>> image = {{1,1,1}, {1,1,0}, {1,0,1}};
    int sr = 1;
    int sc = 1;
    int color = 2;
    auto res = soln.floodFill(image, sr, sc, color);
    printResult(res);

    image = {{0,0,0}, {0,0,0}};
    sr = 0, sc = 0, color = 0;
    res = soln.floodFill(image, sr, sc, color);
    printResult(res);

    return 0;
}

void printResult(vector<vector<int>>& image) {
    for (auto outer : image) {
        for (auto inner : outer) {
            std::cout << inner << " ";
        }
        putchar('\n');
    }
    putchar('\n');
}

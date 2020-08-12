#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string& word, int wordIndex, int x_position, int y_position) {
        if (board[x_position][y_position] != word[wordIndex]) return false;
        if (wordIndex == word.size() - 1) return true;

        char tmp = board[x_position][y_position];
        board[x_position][y_position] = 0;

        if ((x_position > 0 && dfs(board, word, wordIndex + 1, x_position - 1, y_position))
            || (y_position > 0 && dfs(board, word, wordIndex + 1, x_position, y_position - 1))
            || (x_position < board.size() - 1 && dfs(board, word, wordIndex + 1, x_position + 1, y_position))
            || (y_position < board[0].size() - 1 && dfs(board, word, wordIndex + 1, x_position, y_position + 1))
            ) {
            return true;
        }

        board[x_position][y_position] = tmp;
        return false;
    }
};
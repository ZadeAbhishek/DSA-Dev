#include <bits/stdc++.h>
using namespace std;

void operator<<(std::ostream &Cout, std::vector<std::string> matrix)
{
   for (auto y : matrix)
      Cout << y << " ";
   Cout << "\n";
}

class Tries
{
public:
   Tries *children[128] = {};
   bool isWord = false;
   string s = "";
   void insert(string s);
};

void Tries::insert(string s)
{
   Tries *curr = this; // this represents root at start

   for (auto letter : s)
   {
      if (curr->children[letter - '0'] == NULL)
      {
         curr->children[letter - '0'] = new Tries();
      }
      curr = curr->children[letter - '0'];
   }
   curr->isWord = true;
   curr->s = s;
}

class Solution
{
public:
   void get_word(vector<vector<char>> &board, Tries *root, int x, int y, vector<vector<int>> &vis, set<string> &result)
   {
      // base case
      int s = board.size();
      int d = board[0].size();
      if (x > s - 1 || y > d - 1 || x < 0 || y < 0)
         return;
      // check if is word
      if (root == NULL)
         return;

      // main backtraking part
      if (root->children[(board[x][y] - '0')] != NULL && vis[x][y] != 1)
      {
         if (root->children[(board[x][y] - '0')]->isWord)
         {
            result.insert(root->children[(board[x][y] - '0')]->s);
         }
         // letter is present
         vis[x][y] = 1;
         get_word(board, root->children[(board[x][y] - '0')], x - 1, y, vis, result);
         get_word(board, root->children[(board[x][y] - '0')], x + 1, y, vis, result);
         get_word(board, root->children[(board[x][y] - '0')], x, y - 1, vis, result);
         get_word(board, root->children[(board[x][y] - '0')], x, y + 1, vis, result);
         vis[x][y] = 0;
      }
      return;
   }

   vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
   {
      Tries *root = new Tries();
      for (auto s : words)
         root->insert(s);
      string ans = "";
      set<string> result;
      vector<vector<int>> vis(board.size() + 1, vector<int>(board[0].size(), 0));
      for (int i = 0; i < board.size(); i++)
      {
         for (int j = 0; j < board[0].size(); j++)
         {
            get_word(board, root, i, j, vis, result);
         }
      }
      vector<string> finalResult;
      for (auto x : result)
         finalResult.push_back(x);
      return finalResult;
   }
};

int main()
{
   Solution *solve = new Solution();
   vector<vector<char>> b = {{'a'}};
   vector<string> s = {"a"};
   cout << solve->findWords(b, s);
}
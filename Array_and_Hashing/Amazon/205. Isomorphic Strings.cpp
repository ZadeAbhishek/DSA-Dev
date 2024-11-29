// ##ArrayHash
class Solution {
public:
    bool isIsomorphic(string s, string t) {

  if (size(s) != size(t)) return false;

  // size 200 so the we can cover all charecter ASCII

  vector s_vec(200, 0);
  vector t_vec(200, 0);

  // basic idea is we will map ascii of string 1 char to string 2 char vice versa

  for (auto i = 0; i < size(s); i++) {
    if (s_vec[(int) s[i]] == 0 && t_vec[(int) t[i]] == 0) {
      s_vec[(int) s[i]] = (int) t[i];
      t_vec[(int) t[i]] = (int) s[i];
    }
    // if already there check for value are same or not
    if (s_vec[(int) s[i]] != (int) t[i] || t_vec[(int) t[i]] != (int) s[i]) return false;
  }

  return true;
}
};
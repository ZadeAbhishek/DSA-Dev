
// ##Prime Number
class Solution {
    bool isPrime(int n){
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }

    bool palindrome(string s){
        int i = 0;
        int j = s.size() - 1;
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    int primePalindrome(int n) {
        if(n <= 2) return 2;
        if(n >= 9989900) return 100030001; // may be 10^8;
        if(n <= 11 and isPrime(n)) return n;

        for(int i = n + 1 ; i <= 2e8+5; i++){
            if(isPrime(i) and palindrome(to_string(i))){return i;};
        }

        return -1;
    }
};



class Solution {
public:
    int countTriples(int n) {
     // we can solve this in two steps
     // step 1 is to get the square of a nd b
     // add it and take sqaure root can chekc the range 
     int count = 0;
     for(int a = 1 ; a < n ; a++){
        for(int b = a+1 ; b <=n ; b++){
            long long a2 = a * a;
            long long b2 = b * b;
            long long c2 = a2 + b2;
            long long c = (int) sqrt(c2);
            if (c <= n && c * c == c2) {
                    count++;
           }
        }
     }
     return count*2;

    }
};
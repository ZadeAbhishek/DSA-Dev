class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        // we can used sorting but using priority queue always work u i gues
        
         int sum = accumulate(begin(piles), end(piles), 0);
        
        priority_queue<int> table(begin(piles), end(piles)); //O(nlog(n))

        while(k)
        {
            int temp = table.top(); 
            table.pop();
            table.push(temp - (temp/2));
            sum -= (temp / 2);
            k--;
        }

        return sum; 

    }
};
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var rearrangeArray = function(nums) {
    nums.sort((a, b) => a - b);
    let i,j,counter;
    i = 0;
    j = nums.length - 1;
    let ans = [];
    counter = nums.length;
    let flag = 1;
    while(counter){
       ans.push(flag ? nums[i++] : nums[j--]);
       flag = !flag;
       counter--;
    }
    return ans;  
  };
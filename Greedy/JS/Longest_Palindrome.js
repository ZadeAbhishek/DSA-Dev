init();

/**
 * 
 * @param {string} s 
 * @returns Number
 * 
 * Basic idea of this function is we are calculating odd number of char
 * remove them from original string and add 1 if only one odd is present at end
 */


function LongestPalindrome(s) {
    let buffer = new Array(129).fill(0);
    for (let c of s) buffer[c.charCodeAt(c)]++;
    console.log(...buffer);
    for (let curr of buffer) console.log(curr, buffer[0]), buffer[0] += curr & 1;
    console.log(...buffer);
    return (s.length - buffer[0]) + (buffer[0] > 0);
}

function init() {
    let s = "madam";
    let result = LongestPalindrome(s);
    console.log(result);
}
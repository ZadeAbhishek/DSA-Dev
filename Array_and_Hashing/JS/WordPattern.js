/**
 * Input: pattern = "abba", s = "dog cat cat dog"
 * Output: true
 */

init();

function WordPattern(pattern, s) {
    s += ' ';
    let hash1 = {};
    let hash2 = {};
    let stringsep = [];
    let temp = "";
    for (let index = 0; index < s.length; index++) s[index] == ' ' ? (stringsep.push(temp.slice()), temp = []) : temp += s[index];
    if (pattern.length !== stringsep.length) return false;
    for (let index = 0; index < s.length; index++) {

        if (hash1[pattern[index]] !== undefined) { // if a = dog
            if (hash1[pattern[index]] === stringsep[index]) continue; // if a == dog 
            else return false;
        }
        hash1[pattern[index]] = stringsep[index]; // a = dog
        hash2[stringsep[index]] = pattern[index];
    }
    let currTemp = "";
    for (let index = 0; index < stringsep.length; index++) currTemp += hash2[stringsep[index]];
    return currTemp === pattern;
}

function init() {
    let pattern = "abbcda";
    let s = "dog cat cat fish frog dog";
    let result = WordPattern(pattern, s);
    console.log(result);
}
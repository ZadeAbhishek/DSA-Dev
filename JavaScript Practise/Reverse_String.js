let string = "Abhishek Zade"

const reverse = (string,seperator_factor)=>{
    return string.split(seperator_factor).reverse().join(seperator_factor);
};


/* 557. Reverse Words in a String III */
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    let temp = s.split(" ");
    let result = temp.map((word)=>{return word.split("").reverse().join("")});
    return result.join(" ");
};


let reverse_words = reverse(string," ");
let reverse_all = reverse(string,"");

console.log(reverse_words);
console.log(reverse_all);
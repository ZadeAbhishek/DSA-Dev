let string = "Abhishek Zade"

const reverse = (string,seperator_factor)=>{
    return string.split(seperator_factor).reverse().join(seperator_factor);
};

let reverse_words = reverse(string," ");
let reverse_all = reverse(string,"");

console.log(reverse_words);
console.log(reverse_all);
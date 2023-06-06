// exp string to int 
// "[[1,2],[1,3],[2,3]]"

let str = "[1,2]";
let int = [];
let temp = [];
for (s of str) {
    if (s === '[' || s === ',' || s === ' ') continue;
    if (s === ']') {
        int.push(temp.slice());
        temp = [];
        continue;
    }
    let t = parseInt(s);
    temp.push(t);
}
console.log(int);
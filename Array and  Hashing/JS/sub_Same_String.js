//s = ABC
// r = BC now anw = true and len of sub string = 2

//   A B C
// B 0 1 1
// C 0 1 2

// return memo[size(s)-1][size(r)-1]>1  // true

init();


function compare(s, r) {

    let memo = new Array(s.length).fill(Array(r.length).fill(0));

    for (let i = 0; i < s.length; i++) {
        for (let j = 0; j < r.length; j++) {
            if (s[i] != r[j]) {
                if (i == 0 && j == 0) memo[i][j] = 0;
                else if (i == 0 && j != 0) memo[i][j] = memo[i][j - 1];
                else if (i != 0) memo[i][j] = memo[i - 1][j];
            } else {
                if (i == 0 && j == 0) memo[i][j] = 1;
                else memo[i][j] = memo[i][j - 1] + 1;
            }
        }
    }
    console.log(`Lenght of Sub String:${memo[s.length - 1][r.length - 1]}`);
    if (memo[s.length - 1][r.length - 1] > 1) return true;
    else return false;
}

function init() {
    let s = "Hacker Who Has Access To Your Operating System";
    let r = "Hacker Who Has Access To Your Operating System";

    let result = compare(s, r);
    console.log(result);
}
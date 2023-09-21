function palindrom(s) {
    if (s.length == 1) return false;
    let j = s.length - 1;
    let k = 0;
    while (s[j--] == s[k++] && j != k && j > 0 && k < s.length - 1);
    if (j == k && s[j + 1] == s[k - 1]) return true;
    else if (j == 0 && k == s.length) return true;
    else return false;
}


function main() {
    let s = "aba";
    if (palindrom(s)) console.log(`${s} is Palindrom`);
    else console.log("Not a Palindrom");
}

main();
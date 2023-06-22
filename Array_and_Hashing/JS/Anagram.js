init();

function Anagram(s, r) {

    // Buffer to store char count
    let Buffer = new Array(128).fill(0); // O(128) ~ O(1)

    for (let c of s) Buffer[c.charCodeAt(c)]++; //O(n)

    for (let c of r) Buffer[c.charCodeAt(c)]--; //O(n)

    for (let c of Buffer) //O(1)
        if (c > 0) return false;

    return true;
}


function init() {
    let s = "zipri";
    let r = "prizi";
    let result = Anagram(s, r);
    console.log(result);
}
init();

function Anagram(s, r) {

    // Buffer to store char count
    let Buffer = new Array(128).fill(0); // O(128) ~ O(1)

    for (let c of s) Buffer[c.charCodeAt(c)]++; //O(n)

    for (let c of r) Buffer[c.charCodeAt(c)]--; //O(n)

    for (let c of Buffer) //O(1)
        if (c != 0) return false;

    return true;
}

// Not Working
// function Anagram_2(s,r){
//      if(s.length !== r.length) return false;
//      let t = 0 , y = 0 , m = 0 , n = 0 , z = 0;
//      for(let c of s) t += c.charCodeAt(c), m = m ^ c.charCodeAt(c);
//      for(let c of r) y += c.charCodeAt(c), n = n ^ c.charCodeAt(c);
//      for(let i = 0 ; i < s.length ; i++) z += s.charCodeAt(i) - r.charCodeAt(i);
//      console.log(t,y,m,n,z); 
//      let res = t ^ y;
//      return (res===0?true:false)
// }

function init() {
    let s = "af";
    let r = "be";
    let result = Anagram(s, r);
    console.log(result);
}
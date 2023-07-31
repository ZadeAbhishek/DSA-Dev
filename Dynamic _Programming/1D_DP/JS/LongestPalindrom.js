init();

function getLP(s){
    let memo = new Array(s.length).fill(null).map(()=>{return new Array(s.length).fill(0)});
    let m = -999999;
    let res = "";
    for(let diff = 0 ; diff < s.length ; diff++){
        for(let i = 0, j = i + diff ; j < s.length ; i++,j++){
            if(diff == 0) memo[i][j] = 1;
            else if(diff == 1) (s[i] == s[j])?memo[i][j] = 2:memo[i][j] = 0;
            else if(s[i] == s[j] && memo[i+1][j-1]) memo[i][j] = memo[i+1][j-1] + 2;
            if(memo[i][j]) if(j-i+1 > m) m = (j-i+1),res = s.slice(i,j+1);
        }
    }
    return res;
}

function init(){
    let s = "bababdaaadaaa";
    let res = getLP(s);
    console.log(res)
}
init();

function init() {
    let w = [10, 20, 30];
    let c = [60, 100, 120];
    let W = 50;
    let memo = [];
    for (let i = 0; i < w.length; i++) memo.push(0);
    let CMax = -99999999;
    let bag = 0;
    let CurrCost = 0;

    let result = dp(w, c, W, memo, CMax, bag, CurrCost);

    console.log(result);
}


function dp(w, c, W, memo, Cmax, bag, CurrCost) {
    // base case 
    //console.log(`${bag},${W},${Cmax}`);
    if (bag > W) return 0;
    if (bag == W) return CurrCost;
    // itterator to all cases
    for (let index = 0; index < w.length; index++) {
        if (memo[index] != 0) continue;
        memo[index] = 1;
        bag += w[index];
        CurrCost += c[index];
        let temp = dp(w, c, W, memo, Cmax, bag, CurrCost);
        if (temp == 0) Cmax = Math.max((CurrCost - c[index]), Cmax);
        else Cmax = Math.max(temp, Cmax);
        CurrCost -= c[index];
        bag -= w[index];
        memo[index] = 0;
    }
    return Cmax;
}
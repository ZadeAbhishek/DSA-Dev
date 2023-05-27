init();

// Nfactorial using Memoization

function init() {

    let memo = new Array(1000000).fill(0);
    let n = 20;
    let result = Nfact(n, memo);
    console.log(result);

}

function Nfact(n, memo) {
    if (n == 1) return 1;
    if (memo[n] != 0) return memo[n];
    else return memo[n] = n * Nfact(n - 1, memo);
}
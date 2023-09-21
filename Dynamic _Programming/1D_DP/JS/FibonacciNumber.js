init();

function init() {

    //adding memo
    let n = 10;
    let memo = new Array(n+1).fill(0);
    let result = fib(n, memo);
    console.log(`Result -> ${result}`);
    console.log(...memo);

}

function fib(n, memo) {
    if (n == 0 || n == 1) return n;
    console.log(memo[n]);
    if (memo[n] != 0) return memo[n];
    return memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
}
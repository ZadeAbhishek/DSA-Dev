init();

function init() {

    //adding memo

    let memo = new Array(1000000).fill(0);
    let n = 10;
    let result = fib(n, memo);
    console.log(`Result -> ${result}`);
    console.log(`Series->`);
    for (let i = 0; i <= n; i++) console.log(memo[i]);

}

function fib(n, memo) {
    if (n == 0 || n == 1) return n;
    if (memo[n] != 0) return memo[n];
    return memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
}
init();

function GCD(min, max) {
    if (min == 0 || max == 0) return 0;
    if (min == max) return min;
    if (max > min) return GCD(min, max - min);
    else return GCD(min - max, max);
}

function init() {
    let max = 15;
    let min = 10;
    let result = GCD(min, max);
    console.log(result);
}
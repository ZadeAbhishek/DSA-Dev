init();


function pascalTriangle(n) {
    let temp = [];
    let result = [];

    for (let i = 0; i < n; i++) {
        for (let j = 0; j <= i; j++) {
            if (i === j) {
                temp.push(1);
                continue;
            } else if (j === 0) {
                temp.push(1);
                continue;
            }
            temp.push(result[i - 1][j - 1] + result[i - 1][j]);
        }
        result.push(temp.slice());
        temp = [];
    }
    return result;
}

function init() {
    let n = 5;
    let result = pascalTriangle(n);
    console.log(...result)
}
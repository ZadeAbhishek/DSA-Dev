const mat = [[1],[2],[3]];
const target = 100;

function getDiff(mat, target, col, row, i, sum, minDiff,dp) {
    
    const key = `${i}-${sum}`; // since i and sum is variable
    if(key in dp){
        return dp[key];
    }
    
    if (i == col) {
        minDiff.value = Math.min(Math.abs(target - sum), minDiff.value);
        return minDiff.value;
    }
    
    for (let row_index = 0; row_index < row; row_index++) {
        getDiff(mat, target, col, row, i + 1, sum + mat[i][row_index], minDiff,dp);
    }

    dp[key] = minDiff.value;
    return dp[key];
}

function getMinDifference(mat, target) {
    // Using DP and Backtracking
    const row = mat[0].length;
    const col = mat.length;
    // we can create memo here for variable that is changing
    let dp = {};
    return getDiff(mat, target, col, row, 0, 0, { value: Number.MAX_VALUE },dp);
}

console.log(getMinDifference(mat, target));


// Dry run this and try
var minimizeTheDifference = function(mat, target) {
    const rows = mat.length;
    const cols = mat[0].length;
    let dp = new Set([0]);

    for (let i = 0; i < rows; i++) {
        const nextDp = new Set();
        for (let sum of dp) {
            for (let j = 0; j < cols; j++) {
                nextDp.add(sum + mat[i][j]);
            }
        }
        dp = nextDp;
    }

    let minDiff = Number.MAX_VALUE;
    for (let sum of dp) {
        minDiff = Math.min(minDiff, Math.abs(target - sum));
    }

    return minDiff;
};
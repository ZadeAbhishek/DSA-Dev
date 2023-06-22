var cnt = 0;
init();

function init(){
    let steps = 2;
    var memo = new Array(steps).fill(0);
    countSteps(steps,memo)
    return memo[steps];
}

function countSteps(steps,memo){
    if(steps <= 2) {
        memo[steps] = steps;
        return steps;
    }
    if(memo[steps] != undefined && memo[steps] != 0) return memo[steps];
    memo[steps] = countSteps(steps-1,memo) + countSteps(steps-2,memo);
    return memo[steps];
}
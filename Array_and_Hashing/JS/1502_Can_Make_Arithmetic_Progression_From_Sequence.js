var canMakeArithmeticProgression = function(arr) {
    if (arr.length === 0) return false;
    if (arr.length <= 2) return true;
    arr.sort(sortNumber);
    let f = arr[0]; // 
    let s = arr[1];
    diff = s - f;
    for (let index = 2; index < arr.length; index++) {
        if (arr[index] - arr[index - 1] !== diff) return false;
    }
    return true;

};

function sortNumber(a, b) {
    return a - b;
}


// Optimised 

/**
 * @param {number[]} arr
 * @return {boolean}
 */
var canMakeArithmeticProgression = function(arr) {
    let min = Number.MAX_SAFE_INTEGER + 1;
    let max = Number.MIN_SAFE_INTEGER + 1;

    for (let element of arr) {
        if (element >= max) max = element;
        if (element <= min) min = element;
    }

    let d = (max - min) / (arr.length - 1);

    if (d != Math.round(d)) return false;

    if (d === 0) return true;

    let set = new Set();

    for (let element of arr) {
        if (((element - min) % d) !== 0) return false;
        set.add(element);
    }
    //console.log(Object.keys(set).length);
    return set.size === arr.length;
}

// if (((element - min) % d) != 0) return false;

let arr = [-68, -96, -12, -40, 16];
console.log(canMakeArithmeticProgression(arr));
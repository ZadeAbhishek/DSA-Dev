// Given array find minimun swaps to sort array

// 1 2 7 4

// 0 1 2 3
// 1 2 4 7 

// 0 1
// 1 2
// 2 7
// 4 3

// 0 1
// 1 2
// 4 3
// 2 7


// min swap 1 

let arr = [1, 2, 7, 4, 3, 6, 5, 9, 8];

let hashmap = {};

let sorted = [];

for (let index = 0; index < arr.length; index++) hashmap[arr[index]] = index, sorted.push([arr[index], index]);

sorted.sort();

let count = 0;

for (let index = 0; index < sorted.length; index++)
    if (hashmap[sorted[index][0]] != index) swaparr(sorted, index, hashmap[sorted[index][0]]), count++;

function swaparr(sorted, i, j) {
    let temp = sorted[i];
    sorted[i] = sorted[j];
    sorted[j] = temp;
    return sorted;
}

console.log(count);
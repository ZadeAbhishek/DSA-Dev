// of for array || in for object

let arr = [5, 1, -1, -8, -7, 8, -5, 0, 1, 10, 8, 0, -4, 3, -1, -1, 4, -5, 4, -3, 0, 2, 2, 2, 4, -2, -4, 8, -7, -7, 2, -8, 0, -8, 10, 8, -8, -2, -9, 4, -7, 6, 6, -1, 4, 2, 8, -3, 5, -9, -3, 6, -8, -5, 5, 10, 2, -5, -1, -5, 1, -3, 7, 0, 8, -2, -3, -1, -5, 4, 7, -9, 0, 2, 10, 4, 4, -4, -1, -1, 6, -8, -9, -1, 9, -9, 3, 5, 1, 6, -1, -2, 4, 2, 4, -6, 4, 4, 5, -5];

let hashmap = {}; // hashmap

// Traking element into hashmap according to there occurence
for (let curr of arr) hashmap[curr] == undefined ? hashmap[curr] = 1 : hashmap[curr]++;

// array 
let track = [];

// Converting hashmap into array to sort it 
for (let curr in hashmap) track.push([hashmap[curr], curr]);

// sort to get max element
track.sort(sortFunction).reverse();

function sortFunction(a, b) {
    if (a[0] === b[0]) {
        return 0;
    } else {
        return (a[0] < b[0]) ? -1 : 1;
    }
}

// console.log(track);
let k = 7,
    count = 0;

// get top k element
let result = [];
while (count < k) result.push(track[count][1]), count++;
console.log(result);

//console.log(track);
init();

function CountingSort(arr) {
    let max_element = Math.max.apply(null, arr) + 1;
    let buffer = new Array(max_element).fill(0);
    for (let curr of arr) buffer[curr]++;
    arr = [];
    for (let index = 0; index < max_element; index++)
        while (buffer[index] > 0) arr.push(index), buffer[index]--;
    return arr;
}

function init() {
    let arr = [7, 11, 9, 3, 6, 10, 66, 78, 96, 12, 36, 105, 700, 64, 3, 6, 0];
    let result = CountingSort(arr);
    console.log(...result);
}
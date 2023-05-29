init();

function swap_arr(arr, i, j) {
    let temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}

function sort_arr(arr) {
    let start = 0;
    let curr = 0;
    let end = arr.length - 1;
    while (curr < end) {
        if (arr[curr] == 0) swap_arr(arr, curr, start), curr++, start++;
        else if (arr[curr] == 1) curr++;
        else swap_arr(arr, curr, end), end--;
    }
    return arr;
}

function init() {
    let arr = [0, 1, 1, 1, 2, 1, 2];
    let result = sort_arr(arr);
    console.log(...result);
}
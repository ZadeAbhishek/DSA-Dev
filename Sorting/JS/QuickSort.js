/**
 * @init drive Function
 * @partition return [];
 */


init();

function swap_arr(arr, i, j) {
    let temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}

function partition(arr, i, pivot, j) {
    while (i <= j) {
        console.log("sss");
        if (arr[i] >= arr[pivot] && arr[j] <= arr[pivot]) swap_arr(arr, i, j), i++, j--;
        if (arr[i] < arr[pivot]) i++;
        if (arr[j] > arr[pivot]) j--;

    }
    swap_arr(arr, pivot, j);
    return j;
}


function BubbleSort(arr, i, j) {
    // base case
    if (i > j) return;

    let mid = partition(arr, i, i + 1, j);
    console.log(mid);
    BubbleSort(arr, i, mid);
    BubbleSort(arr, mid + 1, j);
}

function init() {
    let arr = [7, 11, 9, 3, 6, 10, 66, 78, 96, 12, 36, 105, 700, 64, 3, 6, 0];
    BubbleSort(arr, 0, arr.length - 1);
    console.log(...arr);
}
init();

function SortAndMerge(arr1, arr2) {
    let temp = [];
    let i = 0,
        j = 0;
    while (i < arr1.length && j < arr2.length) {
        if (arr1[i] < arr2[j]) temp.push(arr1[i]), i++;
        else temp.push(arr2[j]), j++;
    }
    while (i < arr1.length) temp.push(arr1[i]), i++;
    while (j < arr2.length) temp.push(arr2[j]), j++;

    return temp;
}

function MergeSort(arr, high, low) {
    if (high == low) return [arr[low]];
    let mid = Math.floor((high + low) / 2);
    return SortAndMerge(MergeSort(arr, mid, low), MergeSort(arr, high, mid + 1));


}

function init() {
    let arr = [-7, 11, 9, 3, 6, 10, 66, 78, 96, 12, 36, 105, 700, 64, 3, 6];
    let high = arr.length - 1;
    let low = 0;
    let result = MergeSort(arr, high, low);
    console.log(...result);
}
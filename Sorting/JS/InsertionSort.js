init();

function swap(arr, i, j) {
    let temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}

function InsertionSort(arr) {
    let secondar_index;
    let temp = arr.slice();
    for (let index = 1; index < temp.length; index++) {
        secondar_index = index;
        while (temp[secondar_index] < temp[secondar_index - 1] && secondar_index > 0) {
            swap(temp, secondar_index - 1, secondar_index);
            secondar_index--;
        }
    }
    return temp;
}

function init() {
    let arr = [-7, 11, 9, 3, 6, 10, 66, 78, 96, 12, 36, 105, 700, 64, 3, 6];
    let result = InsertionSort(arr);
    console.log(...result);
}
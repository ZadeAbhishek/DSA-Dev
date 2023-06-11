init();


function swap(arr, i, j) {
    let temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}

function BubbleSort(arr) {
    let pass = 0;
    let temp = arr.slice();
    while (pass < temp.length) {
        let i = 0,
            j = 1;
        while (j < temp.length) {
            if (temp[i] > temp[j]) swap(temp, i, j);
            i++, j++;
        }
        pass++;
    }
    return temp;
}

function init() {
    let arr = [-7, 11, 9, 3, 6, 10, 66, 78, 96, 12, 36, 105, 700, 64, 3, 6];
    let result = BubbleSort(arr);
    console.log(...result);
}
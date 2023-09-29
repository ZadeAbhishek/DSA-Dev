init();

function BinarySearch(arr, target, high, low) {
    let result;
    if (high == low && arr[low] == target) return low;
    if (low > high) return -1;
    let mid = Math.round((high + low) / 2);
    if (arr[mid] == target) return mid;
    if (arr[mid] > target) result = BinarySearch(arr, target, mid-1, low);
    else result = BinarySearch(arr, target, high, mid + 1);
    return result;

}


function init() {
    let arr = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12];
    let result = BinarySearch(arr, 1, arr.length - 1, 0); //(array,target,high,low)
    if (result >= 0) console.log(`Element Found at ${result}`);
    else console.log("Element not found");
}
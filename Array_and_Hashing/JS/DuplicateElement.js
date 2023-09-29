// Return true if duplicate element is there

init();

function duplicateElement(arr) {
    let slow = 0;
    let fast = 0;
    let count = 0;
    while (count != arr.length - 1) { // O(n) Time complexity
        slow = arr[slow];
        fast = arr[arr[fast]];
        if (fast == slow && count != arr.length - 1) return true;
        count++;
    }
    return false;
}


function init() {

    let arr = [1, 2, 3, 4, 5, 2];
    let result = duplicateElement(arr);
    console.log(result);
}
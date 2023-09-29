 init();


 function FindSum(arr, target) {
     let result = [];
     let temp = [];
     let hash = {}; // this how you create hash in javascript
     for (let index = 0; index < arr.length; index++) {
         let remiander = target - arr[index];
         if (hash[remiander] != undefined) {
             temp.push(arr[index]);
             temp.push(arr[hash[remiander]]);
             result.push(temp);
             temp = [];
         }
         hash[arr[index]] = index;
     }
     if (result.length > 0) return result;
     else return "No Sutaible Elements Found";
 }

 function init() {
     let arr = [2, 7, 15, 11, 5, 4];
     let target = 10;
     let result = FindSum(arr, target);
     console.log(result);
 }
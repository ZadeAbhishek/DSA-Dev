init();

function init(){
    
    let arr = [0,1,2];
    let l = arr.length;
    let result = new Array();
    for(let i = 0 ; i < Math.pow(2,l)-1; i++){
       let curr = new Array();
       for(let j = 0 ; j < l; j++){
           if(i & (1<<j)) curr.push(arr[j]);
       }
       result.push(curr);
    }
    console.log(...result);

}
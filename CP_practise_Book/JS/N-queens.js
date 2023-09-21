// gobal variable 
let dD = {};
let uD = {};
let c = {};
let arr = [[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]];

function nqueens(curCol){
    // base case 
    if(curCol === arr.length) return true;
    for(let i = 0 ; i < arr.length ; i++){
        
        if((c[i] === undefined || !c[i]) && (dD[i+curCol] === undefined || !dD[i+curCol]) && (uD[(i-curCol)+(arr.length-1)] === undefined || !uD[(i-curCol)+(arr.length-1)]))
        {
        // to check current coloum
          c[i] = true;
        
        //to check current down traingle
        
          dD[i+curCol] = true;

        //to check current upper traingle

          uD[(i-curCol)+(arr.length-1)] = true;

        arr[curCol][i] = 1;

        if(nqueens(curCol+1)) return true;

        arr[curCol][i] = 0;

        c[i] = false;

        dD[i+curCol] = false;

        uD[(i-curCol)+(arr.length-1)] = false;
        
    }

    }
    return false;

}

nqueens(0);
console.log(arr);
// TO detect Cycle we need to use BFs with previos and curr node prt 
// if curr is not vis and curr prev is not equal to prev ptr then it is already visited 
// Hence Cycle detected
class Queue {

    constructor() {
        this.data = [];
    }
    push(data) {
        this.data.push(data);
    }
    pop() {
        let curr = this.data[0];
        this.data.reverse();
        this.data.pop();
        this.data.reverse();
        return curr;
    }
    print() {
        console.log(...this.data);
    }
    empty() {
        if (this.data.length == 0) return true;
        else return false;
    }
}

init();

function insert(array,source,destination){
    let arr = array;
    arr[source].push(destination);
    arr[destination].push(source);
}


function detectCycle(arr){
  let memo = new Array(arr.length).fill(false);
  let q = new Queue();
  for(let x = 0 ; x < arr.length ; x++){
      if(memo[x]) continue;
      memo[x] = true;
      q.push([x,-1]); // [curr,prev]
      while(!q.empty()){
        let c = q.pop();
        let curr = c[0];
        let prev = c[1];
        for(let i of arr[curr]){ // of for array in for objects javascript
            if(!memo[i]){
            memo[i] = true;
            q.push([i,curr]);
            }
            else if(i != prev) return true;
        }
    }
      return false;
  }
}




function init(){
    let no_Nodes = 3;
    let nodes = new Array(no_Nodes+1).fill(null).map(()=>{return new Array()}) // peferct impleneatio
    insert(nodes,0,1);
    insert(nodes,1,2);
    insert(nodes,0,2);
    insert(nodes,2,3);
    let res = detectCycle(nodes);
    console.log(res);
}
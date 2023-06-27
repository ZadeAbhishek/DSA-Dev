// Aim is to travel tree level order 
class Tnode{
    constructor(data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}


function maxHeight(root){
    if(root === null) return 0;
    return 1 + Math.max(maxHeight(root.left),maxHeight(root.right));
}

drive();

function traveseTree(root,temp,level){
  if(root === null) return;
  temp[level].push(root.data);
  traveseTree(root.left,temp,level+1);
  traveseTree(root.right,temp,level+1);
  return;
}

function drive(){
    let root = new Tnode(0);
    let one = new Tnode(1);
    let two = new Tnode(2);
    let three = new Tnode(3);
    let four = new Tnode(4);
    let five = new Tnode(5);
    let six = new Tnode(6);
    let seven = new Tnode(7);
    let eight = new Tnode(8);
 
    root.left = one;
    root.right = two;
    one.left = three;
    one.right = four;
    two.right = six;
    two.left = five;
    five.left = seven;
    seven.left = eight; 

    let h = maxHeight(root);
    let temp = new Array(h).fill(null).map(()=>{return new Array()});
    traveseTree(root,temp,0);
    console.log(temp);

 }
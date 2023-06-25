class Tnode{
    constructor(data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

let flag = true;

function checkBT(root){
  // base case
  if(root === null) return 0;
  let l = checkBT(root.left);
  let r = checkBT(root.right);
  let h = Math.abs(l-r);
  if(h > 1) flag = false;
  return 1 + Math.max(l,r);
}


drive();

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

   //      0
   //   1     2
   //  3 4   5  6
   // True
   root.left = one;
   root.right = two;
   one.left = three;
   one.right = four;
   two.right = six;
   two.left = five;
   five.left = seven;
   seven.left = eight; 

   let res = checkBT(root);
   console.log(res,flag);
}
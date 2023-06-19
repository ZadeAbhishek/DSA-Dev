class Node{
    constructor(key,val){
        this.key = key;
        this.val = val;
        this.next = null;
        this.prev = null;
    }
}

class LRUcache{
   constructor(windowSize){
       this.windowSize = windowSize;
       this.front = new Node(-1,-1);
       this.rear = new Node(-1,-1);
       this.hash = {};
       this.front.next = this.rear; 
       this.rear.prev = this.front;
   }
   // fucntion add remove get put
   add(node){
     let ptr = this.front.next;
     this.front.next = node;
     node.prev = this.front;
     ptr.prev = node;
     node.next = ptr;
   }
   remove(node){
     node.prev.next = node.next;
     node.next.prev = node.prev;
   }
   put(key,val){
    if(this.hash[key] != undefined){
        this.remove(this.hash[key]);
        this.add(this.hash[key]);
        return `Added->${this.hash[key].val}`;
    }
    else if(Object.keys(this.hash).length == this.windowSize){
        // this means it is full
        delete this.hash[this.rear.prev.key];
        this.remove(this.rear.prev);
        let curr = new Node(key,val);
        this.add(curr);
        this.hash[key] = curr;
        return `Added->${this.hash[key].val}`;
    }
    else if(Object.keys(this.hash).length < this.windowSize){
        let curr = new Node(key,val)
        this.hash[key] = curr;
        this.add(curr);
        return `Added->${this.hash[key].val}`;
    } 
    
   }
   get(key){
    if(this.hash[key] == undefined) return `Not Found ${key}`;
    else {
        this.remove(this.hash[key]);
        this.add(this.hash[key]);
        return `Key Found ${this.hash[key].val}`;
    }

   }
   
}


let cache = new LRUcache(3);
console.log(cache.get(1)); // -1
console.log(cache.put(1,1))
console.log(cache.get(1)); // 1
console.log(cache.put(2,2))
console.log(cache.put(3,3))
console.log(cache.put(4,4))
console.log(cache.get(1));
console.log(cache.put(5,5))
console.log(cache.get(2));


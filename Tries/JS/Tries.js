class Tries {
    constructor(value = '') {
       this.children = new Map(); // <letter,new Map()>
       this.isWord = false; // to check if word or not
       this.value = value; // Value at current Tries
    }
 
    push(word) {
       let cur = this;
       for (let letter of word) { // traverse the given word
          if (!cur.children.has(letter)) cur.children.set(letter, new Tries(letter)); // if not present push it  
          cur = cur.children.get(letter); // Get to next map
       }
       cur.isWord = true; // True if word
    }
 
    checkWord(word) {
       let cur = this;
       for (let letter of word) {
          if (!cur.children.has(letter)) return false;
          cur = cur.children.get(letter);
       }
       return cur.isWord === true ? true : false;
 
    }
 
    checkPrefix(word) {
       let cur = this;
       for (let letter of word) {
          if (!cur.children.has(letter)) return false;
          cur = cur.children.get(letter);
       }
       return true;
 
    }
    /**
     * 
     * @param {String} prefix 
     * @returns last node of curr prefix
     */
    getLastPrexfix(prefix) {
       let cur = this;
       for (let letter of prefix) cur = (!cur.children.has(letter)) ? false : cur.children.get(letter);
       return cur;
    }
 
    /**
     * 
     * @param {string} letter 
     * @returns array of words
     */
    getPrefix(letter) {
       let words = [];
       let currNode = this.getLastPrexfix(letter); // get last node of prefix
       if (!currNode) return words; // if not present return false
       if (currNode.isWord) words.push(letter); // if the curr prefi is word add to words
       currNode.children.forEach((childs) => { // call of each child in childrens
          this.getAllWords(letter, childs, words);
       });
       return words;
    }
 
    /**
     * 
     * @param {string} prefix 
     * @param {Tries} childs 
     * @param {[]} words 
     * @returns []
     */
    getAllWords(prefix, childs, words) {
       if (!childs) return words;
       prefix += childs.value;
       if (childs.isWord) words.push(prefix);
       childs.children.forEach((c) => {
          this.getAllWords(prefix, c, words);
       });
       return words;
    }
 
    /**
     * 
     * @param {string} word 
     * @returns 
     */
    remove(word) {
       if (!word) return false;
       let curr = this;
       let stack = [];
 
       // add all node into stack correspond to words
       for (let x of word) {
          if (!curr.children.has(x)) return false;
          stack.push(curr);
          curr = curr.children.get(x);
       }
       curr.isWord = false;
       // remove curr's child having value prev.value
       while (stack.length > 1 && !curr.isWord) {
          let prev = curr;
          curr = stack.pop();
          if (prev.children.length > 0) break;
          curr.children.delete(prev.value);
       }
 
       return true;
    }
 };
 
 let t = new Tries();
 t.push("Abhi");
 t.push("Asshole");
 t.push("Apple");
 console.log(t.checkPrefix("As"));
 let c = t.getPrefix("A");
 console.log(c);
 t.remove("Abhi");
 t.remove("Apple");
 c = t.getPrefix("A");
 console.log(c);

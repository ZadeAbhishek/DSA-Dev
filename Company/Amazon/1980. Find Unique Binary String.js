
var createDecimal = function(binary) {
    let base10 = 0;
    for (let i = 0; i < binary.length; i++) {
        if (binary[i] === '1') {
            base10 += Math.pow(2, binary.length - 1 - i);
        }
    }
    return base10;
};

var base2 = function(x, length) {
    let s = "";
    for (let i = length - 1; i >= 0; i--) {
        let mask = 1 << i;
        if (mask & x) s += '1';
        else s += '0';
    }
    return s;
};

var findDifferentBinaryString = function(nums) {
    let hash = new Set();
    for (let str of nums) {
        hash.add(createDecimal(str));
    }

    let n = nums.length;
    for (let i = 0; i < Math.pow(2, n); i++) {
        if (!hash.has(i)) {
            return base2(i, n);
        }
    }
    
    return;
};
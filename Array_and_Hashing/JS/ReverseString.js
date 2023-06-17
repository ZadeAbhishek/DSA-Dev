// Not working 

init();

function swap(r, x, y) {
    let temp;
    temp = r[x];
    r[x] = r[y];
    r[y] = temp;
    return r;
}

function reverse(s) {

    let len = s.length;
    let r = s.slice();
    let temp = '',
        i = 0,
        j = len - 1;

    while (i <= j) swap(r, i, j), i++, j--;

    console.log(r);

    return r;
}



function init() {

    let s = "]ecitcarP smhtiroglA arodef-derahs@rekcah[";

    let r = reverse(s);

    console.log(r);
}
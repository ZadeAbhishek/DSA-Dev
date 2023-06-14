let states = {
    draw: 'HOLD',
    focusCenter: false,
    drawing: [],
    cursorX: 0,
    cursorY: 0,
    prevcursorX: 0,
    prevcursorY: 0,
    offsetX: 0,
    offsetY: 0,
    scale: 1,
    prevTouches: [null, null],
    touch0x: 0,
    touch0y: 0,
    touch1x: 0,
    touch1y: 0,
    prevTouch0x: 0,
    prevTouch0y: 0,
    prevTouch1x: 0,
    prevTouch1y: 0,
    canvas: document.getElementById("board"),
    strokeStyle: '#fff',
    strokeWidth: 2,


}

export default function varaible() {
    return states;
}

export function setdraw(state) {
    states.draw = state;
}
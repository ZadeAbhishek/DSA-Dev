import React, { useEffect, useState } from 'react'
import './Board.css'
import varaible from '../Compoenets/variable';

let global = varaible();

export function redrawCanvas() {
    global.canvas.width = document.body.clientWidth;
    global.canvas.height = document.body.clientHeight;
    const context = global.canvas.getContext("2d");
    context.fillstyle = '#fff';
    context.fillRect(0, 0, global.canvas.width, global.canvas.height);
    for (let i = 0; i < global.drawing.length; i++) {
        const line = global.drawing[i];
        drawline(toscreenX(line.x0), toscreenY(line.y0), toscreenX(line.x1), toscreenY(line.y1),global.drawing[i].strokeStyle,global.drawing[i].lineWidth)
    }
}

function toscreenX(xTrue) {
    return (xTrue + global.offsetX) * global.scale;
}

function toscreenY(yTrue) {
    return (yTrue + global.offsetY) * global.scale;
}

// screen to original coordinate
function totrueX(xscreen) {
    return (xscreen / global.scale) - global.offsetX;
}


function totrueY(yscreen) {
    return (yscreen / global.scale) - global.offsetY;
}

function trueHeight() {
    return global.canvas.clientHeight / global.scale;
}

function trueWidth() {
    return global.canvas.clientWidth / global.scale;
}


function drawline(x0, y0, x1, y1,color,lineWidth) {
    const context = global.canvas.getContext("2d");
    context.beginPath();
    context.moveTo(x0, y0);
    context.lineTo(x1, y1);
    context.strokeStyle = color;
    context.lineWidth = lineWidth;
    context.stroke();
}



export default function Board() {

    useEffect(() => {

        global.canvas = document.getElementById("board");

        //disable right click
        document.oncontextmenu = function() {
            return false;
        }

        redrawCanvas();

        window.addEventListener("resize", (e) => {
            redrawCanvas();
        });

        global.canvas.addEventListener('mousedown', mouseDown);
        global.canvas.addEventListener('mouseup', mouseUp, false);
        global.canvas.addEventListener('mousemove', mouseMove, false);
        global.canvas.addEventListener('wheel', mouseWheel, false);

        global.canvas.addEventListener('touchstart', touchStart);
        global.canvas.addEventListener('touchend', touchEnd);
        global.canvas.addEventListener('touchmove', touchMove);
      }, []);


        let leftmouseDown = false;
        let rightMouseDown = false;

        function mouseDown(e) {

            if (e.button === 0) {
                leftmouseDown = true;
                rightMouseDown = false;
            }
            if (e.button === 2) {
                leftmouseDown = false;
                rightMouseDown = true;
            }

            // update cursor coordinates
            global.cursorX = e.pageX;
            global.cursorY = e.pageY;
            global.prevcursorX = e.pageX;
            global.prevcursorY = e.pageY;
        }

        function mouseUp() {
            leftmouseDown = false;
            rightMouseDown = false;
        }

        function mouseMove(e) {

            if (leftmouseDown) {
                global.cursorX = e.pageX;
                global.cursorY = e.pageY;

                const scaledx = totrueX(global.cursorX);
                const scaledy = totrueY(global.cursorY);
                const prevscaledx = totrueX(global.prevcursorX);
                const prevscaledy = totrueY(global.prevcursorY);
                if (global.draw === 'DRAW') {
                    global.drawing.push({
                        x0: prevscaledx,
                        y0: prevscaledy,
                        x1: scaledx,
                        y1: scaledy,
                        strokeStyle:global.strokeStyle,
                        lineWidth:global.strokeWidth,
                    })

                    drawline(global.prevcursorX, global.prevcursorY, global.cursorX, global.cursorY,global.strokeStyle,global.strokeWidth);
                }

                if (global.draw === 'PAN') {
                    global.offsetX += (global.cursorX - global.prevcursorX) / global.scale;
                    global.offsetY += (global.cursorY - global.prevcursorY) / global.scale;
                    redrawCanvas();
                }
            }
            global.prevcursorX = global.cursorX;
            global.prevcursorY = global.cursorY;

        }

        function mouseWheel(e) {
            const deltY = e.deltaY;
            const scaleAmount = -deltY / 500;
            global.scale = global.scale * (1 + scaleAmount);

            // zoom the page basaed on wher curson is

            var distx = e.pageX / global.canvas.clientHeight;
            var disty = e.pageY / global.canvas.clientWidth;



            // calcualte how we need to zoom
            const unitZoomedx = trueHeight() * scaleAmount;
            const unitZoomedy = trueWidth() * scaleAmount;

            const unitAddLeft = unitZoomedx * distx;
            const unitAddRight = unitZoomedy * disty;


            global.offsetX -= unitAddLeft;
            global.offsetY -= unitAddRight;


            redrawCanvas();
        }

       

        let singleTouche = false;
        let doubleTouche = false;

        function touchStart(e) {
            if (e.touches.length === 1) {
                singleTouche = true;
                doubleTouche = false;
            }

            if (e.touches.length >= 2) {
                singleTouche = false;
                doubleTouche = true;
            }

            global.prevTouches[0] = e.touches[0];
            global.prevTouches[1] = e.touches[1];
        }

        function touchEnd(e) {
            singleTouche = false;
            doubleTouche = false;
        }

        function touchMove(e) {
            global.touch0x = e.touches[0].pageX;
            global.touch0y = e.touches[0].pageY;
            global.prevTouch0x = global.prevTouches[0].pageX;
            global.prevTouch0y = global.prevTouches[0].pageY;

            const scaledx = totrueX(global.touch0x);
            const scaledy = totrueY(global.touch0y);
            const prevscaledx = totrueX(global.prevTouch0x);
            const prevscaledy = totrueY(global.prevTouch0y);

            if (singleTouche) {
                if(global.draw === 'DRAW'){
                global.drawing.push({
                    x0: prevscaledx,
                    y0: prevscaledy,
                    x1: scaledx,
                    y1: scaledy,
                    strokeStyle:global.strokeStyle,
                    lineWidth:global.strokeWidth,
                })

                drawline(global.prevTouch0x, global.prevTouch0y, global.touch0x, global.touch0y,global.strokeStyle,global.strokeWidth);
            
                }
                if (global.draw === 'PAN') {
                    global.offsetX += (global.touch0x - global.prevTouch0x) / global.scale;
                    global.offsetY += (global.touch0y - global.prevTouch0y) / global.scale;
                    redrawCanvas();
                }

            
            }

            if (doubleTouche) {
                // important 

                // get second coordinate curr and pevious
                global.touch1x = e.touches[1].pageX;
                global.touch1y = e.touches[1].pageY;
                global.prevTouch1x = global.prevTouches[1].pageX;
                global.prevTouch1y = global.prevTouches[1].pageY;

                // get mid point for curr and previous
                const midx = (global.touch0x + global.touch1x) / 2;
                const midy = (global.touch0y + global.touch1y) / 2;

                const prevmidx = (global.prevTouch0x + global.prevTouch1x) / 2;
                const prevmidy = (global.prevTouch0y + global.prevTouch1y) / 2;

                // calcualte distance between touches 
                const hypot = Math.sqrt(Math.pow((global.touch0x - global.touch1x), 2) + Math.pow((global.touch0y - global.touch1y), 2));
                const prevHypot = Math.sqrt(Math.pow((global.prevTouch0x - global.prevTouch1x), 2) + Math.pow((global.prevTouch0y - global.prevTouch1y), 2));

                // calcuate screen scale values
                var zoomAmount = hypot / prevHypot;
                global.scale *= zoomAmount; // change scale
                const scaleAmount = 1 - zoomAmount; // how much we have scale since zoomount is always between 0 to 1

                //cal how many pixel to be move in x and y dir
                const panX = midx - prevmidx; // deltx
                const panY = midy - prevmidy; // delyy

                //scale this based on zoom level
                global.offsetX += (panX / global.scale); // make changes to global x
                global.offsetY += (panY / global.scale); // make changes to global y

                //get realtive position of zoom
                var zoomRatioX = midx / global.canvas.clientWidth; // curr position of x according to scale
                var zoomRatioY = midy / global.canvas.clientHeight; // curr position of y according to scale

                const unitZoomedX = trueWidth() * scaleAmount; // how much zoom in x
                const unitZoomedy = trueHeight() * scaleAmount; // how much zoom in y

                const unitLeft = unitZoomedX * zoomRatioX; // cal curr left
                const unitTop = unitZoomedy * zoomRatioY; // cal curr top

                global.offsetX += unitLeft; // add to gobal
                global.offsetY += unitTop;

                redrawCanvas(); // redraw
            }
            global.prevTouches[0] = e.touches[0];
            global.prevTouches[1] = e.touches[1];
        }




    return ( <canvas id = "board" > Board </canvas>
    )
}
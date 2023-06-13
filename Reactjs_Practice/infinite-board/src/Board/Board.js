import React, { useEffect } from 'react'
import './Board.css'
export default function Board() {


  

  useEffect(()=>{
    const canvas = document.getElementById("board");
    const context = canvas.getContext("2d");

    //disable right click
    document.oncontextmenu = function(){
    return false;
   }

   // list of stroks all strocks drawn
   const drawing = [];

   //coordinate of our cursor
   let cursorX;
   let cursorY;
   let prevcursorX;
   let prevcursorY;

   //distance from origin
   let offsetX = 0;
   let offsetY = 0;

   //zoom amount
   let scale = 1;

   //convert coordinate

   // we are going to convert in two ways 
   // orignal to screen so we have normal coordinate we are converting to current scale
   function toscreenX(xTrue){
    return (xTrue + offsetX) * scale;
   }
   function toscreenY(yTrue){
    return (yTrue + offsetY) * scale;
   }

   // screen to original coordinate
   function totrueX(xscreen){
     return (xscreen / scale) - offsetX;
   }
    

   function totrueY(yscreen){
    return (yscreen / scale) - offsetY;
  }

  function trueHeight(){
    return canvas.clientHeight / scale;
  }
  
  function trueWidth(){
    return canvas.clientWidth / scale;
  }

  function redrawCanvas(){
    canvas.width = document.body.clientWidth;
    canvas.height = document.body.clientHeight;

    context.fillstyle = '#fff';
    context.fillRect(0,0,canvas.width,canvas.height);
    //console.log(drawing);
    for(let i = 0 ; i < drawing.length; i++){
       const line = drawing[i];
       drawline(toscreenX(line.x0),toscreenY(line.y0),toscreenX(line.x1),toscreenY(line.y1))
    }
  }
   
  redrawCanvas();
  
  window.addEventListener("resize",(e)=>{
    redrawCanvas();
  });
 
  canvas.addEventListener('mousedown',mouseDown);
  canvas.addEventListener('mouseup',mouseUp ,false);
  canvas.addEventListener('mousemove',mouseMove, false);
  canvas.addEventListener('wheel',mouseWheel,false);


  let leftmouseDown = false;
  let rightMouseDown = false;

  function mouseDown(e){
    console.log(e.button);

     if(e.button === 0) {
      leftmouseDown = true;  
      rightMouseDown = false;
     }
     if(e.button === 2) {
      leftmouseDown = false;  
      rightMouseDown = true;
     }

     // update cursor coordinates
     cursorX = e.pageX;
     cursorY = e.pageY;
     prevcursorX = e.pageX;
     prevcursorY = e.pageY;
  }

  function mouseUp(){
    leftmouseDown = false;
    rightMouseDown = false;
  }

  function mouseMove(e){
     cursorX = e.pageX;
     cursorY = e.pageY;

     const scaledx = totrueX(cursorX);
     const scaledy = totrueY(cursorY);
     const prevscaledx = totrueX(prevcursorX);
     const prevscaledy = totrueY(prevcursorY);

     if(leftmouseDown){
      drawing.push({
        x0:prevscaledx,
        y0:prevscaledy,
        x1:scaledx,
        y1:scaledy,
      })
  
      drawline(prevcursorX,prevcursorY,cursorX,cursorY);
     }

     if(rightMouseDown){
       offsetX += (cursorX - prevcursorX)/scale;
       offsetY += (cursorY - prevcursorY)/scale;
       redrawCanvas();
     }
     prevcursorX = cursorX;
     prevcursorY = cursorY;
  }

  function mouseWheel(e){
    const deltY = e.deltaY;
    const scaleAmount = -deltY/500;
    scale = scale * (1+scaleAmount);

    // zoom the page basaed on wher curson is
    
    var distx = e.pageX / canvas.clientHeight;
    var disty = e.pageY / canvas.clientWidth;

     

    // calcualte how we need to zoom
    const unitZoomedx = trueHeight() *scaleAmount;
    const unitZoomedy = trueWidth() * scaleAmount;

    console.log(unitZoomedx,unitZoomedy);
    const unitAddLeft = unitZoomedx * distx;
    const unitAddRight = unitZoomedy * disty;

    offsetX -= unitAddLeft;
    offsetY -= unitAddRight;

    redrawCanvas();
  }

  canvas.addEventListener('touchstart',touchStart);
  canvas.addEventListener('touchend',touchEnd);
  canvas.addEventListener('touchmove',touchMove);

  const prevTouches = [null,null];
  let singleTouche = false;
  let doubleTouche = false;

  function touchStart(e){
     if(e.touches.length === 1){
      singleTouche = true;
      doubleTouche = false;
     }

     if(e.touches.length >= 2){
      singleTouche = false;
      doubleTouche = true;
     }

     prevTouches[0] = e.touches[0];
     prevTouches[1] = e.touches[1];
  }
  function touchEnd(e){
    
  }
  function touchMove(e){
    const touch0x = e.touches[0].pageX;
    const touch0y = e.touches[0].pageY;
    const prevTouch0x = prevTouches[0].pageX;
    const prevTouch0y = prevTouches[0].pageY;
   
    const scaledx = totrueX(touch0x);
    const scaledy = totrueY(touch0y);
    const prevscaledx = totrueX(prevTouch0x);
    const prevscaledy = totrueY(prevTouch0y);

    if(singleTouche){
     drawing.push({
       x0:prevscaledx,
       y0:prevscaledy,
       x1:scaledx,
       y1:scaledy,
     })
 
     drawline(prevTouch0x,prevTouch0y,touch0x,touch0y);
    }

    if(doubleTouche){
      // important 
    }
    prevTouches[0] = e.touches[0];
  }


  function drawline(x0,y0,x1,y1){
     context.beginPath();
     context.moveTo(x0,y0);
     context.lineTo(x1,y1);
     context.strokeStyle = '#fff';
     context.lineWidth = 2;
     context.stroke();
  }

    return () => {
      canvas.removeEventListener('mousedown',mouseDown);
      canvas.removeEventListener('mouseup',mouseUp);
      canvas.removeEventListener('mousemove',mouseMove);
      canvas.removeEventListener('wheel',mouseWheel);
    }
  },[]);
  

  

  return (
    <canvas id="board">Board</canvas>
  )
}

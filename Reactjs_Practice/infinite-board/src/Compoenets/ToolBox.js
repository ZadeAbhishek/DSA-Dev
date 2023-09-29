import React, { useEffect } from 'react'
import './ToolBox.css'
import varaible from './variable';
import { redrawCanvas } from '../Board/Board';
import {useState} from 'react';


let global = varaible();

export default function ToolBox() {
  
  useEffect(() => {

    // document.querySelector('.sbm').addEventListener('click',loadBoard);
    // document.getElementById('drawBtn').addEventListener('mousedown',draw);
    // document.getElementById('drawBtn').addEventListener('touchstart',draw);

  }, []);


  
  

  function draw(){
    global.draw = 'DRAW';
  }


  function pan(){
    console.log("PAN");
    global.draw = 'PAN';
  }

  function setCentre(){
    global.offsetX = 0;
    global.offsetY = 0;
    global.scale = 1;
    redrawCanvas();
  }

 function strokeColor(color){
    global.strokeStyle = color;
 }
 
  const [strokeWidth, setstrokeWidth] = useState(2);

 function strokeChange(){
  const strokevalue = document.getElementById("customRange1");
  setstrokeWidth(strokevalue.value);
  global.strokeWidth = strokeWidth;

}

function loadBoard(){
  if(document.querySelector('.file').files[0] === undefined){
    alert("No file Selected");
    return;
  }
  let fileReader = new FileReader();
  fileReader.onload = function () {
      let parsedJSON = JSON.parse(fileReader.result);
      global.drawing = parsedJSON;
      redrawCanvas();                 
  }
  console.log(document.querySelector('.file').files[0]);
  fileReader.readAsText(document.querySelector('.file').files[0]);
}

function saveBoard(){
  const blob = new Blob([JSON.stringify(global.drawing, null, 6)], {type : 'application/json'});
  const a = document.createElement('a');
  a.href = URL.createObjectURL(blob);
  a.download = `${global.projectName}.json`;
  a.click();
}

function saveImage(){
  var canvas = global.canvas
   const dataUrl = canvas.toDataURL("image/png");
   const anchor = document.createElement('a');
   anchor.href = dataUrl;
   anchor.download = `${global.projectName}.png`;
   anchor.click();
}

  return (
<>
 <div className="strockInpu">
 <label htmlFor="customRange1" className="form-label">Stroke</label>
<input type="range" min='2' max='15' value={strokeWidth} className="form-range" id="customRange1" onChange={strokeChange}></input>
</div>

<div className="btn-group color-btn-grp" role="group" aria-label="Basic mixed styles example">
  <button onClick={()=>strokeColor("blue")}type="button" className="btn btn-primary   btn-lg"> </button>
  <button onClick={()=>strokeColor("red")} type="button" className="btn btn-danger  btn-lg"> </button>
  <button onClick={()=>strokeColor("yellow")} type="button" className="btn btn-warning  btn-lg"></button>
  <button onClick={()=>strokeColor("green")} type="button" className="btn btn-success  btn-lg"></button>
  <button onClick={()=>strokeColor("#fff")} type="button" className="btn btn-light  btn-lg"></button>
</div>

    <div  className="btn-group-vertical" role="group" aria-label="Vertical button group">
  <button onClick={draw} id="drawBtn" type="button" className="btn btn-light"><svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" className="bi bi-pencil" viewBox="0 0 16 16">
  <path d="M12.146.146a.5.5 0 0 1 .708 0l3 3a.5.5 0 0 1 0 .708l-10 10a.5.5 0 0 1-.168.11l-5 2a.5.5 0 0 1-.65-.65l2-5a.5.5 0 0 1 .11-.168l10-10zM11.207 2.5 13.5 4.793 14.793 3.5 12.5 1.207 11.207 2.5zm1.586 3L10.5 3.207 4 9.707V10h.5a.5.5 0 0 1 .5.5v.5h.5a.5.5 0 0 1 .5.5v.5h.293l6.5-6.5zm-9.761 5.175-.106.106-1.528 3.821 3.821-1.528.106-.106A.5.5 0 0 1 5 12.5V12h-.5a.5.5 0 0 1-.5-.5V11h-.5a.5.5 0 0 1-.468-.325z"/>
</svg></button>

<button onClick={pan}  id="PanBtn" type="button" className="btn btn-light"><svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" className="bi bi-hand-index" viewBox="0 0 16 16">
  <path d="M6.75 1a.75.75 0 0 1 .75.75V8a.5.5 0 0 0 1 0V5.467l.086-.004c.317-.012.637-.008.816.027.134.027.294.096.448.182.077.042.15.147.15.314V8a.5.5 0 1 0 1 0V6.435a4.9 4.9 0 0 1 .106-.01c.316-.024.584-.01.708.04.118.046.3.207.486.43.081.096.15.19.2.259V8.5a.5.5 0 0 0 1 0v-1h.342a1 1 0 0 1 .995 1.1l-.271 2.715a2.5 2.5 0 0 1-.317.991l-1.395 2.442a.5.5 0 0 1-.434.252H6.035a.5.5 0 0 1-.416-.223l-1.433-2.15a1.5 1.5 0 0 1-.243-.666l-.345-3.105a.5.5 0 0 1 .399-.546L5 8.11V9a.5.5 0 0 0 1 0V1.75A.75.75 0 0 1 6.75 1zM8.5 4.466V1.75a1.75 1.75 0 1 0-3.5 0v5.34l-1.2.24a1.5 1.5 0 0 0-1.196 1.636l.345 3.106a2.5 2.5 0 0 0 .405 1.11l1.433 2.15A1.5 1.5 0 0 0 6.035 16h6.385a1.5 1.5 0 0 0 1.302-.756l1.395-2.441a3.5 3.5 0 0 0 .444-1.389l.271-2.715a2 2 0 0 0-1.99-2.199h-.581a5.114 5.114 0 0 0-.195-.248c-.191-.229-.51-.568-.88-.716-.364-.146-.846-.132-1.158-.108l-.132.012a1.26 1.26 0 0 0-.56-.642 2.632 2.632 0 0 0-.738-.288c-.31-.062-.739-.058-1.05-.046l-.048.002zm2.094 2.025z"/>
</svg></button>

  <button  onClick={setCentre} type="button" className="btn btn-light"><svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" className="bi bi-arrows-angle-contract" viewBox="0 0 16 16">
  <path fillRule="evenodd" d="M.172 15.828a.5.5 0 0 0 .707 0l4.096-4.096V14.5a.5.5 0 1 0 1 0v-3.975a.5.5 0 0 0-.5-.5H1.5a.5.5 0 0 0 0 1h2.768L.172 15.121a.5.5 0 0 0 0 .707zM15.828.172a.5.5 0 0 0-.707 0l-4.096 4.096V1.5a.5.5 0 1 0-1 0v3.975a.5.5 0 0 0 .5.5H14.5a.5.5 0 0 0 0-1h-2.768L15.828.879a.5.5 0 0 0 0-.707z"/>
</svg></button>
</div> 
   
    <div className="dropup-center dropup">
    <button className="btn btn-secondary dropdown-toggle btn-light" type="button" data-bs-toggle="dropdown" aria-expanded="false">
    <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" className="bi bi-gear" viewBox="0 0 16 16">
  <path d="M8 4.754a3.246 3.246 0 1 0 0 6.492 3.246 3.246 0 0 0 0-6.492zM5.754 8a2.246 2.246 0 1 1 4.492 0 2.246 2.246 0 0 1-4.492 0z"/>
  <path d="M9.796 1.343c-.527-1.79-3.065-1.79-3.592 0l-.094.319a.873.873 0 0 1-1.255.52l-.292-.16c-1.64-.892-3.433.902-2.54 2.541l.159.292a.873.873 0 0 1-.52 1.255l-.319.094c-1.79.527-1.79 3.065 0 3.592l.319.094a.873.873 0 0 1 .52 1.255l-.16.292c-.892 1.64.901 3.434 2.541 2.54l.292-.159a.873.873 0 0 1 1.255.52l.094.319c.527 1.79 3.065 1.79 3.592 0l.094-.319a.873.873 0 0 1 1.255-.52l.292.16c1.64.893 3.434-.902 2.54-2.541l-.159-.292a.873.873 0 0 1 .52-1.255l.319-.094c1.79-.527 1.79-3.065 0-3.592l-.319-.094a.873.873 0 0 1-.52-1.255l.16-.292c.893-1.64-.902-3.433-2.541-2.54l-.292.159a.873.873 0 0 1-1.255-.52l-.094-.319zm-2.633.283c.246-.835 1.428-.835 1.674 0l.094.319a1.873 1.873 0 0 0 2.693 1.115l.291-.16c.764-.415 1.6.42 1.184 1.185l-.159.292a1.873 1.873 0 0 0 1.116 2.692l.318.094c.835.246.835 1.428 0 1.674l-.319.094a1.873 1.873 0 0 0-1.115 2.693l.16.291c.415.764-.42 1.6-1.185 1.184l-.291-.159a1.873 1.873 0 0 0-2.693 1.116l-.094.318c-.246.835-1.428.835-1.674 0l-.094-.319a1.873 1.873 0 0 0-2.692-1.115l-.292.16c-.764.415-1.6-.42-1.184-1.185l.159-.291A1.873 1.873 0 0 0 1.945 8.93l-.319-.094c-.835-.246-.835-1.428 0-1.674l.319-.094A1.873 1.873 0 0 0 3.06 4.377l-.16-.292c-.415-.764.42-1.6 1.185-1.184l.292.159a1.873 1.873 0 0 0 2.692-1.115l.094-.319z"/>
</svg>
    </button>
    <ul className="dropdown-menu">
      <li className='setting-li' ><a onClick={saveImage} className="dropdown-item">Save Image</a></li>
      <li className='setting-li' onClick={saveBoard}><a className="dropdown-item">Save Board</a></li>
      <li className='setting-li' ><input type="file" className="file"></input></li>
      <li className='setting-li'><button className='btn btn-primary' onClick={loadBoard}>Submit</button></li>
    </ul>
  </div>
  </>
  )
}

import './App.css';
import { useState } from "react";

let k = 1;
function App() {
  
  const [arr, setarr] = useState([]);

  const [str, setstr] = useState("");

  const pusharr = ()=>{
     arr.push(str);
    setstr("");
     setarr(arr);
  }

  const poparr = (e)=>{
    console.log(e.target.id);
    setarr(arr.filter((item)=> item!==e));
    return;
 }
  
  return (
    <div className="App">

<form>
     <div className="row">
   <div className="col">
    <input type="text" className="form-control" value={str} onChange={(e)=>{setstr(e.target.value)}}  placeholder="String 1" />
  </div>
</div>
<div className="d-grid gap-2 col-6 mx-auto pt-5">
  <button className="btn btn-dark" onClick={pusharr} type="button">Submit</button>
</div>
</form>
  <div className="text-center">
    {arr.map((s)=>{ 
      return <div key={k}>
        <span className="foo" name={s} >{s}</span>
        <button className="btn" id={k++} onClick={poparr} type="button">Delete</button>
        </div>
      })}
        
  </div>

    </div>
  );
}

export default App;

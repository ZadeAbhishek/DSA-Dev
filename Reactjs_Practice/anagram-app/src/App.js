import './App.css';
import { useState} from "react";

function Anagram(s, r) {

  // Buffer to store char count
  let Buffer = new Array(128).fill(0); // O(128) ~ O(1)

  for (let c of s) Buffer[c.charCodeAt(c)]++; //O(n)

  for (let c of r) Buffer[c.charCodeAt(c)]--; //O(n)

  for (let c of Buffer) //O(1)
      if (c > 0) return false;

  return true;
}


function App() {
  const [output, setoutput] = useState("");
  const [str1, setstr1] = useState("");
  const [str2, setstr2] = useState("");
  const changeOutput = ()=>{
    
    let result = Anagram(str1,str2);
    if(result) setoutput("Anagram");
    else setoutput("Not a Anagram")
  }
  return (
    <div className="">
      <form>
     <div className="row">
   <div className="col">
    <input type="text" className="form-control" value={str1} onChange={(e)=>setstr1(e.target.value)} placeholder="String 1" />
  </div>
  <div className="col">
    <input type="text" className="form-control" value={str2} onChange={(e)=>setstr2(e.target.value)}  placeholder="String 2" />
  </div>
</div>
<div className="d-grid gap-2 col-6 mx-auto pt-5">
  <button className="btn btn-dark" type="button" onClick={changeOutput}>Check</button>
</div>
</form>
<div className="text-center pt-5">
 <h2>{output}</h2>
</div>
    </div>
  );
}

export default App;

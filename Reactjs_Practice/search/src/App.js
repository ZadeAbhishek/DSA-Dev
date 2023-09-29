import React, { useEffect } from 'react';
import './App.css';
import data from './data/data.js'
function App() {
   
  const [users, setusers] = React.useState([]);
  const [final, setFinal] = React.useState([]);
  const [input, setInput] = React.useState("");
  
  const inputSet = (s)=>{
    setInput(s);
  }
  
  useEffect(()=>{
     const final_list = users.filter((u)=>{return Object.values(u).join("").toLowerCase().includes(input.toLowerCase())});
     setFinal(final_list);
  },[input]);

  React.useEffect(()=>{
     setusers(data);
  },[])


  return (
    <>
    <div className="App">
      <input className='search' onChange={(e)=>{inputSet(e.target.value)}} type='search' placeholder='Seach Name.....'></input>
    </div>
     <div className="grid">
     
     {
       final.map((user,index)=>{
        return <div key={index} className="grid-child">
     <h4>{user.name}</h4>
     <p>{user.age}</p>
     </div>})}
 </div>
 </>

  );
}

export default App;

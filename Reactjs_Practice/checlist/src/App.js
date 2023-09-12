import React, { useEffect, useState } from 'react';
import './App.css';
import { List } from './Components/List';

let data = ["check Car", "check Watch", "check Keys"];


function App() {
  const [list, setlist] = React.useState([]);
  const [checks, setchecks] = React.useState([]);
  const checkBox = (idx)=>{
     const temp = checks.map((item,id)=>{ return (idx == id?!item:item )})
     setchecks(temp);
  }
   
  useEffect(()=>{
    setlist(data);
    const temp = new Array(data.length).fill(false);
    setchecks(temp);
  },[])

  const deleteItem = (idx)=>{
      // idex == index
      const newList = list.filter((item,id)=> {return id!=idx}); // basic update list
      setlist(newList);
  }
  return (
    <div className="App">
      <List list={list} deleteItem={deleteItem} checks={checks} checkBox={checkBox} />
    </div>
  );
}

export default App;

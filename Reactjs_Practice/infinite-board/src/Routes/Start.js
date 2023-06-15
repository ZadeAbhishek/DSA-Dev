import React from 'react'
import varaible from '../Compoenets/variable'
import './Start.css'
import {useState} from 'react';
import {useNavigate} from 'react-router-dom';
import reactlogo from '../Logo/INFINITE BOARD-logo.png'
let gobal = varaible();



export default function Start() {

    const [ProjectName, setProjectName] = useState("");
    const navigate = useNavigate();

const set = e =>{
   e.preventDefault();
   console.log(ProjectName);
   if(ProjectName === "") gobal.projectName = "Untitled";
   else gobal.projectName = ProjectName;
   navigate('board');
}
  return (
   <> 

 

   <div id="welcone-Screen">
   <img src={reactlogo} alt="INFINTE BOARD" width="500" height="600"/>
   </div>

  <div id="user-name-form">  
  <form onSubmit={set} >
  <div className="row">
    <div className="col">
      <input value={ProjectName} onChange={(e)=>{setProjectName(e.target.value)}} type="text" className="form-control" placeholder="Project name"/>
    </div>
    <div className="col">
    <button type="submit" className="btn btn-light">Submit</button>
    </div>
  </div>
</form>
</div>
</>

  )
}

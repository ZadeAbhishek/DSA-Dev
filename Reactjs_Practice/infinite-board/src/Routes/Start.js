import React from 'react'
import varaible from '../Compoenets/variable'
import './Start.css'
import {useState} from 'react';
import { setBoardApp } from '../App';
import {useNavigate} from 'react-router-dom';

let gobal = varaible();



export default function Start() {

    const [ProjectName, setProjectName] = useState(gobal.projectName);
    const navigate = useNavigate();

const set = e =>{
   e.preventDefault();
   console.log(ProjectName); 
   gobal.projectName = ProjectName;
   navigate('board');
}
  return (
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

  )
}

import React from 'react'
import varaible from './variable'
import './Header.css'

let global = varaible();
global.projectName = prompt("Please enter Project Name")||"untitled"; 
export default function Header() {
   
  return (
    <div id="projectName">{global.projectName}</div>
  )
}

import React from 'react'
import varaible from './variable'
import './Header.css'

let global = varaible();
const name = prompt("Please enter Project Name")||"untitled";
export default function Header() {
global.projectName = name;
  return (
    <div id="projectName">{global.projectName}</div>
  )
}

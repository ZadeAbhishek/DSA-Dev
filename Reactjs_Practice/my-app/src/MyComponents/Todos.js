import React from 'react'
import TodoItems from './TodoItems'

export default function Todos(props) {
  return (
    <div className = "container">
      <h3 className="text-center my-3">Todos List</h3>
      {props.todos.length===0?"Not Todos to Display": props.todos.map((todo)=>{
         return <TodoItems todo = {todo} key = {todo} onDelete={props.onDelete}/> })
      }  
   </div>
  )
}

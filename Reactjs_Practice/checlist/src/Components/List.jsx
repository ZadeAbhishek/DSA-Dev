import React from 'react'
import "../CSS/List.css"
export const List = ({list,deleteItem,checks,checkBox}) => {
  return (
    <>
    {list.map((item,id) =>{
            return <div key={id} className="list-container">
                 <input type="checkbox" className="check" onClick={()=>{checkBox(id)}}/>
                 {item}
                 {checks[id] && <button className="btn" onClick={(e)=>{deleteItem(id)}}>Remove</button>}
            </div>
    })}
    </>
  )
}

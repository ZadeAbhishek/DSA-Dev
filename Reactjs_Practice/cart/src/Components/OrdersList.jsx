import React from 'react'
import "../Css/OrderList.css"


const OrdersList = (props) => {
  return (
      <tr>
        <td>
        <div className='item-card'>
        <img className='img-size' src={`${props.item.img_url}`}></img>{props.item.name}
        <button className='btn remove-btn' onClick={()=>{props.removeIteam(props.item.id)}} >X</button>
        </div>
        </td>
        <td>
          <div className='qty-div'>
           <button className='btn drc-btn' onClick={()=>{props.counter(props.item.id,-1)}}>-</button>
           {props.item.count}
           <button className='btn inc-btn' onClick={()=>{props.counter(props.item.id,1)}}>+</button>
           </div>
        </td>
        <td>
          <div className="price-div">
        ${props.item.price * props.item.count}
        </div>    
        </td>
        </tr>
  )
}

export default OrdersList
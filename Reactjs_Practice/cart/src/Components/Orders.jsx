import React from 'react'
import '../Css/Orders.css'
import OrdersList from './OrdersList'


const Orders = (props) => {
  return (
  
     <div className="table-wapper">
      <table className="table">
        <thead>
          <tr>
            <th className='expand'>Item({props.data.length})</th>
            <th className='qty-expand'>Quantity</th>
            <th>Price</th>
          </tr>
        </thead>
        <tbody>
         
         {props.data.map((item,idx)=>{ return <OrdersList key={idx} item={item} counter={props.counter} removeIteam={props.removeIteam} />})} 

        </tbody>
      </table>
     </div>
     
  )
}

export default Orders
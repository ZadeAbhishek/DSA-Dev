import React, { useEffect } from 'react'
import "../Css/Cart.css"
import data from "./data.js"
import Orders from './Orders';
import Bill from './Bill';
const Cart = () => {

  const [userData, setuserData] = React.useState([]);
  const [bills, setbills] = React.useState([])
  let totalPrice;
  const counter = (idx,i)=>{
     setuserData(userData.map((item)=>{
       if(idx == item.id && item.count >= 0)  item.count+= item.count+i<0?0:i;
       return item;
    }))
  }

  const removeIteam = (idx)=>{
    setuserData(userData.filter((item)=>{return idx!=item.id}))
  }
  
  
  React.useEffect(()=>{
    totalPrice = userData.map((item)=>{ return item.count * item.price})
    setbills(totalPrice);
 },[userData])

  

  React.useEffect(()=>{
     setuserData(data);
     totalPrice = data.map((item)=>{ return item.count * item.price})
     setbills(totalPrice);
  },[])

  return (
   <div className="main">
    <Orders data={userData} counter={counter} removeIteam={removeIteam} />
    <Bill totalPrice={bills}/>
   </div>
  )
}

export default Cart
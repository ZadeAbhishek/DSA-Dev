import React, { useState } from 'react'

export default function FormsX({login}) {
   
    const [userDetails,setUserDetails] = useState({email:"",password:""});

   // prevent defaut is add so that page donot keep loding 
   const Sub = (e)=>{
    e.preventDefault();
    login(userDetails);
   } 

  return (
    <form onSubmit={Sub}>
    <div className="Form-component">
        <label htmlFor="Email">Email:</label>
        <input type="email" name="email" value={userDetails.email} onChange={(e)=>{setUserDetails({...userDetails,email:e.target.value})}} id="email"/>
    </div>
      <div className="Form-component">
      <label htmlFor="password">Password:</label>
      <input type="password" name="password" value={userDetails.password} onChange={(e)=>{setUserDetails({...userDetails,password:e.target.value})}} id="password"/>
  </div>
  <div className="Form-component">
      <input type="submit" value="Submit" />
  </div>
  </form>
  )
}

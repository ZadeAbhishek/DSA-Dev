import './App.css';
import { useState } from 'react'
import FormsX from './components/FormsX';
import $ from 'jquery'; 

function App() {
  const [userdetails,setuserdetails] = useState({email:"",password:""});

  const login =(details)=>{
    console.log(details);
    console.log(details.email);
    setuserdetails({email:details.email,password:details.password});
  }

  const check = (e)=>{
    e.preventDefault();
    console.log(userdetails);
    $.ajax({
      url: "db.json",
      dataType: "json",
      success: function(data) {
          //data sucessfull
          alert(`Submited Name`);
      },
      error: function(data, ev) {
          //data error
          alert(`Try Again`);
      }
  });
  }
  return (
    <>
    <FormsX login={login}/>
    <input type="button" value="Send" onClick={check} />
    </>
  );
}

export default App;

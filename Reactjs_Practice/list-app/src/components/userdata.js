import {React,useState,useEffect} from 'react'
import axios from 'axios'


export default function Userdata() {

  // hooks 
  const [userdata, setuserdata] = useState([])
  const [totalPages, setpages] = useState(10) // dive total data into X pages
  const [currPage, setcurrPage] = useState(1)

    // varaible
    const numberOfPages = Math.ceil(userdata.length/totalPages)

    // incex of currPage
    const indexOflastTodo = currPage * totalPages;  // last index
    const indeofFirstTodo = indexOflastTodo - totalPages; // current index
    
    // cuurent context
    const visibleUserdata = userdata.slice(indeofFirstTodo,indexOflastTodo);

  // get total number of page to display
  const pages = [...Array(numberOfPages+1).keys()].slice(1)


  // function for button
  const changePage = (index) => {
      let curr = currPage + index;
      if(curr <= 0) setcurrPage(1);
      else if(curr >= numberOfPages) setcurrPage(numberOfPages)
      else setcurrPage(curr)
      return      
  }
  
  // this use effect will act as componentDidMount function
  useEffect(() => {
     // set data to hook
     axios.get("http://localhost:8080/getdata").then((res)=>{setuserdata(res.data);});
  }, [])
  
  return (
    <div>{

        // map all data
        visibleUserdata.map((res) => <p key = {res.id} >{"Name: " + res.name + "     " + "Age: "+res.age}</p>)}
        
        <span onClick={()=>changePage(-1)} >Prev</span>
        <p>{pages.map((res)=>(
        <span key = {res} 
        onClick={()=>setcurrPage(res)}>{" " + res + " | "}</span>))}</p>
        <span onClick={()=>changePage(1)} >Next </span>
        </div>
  )
}

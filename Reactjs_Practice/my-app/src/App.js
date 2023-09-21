//import logo from './logo.svg';
import './App.css';
import Header from './MyComponents/Header';
import Footer from './MyComponents/Footer'
import Todos from './MyComponents/Todos'
import { useState, useEffect } from "react";
import AppTodo from './MyComponents/AppTodo';
function App() {
   let initTodo;
   if(localStorage.getItem("todos") === null){
    initTodo = [];
   }
   else{
    initTodo = JSON.parse(localStorage.getItem("todos"));
   }
   const onDelete = (todo)=>{
      setTodos(todos.filter((e)=>{
        return e!==todo;
      }));
      localStorage.getItem("todos");
   };
  
  const addTodo = (title,desc)=>{
    let no;
    if(todos.length === 0) no=0;
    else no = todos[todos.length-1].sno+1;
    console.log(no);
    const myTodo = {
      title:title,
      desc:desc,
      sno:no,
    }
    setTodos([...todos,myTodo]);
    console.log(myTodo);
}
const [todos, setTodos] = useState([initTodo]);
useEffect(() => { localStorage.setItem("todos",JSON.stringify(todos))},[todos])

   
    return (
      <> 
      <Header title="To-Do List" searchBar = {true}/>
      <AppTodo addTodo = {addTodo}/>
      <Todos todos={todos} onDelete = {onDelete}/>
      <Footer/>
      </>
    );
}

export default App;
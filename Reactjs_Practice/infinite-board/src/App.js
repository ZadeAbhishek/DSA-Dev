import Board from './Board/Board';
import './App.css';
import ToolBox from './Compoenets/ToolBox';
import { useState } from "react";
import Draw from '../src/Compoenets/variable'
import Header from './Compoenets/Header';




function App() {
  return (
    <>
    <Header/>
    <ToolBox/>
    <Board/>
    
    </>
  );
}

export default App;

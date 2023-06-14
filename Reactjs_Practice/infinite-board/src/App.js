import './App.css';
import BoardsRoute from './Routes/BoardsRoute';
import { ReactDOM } from 'react-dom/client';
import {BrowserRouter,Routes,Route} from 'react-router-dom'
import Start from './Routes/Start';
import varaible from './Compoenets/variable';

let global = varaible();


function App() {
  
  return (
   <BrowserRouter>
   <Routes>
   <Route path="" element={<Start/>} ></Route>
    <Route path="board" element={<BoardsRoute/>} ></Route>
   
   </Routes>
   </BrowserRouter>
    
  );
}

export default App;

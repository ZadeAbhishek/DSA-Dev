import './App.css';

import { useState} from "react";

function App() {

  const [counter, setcounter] = useState(0)

  const increment = ()=>{
     setcounter(counter+1);
  }

  const decrement = ()=>{
    setcounter(counter-1);
  }

  return (
    <div className="d-grid justify-content-sm-center gap-3 col-2  pt-5">
      <div>
        {counter}
      </div>
     <button type="button" class="btn btn-success" onClick={increment}>Increment</button>
     <button type="button" class="btn btn-danger" onClick={decrement}>Decrement</button>
    </div>
  );
}

export default App;

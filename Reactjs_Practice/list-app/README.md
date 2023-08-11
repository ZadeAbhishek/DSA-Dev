# List App Demo
This Project this demo to create List app with Node js server api. The main Aim to understand How Pagination works in React js Using hooks and How to handle GET request in REACTjs as well as Nodejs

### Librarys Used 

- react-axios
- express

## Working

We will start with creating Server for GET request in Nodejs 

```javascript
import getdata from "./data.js";
import express from 'express'; // express library to create API
import cors from 'cors' // cross origins 

const server = express(); // server instance
const port = 8080;
server.listen(port, function(error) {

    // error listner
    if (error) console.log(`Error:${error}`)
    else console.log(`Listing on port:${port}`)

    // cors access to server
    server.use(cors());

    server.get('/getdata', (req, res) => {

        // permisson for CORS 
        res.header("Access-Control-Allow-Origin", "*")

        // converting data to json
        let json = JSON.stringify(getdata().data);

        // sendng json
        res.send(json);

        console.log("response send..")
    })
})
```

We will create Frontend in react to fetch data from server and Pagination Logic

```javascript
import React, { useState, useEffect } from 'react';
import axios from 'axios';

export default function Userdata() {
  // Hooks
  const [userdata, setUserData] = useState([]);
  const [totalPages, setTotalPages] = useState(10); // Divide total data into X pages
  const [currPage, setCurrPage] = useState(1);

  // Calculate the total number of pages
  const numberOfPages = Math.ceil(userdata.length / totalPages);

  // Calculate indexes for slicing the data
  const indexOfLastTodo = currPage * totalPages;
  const indexOfFirstTodo = indexOfLastTodo - totalPages;

  // Slice the current data for the visible page
  const visibleUserdata = userdata.slice(indexOfFirstTodo, indexOfLastTodo);

  // Generate an array of page numbers for pagination
  const pages = [...Array(numberOfPages + 1).keys()].slice(1);

  // Function to handle page change
  const changePage = (index) => {
    let newPage = currPage + index;
    if (newPage <= 0) {
      setCurrPage(1);
    } else if (newPage >= numberOfPages) {
      setCurrPage(numberOfPages);
    } else {
      setCurrPage(newPage);
    }
  };

  // UseEffect to fetch data on component mount
  useEffect(() => {
    axios.get("http://localhost:8080/getdata")
      .then((res) => {
        setUserData(res.data);
      });
  }, []);

  return (
    <div>
      {/* Display user data */}
      {visibleUserdata.map((res) => (
        <p key={res.id}>
          {"Name: " + res.name + "     " + "Age: " + res.age}
        </p>
      ))}

      {/* Pagination */}
      <span onClick={() => changePage(-1)}>Prev</span>
      <p>
        {pages.map((res) => (
          <span
            key={res}
            onClick={() => setCurrPage(res)}
          >
            {" " + res + " | "}
          </span>
        ))}
      </p>
      <span onClick={() => changePage(1)}>Next </span>
    </div>
  );
}

```
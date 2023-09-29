# List App with Pagination Demo

Welcome to the List App with Pagination demo project! This project aims to showcase the creation of a list app using a Node.js server API and demonstrates how to implement pagination in a React.js application using hooks. Additionally, it provides insights into handling GET requests in both React.js and Node.js.

## Libraries Used

- [react-axios](https://www.npmjs.com/package/react-axios)
- [express](https://expressjs.com/)

## How It Works

### Node.js Server for GET Request

To start, we create a Node.js server to handle GET requests. The server code snippet demonstrates the basic setup and usage of the Express framework along with the CORS middleware for handling cross-origin requests. It exposes an endpoint `/getdata` that responds with JSON data.

```javascript
// Import required modules and data
import getdata from "./data.js";
import express from 'express';
import cors from 'cors';

const server = express(); // Create an Express server instance
const port = 8080;

server.listen(port, function(error) {
    if (error) console.log(`Error: ${error}`);
    else console.log(`Listening on port: ${port}`);

    server.use(cors()); // Enable CORS for the server

    server.get('/getdata', (req, res) => {
        res.header("Access-Control-Allow-Origin", "*"); // Allow cross-origin requests
        const jsonData = JSON.stringify(getdata().data);
        res.send(jsonData); // Send the JSON response
        console.log("Response sent...");
    });
});
```

### React Frontend with Pagination Logic

The React component `Userdata` fetches data from the Node.js server and implements pagination logic to display the fetched data in a paginated manner. The component utilizes React hooks for state management and Axios for making GET requests.

```javascript
import React, { useState, useEffect } from 'react';
import axios from 'axios';

export default function Userdata() {
  // State hooks
  const [userdata, setUserData] = useState([]);
  const [totalPages, setTotalPages] = useState(10);
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

  // Fetch data on component mount
  useEffect(() => {
    axios.get("http://localhost:8080/getdata")
      .then((res) => {
        setUserData(res.data);
      });
  }, []);

  return (
    <div>
      {/* Display user data */}
      {visibleUserdata.map((user) => (
        <p key={user.id}>
          {"Name: " + user.name + "     " + "Age: " + user.age}
        </p>
      ))}

      {/* Pagination */}
      <span onClick={() => changePage(-1)}>Prev</span>
      <p>
        {pages.map((pageNumber) => (
          <span
            key={pageNumber}
            onClick={() => setCurrPage(pageNumber)}
          >
            {" " + pageNumber + " | "}
          </span>
        ))}
      </p>
      <span onClick={() => changePage(1)}>Next</span>
    </div>
  );
}
```

Feel free to use and modify this improved README for your project!
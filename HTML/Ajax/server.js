// Import required dependencies
const express = require('express'); // Express.js for creating the server
const cors = require('cors'); // CORS middleware for handling cross-origin requests
const bp = require('body-parser'); // Body-parser middleware for parsing request bodies
const path  = require('path');

// Initialize the Express server
const server = express();

// Use CORS middleware to allow cross-origin requests
server.use(cors());

// Use body-parser middleware to parse JSON request bodies
server.use(bp.json());

// Start the server and listen on port 8080
server.listen(8080, () => {
    console.log("Listening on Port 8080....");
});

// Handle POST API request at endpoint '/userdata'
server.post("/userdata", (req, res) => {
    // Log the data received in the request body
    console.log(req.body);

    // Check if the request is defined (not undefined)
    if (req != undefined)
        res.send("Submitted"); // Send response "Submitted" if the request is defined
    else
        res.send("Error"); // Send response "Error" if the request is undefined
});

server.get("/", (req, res) => {
    res.sendFile(path.join(__dirname,'./index.html'));
});

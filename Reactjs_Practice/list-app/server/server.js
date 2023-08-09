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
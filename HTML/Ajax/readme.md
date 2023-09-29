# Form Submission Example

This example demonstrates a simple HTML form with a JavaScript function that sends form data to a server using the Fetch API. The form collects user email and password and submits them to an API endpoint for processing.

## How It Works

### HTML Form

The HTML file `index.html` contains a form with two input fields: email and password. When the user clicks the "Submit" button, the JavaScript function `submitcall()` is triggered.

### JavaScript Function

The `submitcall()` function does the following:

1. Gathers the form data (email and password) from the input fields.
2. Converts the data into JSON format using `JSON.stringify()`.
3. Defines the API endpoint URL.
4. Uses the Fetch API to send a POST request to the server.

If the response from the server is successful (HTTP status 200), an "Submitted" alert is shown. Otherwise, an error alert is displayed.

### Styling

The form's appearance is styled using CSS to create a centered and visually appealing design. The form is styled with rounded corners, shadow, and a green submit button.

## Getting Started

1. Clone or download the repository.

2. Open the `index.html` file in a web browser.

3. Enter your email and password in the form fields.

4. Click the "Submit" button to see the form submission process in action.

## Notes

- This example assumes you have a server running at `http://localhost:8080/userdata` that can handle POST requests and respond accordingly.

- The code provided here is a simplified example for educational purposes. In real-world applications, proper error handling and security measures should be implemented.

Feel free to use and modify this example to learn more about form submissions using the Fetch API and building basic web interfaces.


## Dependency
```
npm i express
npm i cors
npm i body-parser

```

# React Search Filter App

This is a simple React application that allows users to search and filter a list of users based on their names. It displays a list of users with their names and ages in a grid format, and users can input a search query to filter the displayed users in real-time.

## Getting Started

To get started with this application, follow these steps:

1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/your-username/react-search-filter-app.git
   ```

2. Navigate to the project directory:
   ```bash
   cd react-search-filter-app
   ```

3. Install the project dependencies using npm or yarn:
   ```bash
   npm install
   # or
   yarn install
   ```

4. Run the development server:
   ```bash
   npm start
   # or
   yarn start
   ```

5. Open your web browser and access the application at `http://localhost:3000`.

## Usage

Once you have the application running, you can use it to search and filter the list of users:

- In the input field labeled "Search Name.....," enter a search query. As you type, the list of displayed users will dynamically update to show only those whose names match the search query.

## Code Structure

Here's an overview of the main components and their functionality in the code:

- **App.js**: This is the main component of the application. It manages the application's state, including the list of users, the filtered list (`final`), and the user's input for searching. It also contains the JSX for rendering the search input and the list of users.

- **data.js**: This file contains the initial list of users as an array of objects. You can modify this data to include your own user information.

- **CSS files**: The CSS files (`App.css` and any other relevant CSS files) contain styling rules for the application's appearance.

## How It Works

- The `useEffect` hook is used to filter the list of users (`users`) based on the user's input (`input`). It updates the `final` state with the filtered list whenever the `input` state changes.

- Another `useEffect` hook is used to initialize the `users` state with the data from the `data.js` file when the component mounts.

- The user interacts with the application by typing in the search input. As they type, the list of users is updated in real-time to show only those whose names contain the search query.

## Customize

You can customize this application by:

- Modifying the data in the `data.js` file to include your own list of users.
- Adjusting the styling in the CSS files to match your preferred design.
- Adding more features and functionalities as needed.

## Dependencies

This project relies on the following dependencies:

- React: A JavaScript library for building user interfaces.
- ReactDOM: A package for rendering React components in the DOM.
- Other dependencies listed in the `package.json` file.

You can find more details about these dependencies in the `package.json` file.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- This project is a simple example of using React for creating a real-time search and filter functionality.
- Special thanks to the React community for their contributions and support.

Feel free to explore and enhance this application as needed for your own projects!

1. **Importing Dependencies:**
   ```javascript
   import React, { useEffect } from 'react';
   import './App.css';
   import data from './data/data.js'
   ```
   - Here, you're importing the necessary dependencies for your React application:
     - `React` and `useEffect` are imported from the 'react' library.
     - You're importing the CSS file 'App.css' for styling.
     - You're importing data from an external file './data/data.js'.

2. **Functional Component:**
   ```javascript
   function App() {
   ```
   - You define a functional component called `App`.

3. **State Variables:**
   ```javascript
   const [users, setUsers] = React.useState([]);
   const [final, setFinal] = React.useState([]);
   const [input, setInput] = React.useState("");
   ```
   - You declare three state variables using React hooks:
     - `users` stores the list of users.
     - `final` stores the filtered list of users.
     - `input` stores the user's search input.

4. **Input Handling Function:**
   ```javascript
   const inputSet = (s) => {
     setInput(s);
   }
   ```
   - You define a function `inputSet` to update the `input` state with the user's input value.

5. **Effect for Filtering Users:**
   ```javascript
   useEffect(() => {
     const finalList = users.filter((u) => {
       return Object.values(u).join("").toLowerCase().includes(input.toLowerCase());
     });
     setFinal(finalList);
   }, [input]);
   ```
   - You use the `useEffect` hook to filter the list of users (`users`) whenever the `input` state changes.
   - It filters the `users` array based on whether any of the user's data (name or age) contains the `input` value. The result is stored in the `final` state.

6. **Effect for Initializing Users:**
   ```javascript
   React.useEffect(() => {
     setUsers(data);
   }, []);
   ```
   - Another `useEffect` hook is used to initialize the `users` state with data from the external 'data.js' file when the component mounts. This code runs only once when the component first loads.

7. **Render Function:**
   ```javascript
   return (
     <>
       <div className="App">
         <input
           className='search'
           onChange={(e) => { inputSet(e.target.value) }}
           type='search'
           placeholder='Search Name.....'
         ></input>
       </div>
       <div className="grid">
         {final.map((user, index) => {
           return (
             <div key={index} className="grid-child">
               <h4>{user.name}</h4>
               <p>{user.age}</p>
             </div>
           )
         })}
       </div>
     </>
   );
   ```
   - In the JSX code, you render the following components:
     - An input element for searching (`<input>`).
     - A grid of user information based on the filtered `final` list.
     - You map over the `final` list and display each user's name and age.

This React application allows users to input a search query, which then filters and displays the matching users in real-time. The `useEffect` hooks handle the filtering and initialization of the user data, and the component renders the search input and filtered user list.
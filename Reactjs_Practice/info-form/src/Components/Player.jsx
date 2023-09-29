import React from 'react'
import "../CSS/Player.css"
import Form from './Form'
export const Player = () => {
    const [questionData, setquestionData] = React.useState([
        {
          id:1,
          question: "What is the capital of France?",
          options: [
            { label: "A", text: "Berlin" },
            { label: "B", text: "London" },
            { label: "C", text: "Paris" },
            { label: "D", text: "Madrid" }
          ],
          correctAnswer: "C"
        },
        {
          id:2,  
          question: "Which planet is known as the Red Planet?",
          options: [
            { label: "A", text: "Mars" },
            { label: "B", text: "Earth" },
            { label: "C", text: "Jupiter" },
            { label: "D", text: "Venus" }
          ],
          correctAnswer: "A"
        },
        // Add more questions here
      ])
      const [currQuestionIndex, setcurrQuestionIndex] = React.useState(0);

      let answerArray = questionData.map((index)=>({answer:null}))
      
      const currQuestion = questionData[currQuestionIndex];

      const iterator = (irr)=>{
         let index = currQuestionIndex + irr;
         index = index < 0 ? 0 : index;
         index = index > questionData.length-1 ? questionData.length-1 : index;
         setcurrQuestionIndex(index);
      }
  return (
    <div className="player-container">
        <Form questionData={currQuestion} currQuestion={currQuestion}/>
        <div className="player-btn">
            <button className="next" onClick={()=>{iterator(1)}} >Next</button>
            <button className="prev" onClick={()=>{iterator(-1)}}>Prev</button>
            <button className="submit">Submit</button>
        </div>
    </div>
  )
}

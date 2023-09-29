import React from 'react'
import "../CSS/Form.css"
const Form = ({questionData}) => {
  return (
    <div className="question-form-container">
         <div className="questions-container">{questionData.id}.{questionData.question}</div>
         {questionData.options.map((ans)=>(
                     <div className="answer-container">
                     <label htmlFor={`${ans.label}`}>{ans.label}.{ans.text}</label>
                     <input type="checkbox" className='input' for={`${ans.label}`}/>
                     </div>
         ))}                                        
    </div>
  )
}

export default Form
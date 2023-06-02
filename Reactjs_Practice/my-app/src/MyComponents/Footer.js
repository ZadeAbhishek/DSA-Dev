import React from 'react'

export default function Footer() {
    let footerStyle = {
        position:"relative",
        top: "70vh",
        width: "100%",
        border:"2px solid red"
    }
  return (
    <footer className="bg-dark text-light py-3" style={footerStyle}>
        <p className="text-center">
        copyright &copy; MytodoList.com</p></footer>
  )
}

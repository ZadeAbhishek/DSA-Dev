import React from 'react'
import PropTypes from 'prop-types'
/*
props == javascript object that contains all paramter from parent compnents
*/
export default function Header(props) {
    return ( <
        div >
        <
        nav className = "navbar navbar-expand-lg bg-body-tertiary" >
        <
        div className = "container-fluid" >
        <
        a className = "navbar-brand"
        href = "/#" > { props.title } < /a> <
        button className = "navbar-toggler"
        type = "button"
        data - bs - toggle = "collapse"
        data - bs - target = "#navbarSupportedContent"
        aria - controls = "navbarSupportedContent"
        aria - expanded = "false"
        aria - label = "Toggle navigation" >
        <
        span className = "navbar-toggler-icon" > < /span> <
        /button> <
        div className = "collapse navbar-collapse"
        id = "navbarSupportedContent" >
        <
        ul className = "navbar-nav me-auto mb-2 mb-lg-0" >
        <
        li className = "nav-item" >
        <
        a className = "nav-link active"
        aria - current = "page"
        href = "/#" > Home < /a> <
        /li> <
        li className = "nav-item" >
        <
        a className = "nav-link active"
        aria - current = "page"
        href = "/#" > About < /a> <
        /li>

        <
        /ul> {
            props.searchBar ? < form className = "d-flex"
            role = "search" >
                <
                input className = "form-control me-2"
            type = "search"
            placeholder = "Search"
            aria - label = "Search" / >
                <
                button className = "btn btn-outline-success"
            type = "submit" > Search < /button> <
                /form> : "fasle"} <
                /div> <
                /div> <
                /nav> <
                /div>
        )
    }

    /**
     * Shows the error in console log 
     * otherwise no error will cause
     * helps in production
     */

    Header.propTypes = {
        title: PropTypes.string
    }

    /**
     * if nothing is Passed then return this as defualt
     */

    Header.defaultProps = {
        title: "Sample Title"
    }
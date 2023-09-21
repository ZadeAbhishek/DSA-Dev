import React, { useEffect } from 'react';
import "../Css/Bill.css";

const Bill = (props) => {
  // Calculate the total price
  let total_Price = 0;
  props.totalPrice.forEach((x) => {
    total_Price += x;
  });

  // Calculate the discount
  let discount = (total_Price * 20) / 100;

  // Calculate the final price after applying the discount
  let Final_Price = total_Price - discount;

  return (
    <div className="bill">
      Total
      <div className="total-item">
        {`item(${props.totalPrice.length}) : + $${total_Price}`}
      </div>
      <div className="discount-item">
        {`Discount : - $${discount}`}
      </div>
      <div className="total-price">
        {`Total Order : - $${Final_Price}`}
      </div>
    </div>
  );
}

export default Bill;

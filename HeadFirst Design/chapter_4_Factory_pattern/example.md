# Factory Pattern System Design Interview Question

## Question: Design a Payment Processing System

You are asked to design a payment processing system for an e-commerce platform that supports multiple payment methods. The system should be able to process payments through various methods such as Credit Card, PayPal, and Bitcoin. Each payment method requires different information and processing logic.

### Requirements:
1. The system should be easily extendable to support new payment methods in the future.
2. Each payment method should implement a common interface to ensure consistency in processing payments.
3. The system should decide which payment method to use at runtime based on user input.

### Tasks:
1. Define a common interface for all payment methods.
2. Implement at least three different payment methods (Credit Card, PayPal, Bitcoin).
3. Create a factory class that will generate the appropriate payment method object based on user input.
4. Demonstrate how the system can process a payment using the factory pattern.

### Example Usage:
- User selects "Credit Card" as their payment method and provides the necessary details.
- The system uses the factory to create a `CreditCardPayment` object and processes the payment.
- The same process should work seamlessly for PayPal and Bitcoin.


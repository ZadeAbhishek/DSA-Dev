# Strict Mode in JavaScript

Strict mode in JavaScript is a set of rules that enhances the default behavior of the language by catching common coding mistakes and "unsafe" actions. It was introduced in ECMAScript 5 (ES5) to help developers write more reliable and error-free code. When strict mode is enabled, the JavaScript interpreter becomes less forgiving of certain types of mistakes, which can help you identify and fix problems early in the development process. Here's an explanation of what strict mode does:

1. **Error Prevention**: Strict mode catches common coding mistakes and turns them into errors. For example, assigning a value to an undeclared variable or using reserved words as variable names will trigger errors. In non-strict mode, these issues would typically result in creating global variables or have unintended consequences.

2. **No Silent Failures**: In non-strict mode, JavaScript might fail silently when errors occur, making debugging challenging. Strict mode ensures that errors are reported explicitly, which helps developers identify and fix issues quickly.

3. **Safer Assignments**: In strict mode, assignments that would accidentally create global variables are not allowed. This prevents accidental pollution of the global namespace, which can lead to conflicts and unexpected behavior.

4. **Restricted Octal Syntax**: Octal literals (e.g., `0123`) are not allowed in strict mode, reducing confusion and potential errors related to the use of octal values.

5. **Eliminates `this` coercion**: In strict mode, the value of `this` in functions is not automatically coerced to the global object (e.g., `window` in a web browser). This can prevent unexpected behavior when working with objects and constructors.

6. **Deprecated Features**: Strict mode deprecates certain features that are considered problematic or error-prone, such as the `with` statement and certain `arguments` object behaviors.

To enable strict mode in your JavaScript code, you can add the following line at the beginning of your script or function:

```javascript
"use strict";

function doSomething() {
    // This function is in strict mode.
    // You'll get errors for common coding mistakes.
}
```

Certainly, here's the markup for the explanation of the difference between Host objects and Native objects:


# Difference between Host Objects and Native Objects

In JavaScript, there are two primary categories of objects: Host objects and Native objects. These objects serve different purposes and come from distinct sources within the JavaScript environment.

## Native Objects

Native objects, also known as built-in objects, are fundamental objects that are an integral part of the JavaScript language. They are defined in the ECMAScript specification and are universally available in all JavaScript environments. Examples of native objects include:

- `String`
- `Math`
- `RegExp`
- `Object`
- `Function`

These native objects provide core functionality and are consistent across all JavaScript implementations.

## Host Objects

Host objects, on the other hand, are objects provided by the environment in which JavaScript code is executed. They are not a part of the ECMAScript specification and can vary depending on the environment. In a typical web browser environment, host objects may include:

- `window` (the global object in a browser)
- `XmlHttpRequest` (for making HTTP requests)
- DOM nodes (representing elements in the Document Object Model)

Host objects are distinct from native objects because they are not guaranteed to exist in all JavaScript environments. For instance, if JavaScript runs outside of the browser, such as in Node.js for server-side scripting, a different set of host objects will be available, specific to the Node.js environment.

In summary, the key difference between host objects and native objects lies in their source and availability. Native objects are part of the core JavaScript language and are consistent across all environments, while host objects are environment-specific and provided by the hosting environment.

# Same-Origin Policy in JavaScript

The **same-origin policy** is a vital security feature implemented by web browsers to safeguard web applications from certain types of security threats. It enforces restrictions on web pages, preventing them from making requests to domains (origins) different from the one that served the web page. This policy is instrumental in maintaining the security and integrity of web applications.

## Understanding Same-Origin

In the context of the same-origin policy, an origin is defined by three key components:

- **Protocol:** This specifies how data is transferred and can be, for example, `http`, `https`, `ftp`, etc.

- **Domain:** This is the web address of the server hosting a web page or resource.

- **Port:** While not always explicitly mentioned in URLs, it defines the communication endpoint on the server. Commonly, HTTP uses port 80.

## Key Rules of the Same-Origin Policy

1. **JavaScript Access:** JavaScript running on a web page from one origin is generally not allowed to directly access data or interact with resources hosted on a different origin.

2. **Exceptions:** Some exceptions exist, such as loading images, scripts, and stylesheets from different origins, but even these resources are subject to additional security checks.

3. **Cross-Origin Requests:** If a web page from one origin needs to make requests to a different origin's server, the server must enable **Cross-Origin Resource Sharing (CORS)** by including specific HTTP response headers.

## Security Benefits

- **Prevents Unauthorized Access:** By enforcing the same-origin policy, web browsers prevent malicious websites from making unauthorized requests to other websites on behalf of a user, thus safeguarding user data.

- **Mitigates XSS Attacks:** This policy plays a pivotal role in mitigating cross-site scripting (XSS) attacks, as it thwarts the injection of malicious scripts from one origin into a different origin's web page.

## CORS (Cross-Origin Resource Sharing)

- When a web page needs to access resources from a different origin, the server hosting those resources can include **CORS headers** in its HTTP responses. These headers specify which origins are permitted to access its resources, granting permissions to trusted origins while denying access to others.

## JSONP (JSON with Padding)

- In some cases, web developers use **JSONP (JSON with Padding)** as a workaround to the same-origin policy. JSONP involves dynamically adding script tags to the DOM to load JSON data from a different domain. However, it has security risks and should be used cautiously.

In summary, the same-origin policy in JavaScript is a fundamental security feature that ensures web pages can only interact with resources from the same origin, unless explicitly permitted by the server through CORS headers. This policy is indispensable in preventing unauthorized data access and protecting web applications from various security threats.



# Deep Copy vs. Shallow Copy in JavaScript Objects

In JavaScript, when you want to duplicate or clone an object, you can create either a **deep copy** or a **shallow copy**. These two types of copies differ in how they handle nested objects or objects referenced within the original object. Let's explore each concept:

## Shallow Copy

A **shallow copy** of an object creates a new object that is a copy of the original object. However, it does not create copies of the nested objects inside the original object. Instead, it copies references to those nested objects. Therefore, changes made to the nested objects in the copied object will also affect the original object, and vice versa.

### Examples of Shallow Copy Methods

- **Spread Operator (`...`):** `const shallowCopy = { ...originalObject };`

- **Object.assign():** `const shallowCopy = Object.assign({}, originalObject);`

- **Array.from():** For shallow copying arrays, you can use `Array.from(originalArray);`.

## Deep Copy

A **deep copy**, on the other hand, creates an entirely new object with copies of all nested objects inside the original object. In other words, it recursively copies all nested objects and their properties, ensuring that changes made to the copied object or its nested objects do not affect the original object or its nested objects.

### Creating a Deep Copy

Creating a deep copy is more complex and typically requires custom code or the use of libraries like Lodash. Here's an example of how you might create a deep copy using a recursive function:

```javascript
function deepCopy(obj) {
  if (typeof obj !== 'object' || obj === null) {
    return obj; // Return non-objects as-is
  }

  if (Array.isArray(obj)) {
    return obj.map(deepCopy); // Handle arrays
  }

  const copy = {};
  for (const key in obj) {
    if (obj.hasOwnProperty(key)) {
      copy[key] = deepCopy(obj[key]); // Recursively copy nested objects
    }
  }

  return copy;
}

const originalObject = {
  a: 1,
  b: { c: 2 },
};

const deepCopiedObject = deepCopy(originalObject);

```

# How to compare two objects in JavaScript?

In JavaScript, you can compare two objects in several ways, depending on your specific requirements. Here are some common approaches for comparing objects:

1. **Strict Equality (===):** The strict equality operator (`===`) compares two objects by reference. It returns `true` only if the two objects reference the same memory location (i.e., they are the same object). This method is the simplest and most common way to compare objects by reference.

   ```javascript
   const obj1 = { name: 'Alice' };
   const obj2 = obj1; // Both obj1 and obj2 reference the same object

   console.log(obj1 === obj2); // true
   ```

2. **Comparing Object Properties:** To compare two objects by their properties (content), you can manually iterate through the properties of both objects and check if their values are equal. This method allows you to perform a deep comparison, considering the properties and nested objects.

   ```javascript
   function objectsAreEqual(objA, objB) {
     const keysA = Object.keys(objA);
     const keysB = Object.keys(objB);

     if (keysA.length !== keysB.length) {
       return false;
     }

     for (const key of keysA) {
       if (objA[key] !== objB[key]) {
         return false;
       }
     }

     return true;
   }

   const person1 = { name: 'Alice', age: 30 };
   const person2 = { name: 'Alice', age: 30 };

   console.log(objectsAreEqual(person1, person2)); // true
   ```

3. **Using a Library:** For deep comparisons or more complex object structures, you can use JavaScript libraries like Lodash, which provide utility functions for deep object comparisons.

   ```javascript
   const _ = require('lodash');

   const obj1 = { name: 'Alice', address: { city: 'New York' } };
   const obj2 = { name: 'Alice', address: { city: 'New York' } };

   console.log(_.isEqual(obj1, obj2)); // true
   ```

4. **Custom Comparison Functions:** You can write custom comparison functions that define your specific criteria for object equality. This method is useful when you need to compare objects based on certain rules or conditions specific to your application.

   ```javascript
   function customObjectComparison(objA, objB) {
     // Implement your custom comparison logic here
     // Return true if the objects are considered equal, otherwise return false
   }

   const result = customObjectComparison(obj1, obj2);
   ```

The choice of which method to use for comparing objects depends on the context and the specific requirements of your application. If you need a simple reference comparison, use `===`. For content-based comparisons, you can manually compare properties or leverage libraries like Lodash for deep comparisons. Custom comparison functions are suitable when you have unique comparison criteria.


```javascript
var a = [1,2,3];
var b = [1,2,3];
var c = "1,2,3";

a == c;		// true
b == c;		// true
a == b;		// false

explain this
```
The behavior you're observing in the comparisons involving variables `a`, `b`, and `c` is due to JavaScript's type coercion and how it handles equality comparisons (`==`) between different data types. Let's break down each comparison:

1. `a == c`: This comparison is between an array (`a`) and a string (`c`). JavaScript tries to coerce both operands to a common data type before comparing them. In this case, it converts the array `a` to a string, resulting in the string `"1,2,3"`. Now, you're comparing two strings, and they are equal because they have the same content.

2. `b == c`: This comparison is similar to the previous one. It's between another array (`b`) and the same string (`c`). Again, JavaScript converts the array `b` to the string `"1,2,3"` and then compares the two strings, which are equal.

3. `a == b`: This comparison is directly between two arrays (`a` and `b`). Arrays in JavaScript are objects, and object comparisons are reference comparisons. The `==` operator checks if the two objects (arrays) have the same reference in memory. In this case, `a` and `b` are two different array objects with the same content, so the comparison returns `false` because they are not the same object in memory.

In summary, the comparisons `a == c` and `b == c` return `true` because JavaScript performs type coercion and converts the arrays to strings before comparing. However, the comparison `a == b` returns `false` because it checks for object reference equality, and `a` and `b` are two distinct array objects in memory.


# Call and Apply

The main difference between `.call` and `.apply` in JavaScript is how they pass arguments to a function:

1. **`.call`**: It passes arguments to a function as a comma-separated list. You list each argument individually after the function.

   ```javascript
   functionName.call(thisArg, arg1, arg2, ...);
   ```

2. **`.apply`**: It passes arguments to a function as an array. You provide the function with an array containing all the arguments.

   ```javascript
   functionName.apply(thisArg, [arg1, arg2, ...]);
   ```

In essence, `.call` is used when you have a known number of arguments and want to pass them individually, while `.apply` is used when you have a variable number of arguments or an array of arguments and want to pass them together. Both methods allow you to control the `this` context within a function.


# Deep Freeze

Deep-freezing objects in JavaScript means making an object and all of its nested properties immutable, so they cannot be modified or changed. To deep-freeze an object, you need to recursively traverse through all properties, including nested objects and arrays, and set them to be non-configurable and non-writable using `Object.freeze()` or a similar mechanism. Here's how you can deep-freeze an object:

```javascript
function deepFreeze(obj) {
  // Retrieve the property names defined on the object
  const propNames = Object.getOwnPropertyNames(obj);

  // Freeze each property one by one, including nested objects
  for (const propName of propNames) {
    const propValue = obj[propName];

    // If the property is an object, recursively deep-freeze it
    if (typeof propValue === 'object' && propValue !== null && !Object.isFrozen(propValue)) {
      deepFreeze(propValue);
    }

    // Freeze the property itself (making it non-writable and non-configurable)
    Object.freeze(obj[propName]);
  }

  // Finally, freeze the object itself (making it non-extensible)
  return Object.freeze(obj);
}

const sampleObject = {
  a: 1,
  b: {
    c: 2,
    d: [3, 4],
  },
};

const deepFrozenObject = deepFreeze(sampleObject);

// Attempting to modify the deep-frozen object will result in errors or silent failures
deepFrozenObject.a = 100; // Throws an error in strict mode
deepFrozenObject.b.c = 200; // Throws an error in strict mode
deepFrozenObject.b.d.push(5); // Throws an error in strict mode
```

In this code:

1. The `deepFreeze` function recursively iterates through all properties of the object using `Object.getOwnPropertyNames`.

2. For each property, it checks if it's an object and not already frozen. If it's an object, the `deepFreeze` function is called recursively on that object.

3. Finally, it calls `Object.freeze` on each property to make them non-writable and non-configurable and then freezes the object itself.

Once an object is deep-frozen, any attempts to modify its properties or nested properties will result in errors (or silent failures in non-strict mode) because the object and all of its properties are now immutable. Deep-freezing is useful when you want to ensure that an object remains unchanged throughout its lifetime, providing a form of data immutability.
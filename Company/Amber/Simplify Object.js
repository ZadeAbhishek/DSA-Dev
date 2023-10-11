// Online Javascript Editor for free
// Write, Edit and Run your Javascript code using JS Online Compiler

// fun({} / /curr obj,{} // resu)
var user = {
    name: "Vishal",
    address: {
      primary: {
        house: "109",
        street: {             
          main: "21",
          cross: "32"
        }
      }
    }
  };
  
  var result = {};
  
  const merge = (obj1,result,currName)=>{
      // get all key iform obj
      for(const keys in obj1){
          // chekc if the given value or object
          if( typeof(obj1[keys]) == "object") merge(obj1[keys],result,`${currName}_${keys}`);
          else result[`${currName}_${keys}`] = obj1[keys]
      }
  }
  
  merge(user,result,"user");
  console.log(result)
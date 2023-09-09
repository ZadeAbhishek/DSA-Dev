const checkIfNumber = (num)=>{
    return new Promise((response,reject)=>{
        if(typeof num == "number") response('Its a Number');
        else reject("Not a Number");
    })
}

checkIfNumber("a").then((response)=>{console.log(response)}).catch((response)=>{console.log(response)});
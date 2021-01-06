// Primitive Data types :- String,Number,Boolean,Undefined 

console.log("Hello!");
let  x=9;
console.log(x++);
console.log(x);  
x="fbdsjfb";
console.log(x); 
var y=3;
y="fdsf";
let number=454;
console.log(number);
console.log(typeof(x));
let s=null;
console.log(typeof(s));


// Unprimitve Data types :- Object,Functions,Arrays
let ob={
    firstname: "deepak",
    lastname: "joshi",
     dance: () => {
        console.log(ob.firstname + "Dances");
    }
};
console.log(ob.firstname);
ob.age=21;
console.log(ob.age);
ob.dance();
console.log(ob);

let arr=[54,'fhfgh',"hgfh"];
console.log(arr);
console.log(arr[0]);
arr[4]='hello';
arr[10]=657; 
console.log(arr);
console.log(arr.length);

function greet(name){
    console.log(`Namaste!  ${name}`);
};
greet("Deepak");


 
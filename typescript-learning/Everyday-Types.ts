//The primitives: string, number and boolen

//arrays

//any, js doesnt have this, you can use it whenever you don't want a particular value to cause typechecking errors

//let :block scoped(only exists in the pair of curly braces {}), reassignable(you can assign a new value to that variable name), No redeclaration(can't declare the same variable name twice in the same scope)
//const : the recommended default for constants, block scoped, Not reassinable(but can modify its content if its an object or array), 
//var : avoid using,Function scoped, 

//Use const by default: If the value doesn't need to change, const makes your code safer and clearer.
//Use let when necessary: If you know the value needs to be reassigned (like in a loop or a toggle), use let.
//Avoid var, It is considered bad practice in modern development because its scoping behavior is counter-intuitive.

//Type annotations on Variables
let meuNome: string = "Rodrigo";

//Return type Annotations
function getFavoriteNumber(): number {
    return 26;
}

//Functions with return Promises, 
// a Promise is an object representing the eventual completion ,or failure, of an asynchronous operation and its resulting value.
// uses a async/await syntax
async function getFavoriteNumber(): Promise<number> {
    return 26;
    
}

//Anonymous Functions
//when a function appears in a place where typescript can determine how its going to be called, the parameters of that function are automatically given types
const names = ["Alice", "Bob", "Eve"];
 
// Contextual typing for function - parameter s inferred to have type string
names.forEach(function (s) {
  console.log(s.toUpperCase());
});
 
// Contextual typing also applies to arrow functions
names.forEach((s) => {
  console.log(s.toUpperCase());
});
//this process is called contextual typing

//Object Types
// The parameters type annotation is an object type
function printCoord(pt: { x: number; y: number }) {
  console.log("The coordinate's x value is " + pt.x);
  console.log("The coordinate's y value is " + pt.y);
}
printCoord({ x: 3, y: 7 });

// adding "?" specify the ones that are optional
//Union Types,
function printId( id: number | string){
    console.log("Your ID is:" + id);
}


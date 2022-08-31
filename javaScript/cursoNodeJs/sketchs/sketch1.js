const strPrim = "foo"; // A literal is a string primitive
const strPrim2 = String(1); // Coerced into the string primitive "1"
const strPrim3 = String(true); // Coerced into the string primitive "true"
const strObj = new String(strPrim); // String with new returns a string wrapper object.

console.log(typeof strPrim); // Logs "string"
console.log(typeof strPrim2); // Logs "string"
console.log(typeof strPrim3); // Logs "string"
console.log(typeof strObj);  // Logs "object"

console.log(strPrim); // Logs "string"
console.log(strPrim2); // Logs "string"
console.log(strPrim3); // Logs "string"
console.log(strObj);  // Logs "object"

const x = "trying to do a string \
that will work breaking lines \
that's awesome!";

console.log(x)
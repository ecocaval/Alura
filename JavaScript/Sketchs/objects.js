class User {
    constructor(firstName, lastName, age, dateAccountCreation, accountStatus) {
        this.firstName = firstName
        this.lastName = lastName
        this.age = age
        this.dateAccountCreation = dateAccountCreation
        this.accountStatus = accountStatus
    }
}

let userErico = new User('Erico', 'Cavalcanti', '22', '22/11/2015', 'Premium')
let userVitoria = new User('Vitoria', 'Harter', '24', '24/03/2007', 'Standard')

console.log(userErico)
console.log(userVitoria)
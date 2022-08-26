function Client (name,email,cpf) {
    this.name = name
    this.email = email
    this.cpf = cpf
    this.transferTo = function (clientReceiving, amount) {
        if(this.balance >= amount) {
            this.balance -= amount
            clientReceiving.balance += amount
        } else {
            console.log(`Your balance is lower then the amount to send.`)
        }
    }
}

function ClientBalance (name, email, cpf, balance, balancePoup) {
    Client.call(this, name, email, cpf)
    this.balance = balance
    this.balancePoup = balancePoup
}

ClientBalance.prototype.transferToPoup = function(clientReceiving, amount) {
    if(this.balancePoup >= amount) {
        this.balancePoup -= amount
        clientReceiving.balancePoup += amount
    } else {
        console.log(`Your balance is lower then the amount to send.`)
    }
}

const clientEricoBalance = new ClientBalance('Érico', 'Cavalcanti', '13140363788', 1500, 4000)
const clientVitoriaBalance = new ClientBalance('Vitoria', 'Harter', '44955219772', 20000, 40000)

clientEricoBalance.transferTo(clientVitoriaBalance, 1000)
clientVitoriaBalance.transferToPoup(clientEricoBalance, 1000)

console.log(clientEricoBalance)
console.log(clientVitoriaBalance)
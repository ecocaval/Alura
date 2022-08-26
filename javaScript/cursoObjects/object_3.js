const client = {
    name: 'Andre',
    lastName: 'Andrade',
    age: 18,
    cpf: '129014894039',
    email: 'sadjsi@email.com',

    dependent: {
        name: 'Tamires',
        relation: 'Daughter',
        age: 11,
    },

    secure: 'disabled',
    receivedSecureOffer: false,

    sendTransf: function(value, client) {
        if(this.balance >= value) {
            this.balance -= value
            client.balance += value
        } else {
            console.log(`Desculpe Sr.(a) ${this.nome}, seu saldo de R$ ${this.saldo} é insuficiente para realizar a transação de R$ ${value}`)
        }
    },

    sendSecureOfferTo: function(client) {
        console.log(`Olá sr(a). ${client.name}, gostaria de conhecer nossos planos de seguro?`)
        client.receivedSecureOffer = true
    },

}

function offerSecureOption(client) {
    const clientInfos = Object.keys(client) //creates an array of client object keys
    if(clientInfos.includes('dependent')) {
       client.sendSecureOfferTo(client) 
    } else {
        console.log(`O cliente ${client.name} não possui dependentes!`)
    }
}

offerSecureOption(client)

// for(let clientInfo in client) {
//     if(clientInfo === 'dependent') {
//         sendSecureOfferTo(client)
//     }
// }

// if(!client.receivedSecureOffer) {
//     console.log(`O cliente ${client.name} não possui dependentes!`)
// }
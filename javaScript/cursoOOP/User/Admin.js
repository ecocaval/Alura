import User from './User.js';

class Admin extends User {
    constructor(nome, email, nascimento, role = 'admin', ativo = true) {
        super(nome, email, nascimento, role, ativo);
    }
}

const novoAdmin = new Admin('Erico', 'e@e.com', '2000-18-02');

console.log(novoAdmin);
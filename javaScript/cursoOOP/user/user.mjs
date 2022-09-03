import chalk from 'chalk';

const user = {
    nome: 'erico',
    email: 'ecocaval@hotmail.com',
    nascimento: '18/02/2000',
    role: 'estudante',
    ativo: true,
    exibirInfos: function() {
        console.log((chalk.yellow('Nome: ')) + this.nome);
        console.log((chalk.yellow('Email: ')) + this.email);
        console.log((chalk.yellow('Nascimento: ')) + this.nascimento);
    }
}

const admin = {
    nome: 'marinana',
    email: 'm@m.com',
    role: 'admin',
    criarCurso: function() {
        console.log('Curso criado!');
    }
}

Object.setPrototypeOf(admin, user);

admin.criarCurso();
admin.exibirInfos();    

const exibeSomenteRole = admin.role;

const exibeRoleBindado = exibeSomenteRole.bind(admin);


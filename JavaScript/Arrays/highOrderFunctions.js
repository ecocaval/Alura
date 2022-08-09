/*******************************************/

// const usuarioLogin = (nomeUsuario, cargo) => {
//     if(autenticaCargo(cargo)) {
//         return acesso(nomeUsuario);
//     } else {
//         return 0;
//     }
// }

// const acesso = (nomeUsuario) => {
//     return `${nomeUsuario} logou com sucesso!`;
// }

// const autenticaCargo = (cargo) => {
//     let array = [];
//     for(let i = 0; i < cargo; i++) {
//         array.push(i);
//     }
//     return true;
// }

// console.log(usuarioLogin('lucas'));

/*******************************************/

// function userLogin(username) {
//     let array = []
//     for(let i = 0; i < 90000; i++) {
//         array.push[i];
//     }
//     return `${username} has logged sucessfully!`;
// }

// console.log(userLogin('lucas'));

/*******************************************/

const acesso = (nome) => {
    return `${nome} logou com sucesso no sistema!`
  }
  
  const autentica = (cargo) => {
    let array = []
    for( i = 0; i < cargo; i++){
      array.push(i)
    }
    return true;
  }
  
  const login = (pessoa, autentica) => {
    if(pessoa.cargo === `funcionario`) {
       autentica(90000)
    } else if(pessoa.cargo === `diretoria`) {
       autentica(900000)
    }
   return acesso(pessoa.nome)
  }
  
const chalk = require('chalk');
const validaURLs = require('./httpValidation')
const pegaArquivo = require('./index.mjs');

const caminho = process.argv;

async function processaTexto(caminhoDeArquivo) {
  const resultado = await pegaArquivo(caminhoDeArquivo[2]);
  if(caminhoDeArquivo[3] === 'validate') { 
    await validaURLs(resultado);
    return;
  }
  console.log(chalk.yellow('lista de links\n'), resultado);
}

processaTexto(caminho);

const chalk = require('chalk');
const validaURLs = require('./httpValidation')
const pegaArquivo = require('./index.mjs');

const caminho = process.argv;

async function processaTexto(caminhoDeArquivo) {
  const resultado = await pegaArquivo(caminhoDeArquivo[2]);
  console.log(chalk.yellow('lista de links\n'), resultado);
  await validaURLs(resultado);

  return resultado;
}

processaTexto(caminho);

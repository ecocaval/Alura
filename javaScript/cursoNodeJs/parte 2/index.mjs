const chalk = require('chalk');
const fs = require('fs');

const texto1 = 'A interface File provê informações sobre arquivos e permite ao JavaScript  a acessar seu conteúdo. São geralmente recuperados a partir de um objeto [FileList](https://developer.mozilla.org/pt-BR/docs/Web/API/FileList) que é retornado como resultado da seleção, pelo usuário, de arquivos através do elemento [<input>](https://developer.mozilla.org/pt-BR/docs/Web/HTML/Element/Input), a partir do objeto [DataTransfer](https://developer.mozilla.org/pt-BR/docs/Web/API/DataTransfer) utilizado em operações de arrastar e soltar, ou a partir da API `mozGetAsFile()` em um [HTMLCanvasElement](https://developer.mozilla.org/pt-BR/docs/Web/API/HTMLCanvasElement). Em Gecko, códigos com privilégiios podem criar objetos File representando qualquer arquivo local sem a intereção do usuário (veja [Implementation notes](https://developer.mozilla.org/pt-BR/docs/Web/API/File#implementation_notes) para mais informações.)'

function treatError (err) {
    return console.log(chalk.red(`An error was detected!\n${err}`));
}

async function readFile (filePath) {
    const encoding = 'utf-8';

    console.log('\nStarted reading file...')
    try {
        const texto = await fs.promises.readFile(filePath, encoding);
        console.log(chalk.green(texto));
    } catch (err) {
        treatError(err);
    } finally {
        console.log('Finished reading file...')
    }
}

function linksExtract (textToExtractLinks) {
    const regEx = /\[([^\]]*)\]\((https?:\/\/[^$#\s].[^\s]*)\)/gm; //gm refers to global and multi-line  
    let extractedLinks = [];
    let temp;

    while((temp = regEx.exec(textToExtractLinks)) !== null) {
        extractedLinks.push({[(temp[1])] : temp[2]})
    }
    return extractedLinks;
}

const linksExtractedArr = linksExtract(texto1);
console.log(linksExtractedArr);

/*
    EXPRESSOES REGULARES:
    1) \[[\w]*\} ----> seleciona todas (*) as palavras (\w) dentro de (\[) e (\]) -> note que o '\' 
    é para que a [ e a ] nao sejam consfundidas com um vetor). Para o nosso caso o problema desta
    abordagem é que não seram considerados caracteres especiais incluidos dentro de '[]' no caso de
    '<input>' por exemplo, para resolver isso podemos realizar a expressão da seguinte maneira:

    2) \[([^\]]*)\]----> selecionas tudo (*) que começa em [ e não termina com ] (^\]) e vai até ]. 

    agora querendo encontrar os links kttps entre ()

    3) \((https?:\/\/[^$#\s].[^\s]*)\)/gm ---->  seleciona tudo que começa com '(https?://' + tudo que nao
    os '[]' aqui       \s faz referencia |   for '$', '#', ' ' (representado por \s) + '.' + tudo que
    criam uma classe.  a "white space". |    nao for ' ' até ')' (o qual também precisa iniciar com \).

    Para declarar una expressão regular em javascript utilizamos '//'

    ex: const regex = /[a-zA-z\s]/;
        let regex = new RegExp("[a-zA-z\s]");
*/                

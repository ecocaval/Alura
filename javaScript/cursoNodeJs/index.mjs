const chalk = require("chalk"); // must be installed through npm install chalk
const fs = require('fs'); // there's no need to install fs

function treatError (err) {
    throw new Error(chalk.red(err.code, "There's no reading file in this directory!"));
}

function catchFile (fileToCatchPath) {
    const encoding = 'utf-8';

    fs.promises
    .readFile(fileToCatchPath, encoding)
    .then((textFomFile) => console.log(chalk.yellow(textFomFile)))
    .catch((err) => treatError(err))
}

catchFile('./arquivos/texto1.md');

/*
function catchFile (fileToCatchPath) {
    const encoding = 'utf-8';
    const callBackCatchFIle = (err, textReceived) => {
        if(err) {
            return treatError(err)
        }
        return console.log(chalk.yellow(textReceived));
    };
    fs.readFile(fileToCatchPath, encoding, callBackCatchFIle);
}

fs refers to 'file system'  -> fs.readFile(file, [encoding], [callback]);
    obs: file = (string) filepath of the file to read;
        encoding = will normally refer to 'UTF-8';
        callback = function (err, data) {
            if (err) {
                return console.log(err);
            }
            console.log(data);
        }
*/

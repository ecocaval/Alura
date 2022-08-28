const chalk = require("chalk"); // must be installed through npm install chalk
const fs = require('fs'); // there's no need to install fs

/*
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

function catchFile (fileToCatchPath) {
    const encoding = 'utf-8';
    fs.readFile(fileToCatchPath, encoding, );
}
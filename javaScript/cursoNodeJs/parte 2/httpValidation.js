async function validaURLs (arrayDeLinksParaValidar) {

    const arrURLs = []

    const geraArrayDeURLs = (arr) => {
        arr.forEach(element => {
            arrURLs.push((Object.values(element))[0]);
        });
        // console.log(arrURLs);
    }

    geraArrayDeURLs(arrayDeLinksParaValidar);

    arrURLs.forEach(URL => {
        console.log(URL);
    })
    
}

module.exports = validaURLs
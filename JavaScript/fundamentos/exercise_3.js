let polygon = 'triangle';
let polygonHeight = 3;
let polygonLenght = 10;

var polygonArea;

if(polygon === 'triangle')
{
    polygonArea = polygonHeight * polygonLenght / 2;
} 
else
{
    polygonArea = polygonHeight * polygonLenght;
}

console.log(polygonArea);
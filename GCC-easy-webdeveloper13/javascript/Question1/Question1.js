'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));

    main();
});

function readLine() {
    return inputString[currentLine++];
}

function findMaxProfit(numOfPredictedDays, predictedSharePrices){
    return -1;
}

function main() {
    const line = readLine().split(' ');
    const numOfPredictedDay = line[0];
    const predictedSharePrices = line.slice(1)
    const predictedSharePricesInt = predictedSharePrices.map(num => parseInt(num, 10));

    const result = findMaxProfit(numOfPredictedDay, predictedSharePricesInt);

    // Please do not remove the below line.
    console.log(result)
    // Do not print anything after this line
}

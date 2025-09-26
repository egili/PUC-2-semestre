
// 25009281

function getNumbers() {

    let firstNumber = parseInt(prompt("Diga o primeiro numero: "));
    let secondNumber = parseInt(prompt("Diga o segundo numero: "));

    return [firstNumber, secondNumber];
}

function validateFriendNumbers(numbers) {
    if(!numbers || numbers.length !== 2) {
        console.log("Voce deve informar dois numeros");
        return false;
    }

    let sumDivisorsFirst = 0;
    let sumDivisorsSecond = 0;
    let firstNumber = numbers[0];
    let secondNumber = numbers[1];

    for(let i = 1; i < firstNumber; i++) {
        if(firstNumber % i === 0) {
            sumDivisorsFirst += i;
        }
    }

    for(let i = 1; i < secondNumber; i++) {
        if(secondNumber % i === 0) {
            sumDivisorsSecond += i;
        }
    }
    
    if(sumDivisorsFirst === secondNumber && sumDivisorsSecond === firstNumber) {
        return true;
    }
}

function main() {
    let numbers = getNumbers();
    if(validateFriendNumbers(numbers)) {
        console.log(`os numeros ${numbers[0]} e ${numbers[1]} sao amigos`);  
    } else {
        console.log(`os numeros ${numbers[0]} e ${numbers[1]} nao sao amigos`);
    }
}

main();


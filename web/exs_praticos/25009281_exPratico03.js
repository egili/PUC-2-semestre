// 25009281

function getMinMax() {
    let min = parseInt(prompt("Diga o valor mínimo do intervalo: "));
    let max = parseInt(prompt("Diga o valor máximo do intervalo: "));
    
    return [min, max];
}

function somaDivisoresProprios(numero) {
    let soma = 0;
    for (let i = 1; i < numero; i++) {
        if (numero % i === 0) {
            soma += i;
        }
    }
    return soma;
}

function encontrarNumerosAmigos(min, max) {
    let paresAmigos = [];
    
    for (let a = min; a <= max; a++) {
        let b = somaDivisoresProprios(a);
        
        if (b > a && b >= min && b <= max) {
            let somaDivisoresB = somaDivisoresProprios(b);
            
            if (somaDivisoresB === a) {
                paresAmigos.push([a, b]);
            }
        }
    }
    
    return paresAmigos;
}

function main() {
    let [min, max] = getMinMax();
    
    if (isNaN(min) || isNaN(max)) {
        console.log("Por favor, digite valores numéricos válidos.");
        return;
    }
    
    if (min > max) {
        console.log("O valor mínimo deve ser menor ou igual ao máximo.");
        return;
    }
    
    console.log(`Procurando pares de números amigos entre ${min} e ${max}...`);
    
    let paresAmigos = encontrarNumerosAmigos(min, max);
    
    if (paresAmigos.length === 0) {
        console.log(`Não foram encontrados pares de números amigos no intervalo [${min}, ${max}].`);
    } else {
        console.log(`Pares de números amigos encontrados no intervalo [${min}, ${max}]:`);
        paresAmigos.forEach(par => {
            console.log(`${par[0]} e ${par[1]} são amigos`);
            console.log(`\nSoma dos divisores de ${par[0]} = ${par[1]}`);
            console.log(`\n Soma dos divisores de ${par[1]} = ${par[0]}`);
        });
    }
}

main();
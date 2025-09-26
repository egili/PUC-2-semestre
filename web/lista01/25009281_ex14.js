// 25009281

// ex 14
let numeroContagem = prompt("Digite um número para iniciar a contagem regressiva:");

numeroContagem = Number(numeroContagem);

console.log(`Contagem regressiva a partir de ${numeroContagem}:`);
while (numeroContagem >= 0) {
    console.log(numeroContagem);
    numeroContagem--;
}
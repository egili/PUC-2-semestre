// 25009281

// ex 9
let n = prompt("Digite um número para ver a tabuada:");
n = Number(n);

console.log(`Tabuada do ${n}:`);
for (let i = 1; i <= 10; i++) {
    console.log(`${n} x ${i} = ${n * i}`);
}
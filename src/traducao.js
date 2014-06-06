div = 0;
document.write("Digite um numero"+"<br>");
num = parseInt(window.prompt(" "));
for (i=2;i<=num;i++){
    if ((num % i == 0))  {
        div = div + 1;
    }
}
if ((div == 1))  {
    document.write("O numero e primo"+"<br>");
}
else { 
    document.write("O numero nao e primo"+"<br>");
}

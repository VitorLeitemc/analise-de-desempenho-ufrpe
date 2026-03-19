#include <iostream>  // Biblioteca para ler e escrever no console
#include <vector>    // Para usar listas dinâmicas de números
#include <limits>    // Para tratar erros de entrada (letras em vez de números)

using namespace std;

void encontrarPrimos(int n) {
    // Criamos uma "lista de verificação" de tamanho N+1.
    // No começo, assumimos que todos são verdadeiros (primos).
    vector<bool> e_primo(n + 1, true);
    
    // 0 e 1 não são primos por definição
    if (n >= 0) e_primo[0] = false;
    if (n >= 1) e_primo[1] = false;

    // Estratégia rápida: Crivo de Eratóstenes
    // Vamos de 2 até a raiz quadrada de N
    for (int p = 2; p * p <= n; p++) {
        // Se p ainda é marcado como primo, então todos os seus múltiplos não são!
        if (e_primo[p]) {
            for (int i = p * p; i <= n; i += p)
                e_primo[i] = false;
        }
    }

    // Agora vamos exibir os resultados solicitados
    cout << "\nValor de N: " << n << endl;
    cout << "Numeros primos encontrados: ";

    int contador = 0;
    bool primeiro = true;

    for (int i = 2; i <= n; i++) {
        if (e_primo[i]) {
            // Se não for o primeiro, coloca o traço "-" antes do número
            if (!primeiro) cout << " - ";
            cout << i;
            contador++;
            primeiro = false;
        }
    }

    cout << "\nQuantidade de numeros primos: " << contador << endl;
}

int main() {
    int n;

    while (true) {
        cout << "Digite um numero inteiro N > 0: ";
        
        // Verifica se a entrada é um número e se é maior que 0
        if (cin >> n && n > 0) {
            encontrarPrimos(n);
            break; // Sai do loop se der tudo certo
        } else {
            // "Tratamento" se o usuário digitar letra ou número < 1
            cout << "Entrada invalida! Por favor, digite um numero inteiro positivo.\n";
            cin.clear(); // Limpa o erro do console
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta o que foi digitado
        }
    }

    return 0;
}
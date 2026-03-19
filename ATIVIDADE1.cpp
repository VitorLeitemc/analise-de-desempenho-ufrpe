#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void encontrarPrimos(int n) {
    vector<bool> e_primo(n + 1, true);
    
    if (n >= 0) e_primo[0] = false;
    if (n >= 1) e_primo[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (e_primo[p]) {
            for (int i = p * p; i <= n; i += p)
                e_primo[i] = false;
        }
    }

    cout << "\nValor de N: " << n << endl;
    cout << "Numeros primos encontrados: ";

    int contador = 0;
    bool primeiro = true;

    for (int i = 2; i <= n; i++) {
        if (e_primo[i]) {
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
        
        if (cin >> n && n > 0) {
            encontrarPrimos(n);
            break;
        } else {
           
            cout << "Entrada invalida! Por favor, digite um numero inteiro positivo.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}
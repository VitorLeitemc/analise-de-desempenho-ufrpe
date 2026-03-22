#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

// ==========================================================
// PARTE I - VETORES
// ==========================================================

// 1. Soma de elementos
int soma_elementos(vector<int> lista) {
    int total = 0;
    for (int num : lista) {
        total += num;
    }
    return total;
}

// 2. Contar números pares
int contar_pares(vector<int> lista) {
    int qtd = 0;
    for (int num : lista) {
        if (num % 2 == 0) qtd++;
    }
    return qtd;
}

// 3. Maior número
int maior_numero(vector<int> lista) {
    if (lista.empty()) return 0;
    int maior = lista[0];
    for (int num : lista) {
        if (num > maior) maior = num;
    }
    return maior;
}

// 4. Contar elementos maiores que X
int contar_maiores_que_x(vector<int> lista, int x) {
    int contador = 0;
    for (int num : lista) {
        if (num > x) contador++;
    }
    return contador;
}

// 5. Soma dos pares
int soma_pares(vector<int> lista) {
    int soma = 0;
    for (int num : lista) {
        if (num % 2 == 0) soma += num;
    }
    return soma;
}

// 6. Verificar existência de elemento
bool existe_elemento(vector<int> lista, int x) {
    for (int num : lista) {
        if (num == x) return true;
    }
    return false;
}

// 7. Inverter lista (Sem funções prontas)
vector<int> inverter_lista(vector<int> lista) {
    vector<int> nova_lista;
    for (int i = lista.size() - 1; i >= 0; i--) {
        nova_lista.push_back(lista[i]);
    }
    return nova_lista;
}

// 8. Contar ocorrências
int contar_ocorrencias(vector<int> lista, int x) {
    int contador = 0;
    for (int num : lista) {
        if (num == x) contador++;
    }
    return contador;
}

// 9. Soma dos valores positivos
int soma_positivos(vector<int> lista) {
    int soma = 0;
    for (int num : lista) {
        if (num > 0) soma += num;
    }
    return soma;
}

// 10. Produto dos elementos
int produto_elementos(vector<int> lista) {
    if (lista.empty()) return 0;
    int produto = 1;
    for (int num : lista) {
        produto *= num;
    }
    return produto;
}

// ==========================================================
// PARTE II - STRINGS
// ==========================================================

// 11. Contar vogais
int contar_vogais(string s) {
    int contador = 0;
    string vogais = "aeiouAEIOU";
    for (char c : s) {
        if (vogais.find(c) != string::npos) {
            contador++;
        }
    }
    return contador;
}

// 12. Contar caracteres (Sem usar .length() ou .size())
int contar_caracteres(string s) {
    int contador = 0;
    for (char c : s) {
        contador++; 
    }
    return contador;
}

// 13. Verificar palíndromo
bool eh_palindromo(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        if (tolower(s[i]) != tolower(s[n - 1 - i])) {
            return false;
        }
    }
    return true;
}

// 14. Contar ocorrências de um caractere
int contar_char(string s, char c) {
    int contador = 0;
    for (char atual : s) {
        if (atual == c) contador++;
    }
    return contador;
}

// 15. Substituir caractere
string substituir_char(string s, char c1, char c2) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == c1) s[i] = c2;
    }
    return s;
}

// 16. Maiúsculas e minúsculas
string contar_cases(string s) {
    int mai = 0, min = 0;
    for (char c : s) {
        if (isupper(c)) mai++;
        else if (islower(c)) min++;
    }
    return "Maiusculas: " + to_string(mai) + " | Minusculas: " + to_string(min);
}

// 17. Remover espaços
string remover_espacos(string s) {
    string resultado = "";
    for (char c : s) {
        if (c != ' ') resultado += c; 
    }
    return resultado;
}

// 18. Primeiro caractere
char primeiro_caractere(string s) {
    if (s.empty()) return '\0'; 
    return s[0];
}

// ==========================================================
// FUNÇÃO PRINCIPAL DE TESTES
// ==========================================================
int main() {
    // --- TESTES PARTE I: VETORES ---
    vector<int> v = {1, 2, 3, 4};
    vector<int> v_pdf = {3, 7, 2, 9, 5};
    vector<int> v_neg = {-1, 2, 3, 4, 5};

    cout << "1. Soma [1,2,3,4]: " << soma_elementos(v) << " (Esperado: 10)" << endl;
    cout << "2. Pares [1,2,3,4]: " << contar_pares(v) << " (Esperado: 2)" << endl;
    cout << "3. Maior [3,7,2,9,5]: " << maior_numero(v_pdf) << " (Esperado: 9)" << endl;
    cout << "4. Maiores que 5 em [1,5,8,2,10]: " << contar_maiores_que_x({1, 5, 8, 2, 10}, 5) << " (Esperado: 2)" << endl;
    cout << "5. Soma pares [1,2,3,4]: " << soma_pares(v) << " (Esperado: 6)" << endl;
    cout << "6. Existe 7 em [4,7,1,9]? " << (existe_elemento({4, 7, 1, 9}, 7) ? "sim" : "nao") << endl;
    
    cout << "7. Inverter [1,2,3,4]: ";
    for(int x : inverter_lista(v)) cout << x << " ";
    cout << endl;

    cout << "8. Ocorrencias de 2 em [1,2,2,3,2,4]: " << contar_ocorrencias({1,2,2,3,2,4}, 2) << endl;
    cout << "9. Soma positivos [-1,2,3,4,5]: " << soma_positivos(v_neg) << endl;
    cout << "10. Produto [1,2,3,4]: " << produto_elementos(v) << endl;

    // --- TESTES PARTE II: STRINGS ---
    cout << "\n11. Vogais 'Programacao': " << contar_vogais("Programacao") << endl;
    cout << "12. Caracteres 'teste': " << contar_caracteres("teste") << endl;
    cout << "13. Palindromo 'arara': " << (eh_palindromo("arara") ? "sim" : "nao") << endl;
    cout << "14. 'a' em 'banana': " << contar_char("banana", 'a') << endl;
    cout << "15. Substituir 'a' por 'o': " << substituir_char("banana", 'a', 'o') << endl;
    cout << "16. " << contar_cases("AbCde") << endl;
    cout << "17. Remover espacos: " << remover_espacos("ola mundo") << endl;
    cout << "18. Primeiro char 'python': " << primeiro_caractere("python") << endl;

    return 0;
}
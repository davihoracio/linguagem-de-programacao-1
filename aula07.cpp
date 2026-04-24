#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

int main()
{
    vector<int> Numeros(5);
    int indiceBusca;

    cout << "Digite 5 valores: \n";
    for (int i = 0; i < 5; i++)
    {
        cin >> Numeros[i];
    }

    cout << "Digite o valor que deseja acessar: \n";
    cin >> indiceBusca;

    try
    {
        cout << "Valor armazenado: " << Numeros.at(indiceBusca) << endl;
    }
    catch (const out_of_range &e)
    {
        cout << "Erro: O indice digitado esta fora dos limites do vetor!" << endl;
    }
}
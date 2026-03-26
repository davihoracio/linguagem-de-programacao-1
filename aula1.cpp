#include <iostream>

using namespace std;

int main(){

    int num1;
    int num2; 
    int operacao;
    int resultado;

        while (operacao != 0){
            cout << "Digite o primeiro numero: ";
            cin >> num1;
            cout << "Digite o segundo numero: ";
            cin >> num2;

            cout << "Digite o numero da operacao desejada:\n 1 - Soma\n 2 - Subtracao\n 3 - Divisao\n 4 - Multiplicacao\n 0 - Sair\n";
            cin >> operacao;
            
            switch (operacao){
                case 1:
                    resultado = num1 + num2;
                    cout << "O resultado da soma: " << resultado << endl;
                    break;
                case 2:
                    resultado = num1 - num2;
                    cout << "O resultado da subtracao: " << resultado << endl;
                    break;
                case 3:
                    resultado = num1/num2;
                    cout << "O resultado da divisao: " << resultado << endl;
                    break;
                case 4: 
                    resultado = num1*num2;
                    cout << "O resultado da multiplicacao: " << resultado <<endl;
                    break;
                case 0: 
                    break;
                default:
                    cout << "Digite uma operacao valida" << endl;
        }}
}
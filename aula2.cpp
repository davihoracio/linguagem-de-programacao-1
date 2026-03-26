#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct Aluno
{
    int id{0};
    string name;
    int idade{0};
    int nota1{0};
    int nota2{0};
    int nota3{0};

    double media() const
    {
        return (nota1 + nota2 + nota3) / 3.0;
    }
};

struct Turma
{
    static constexpr int capacidadeMaxima{40};
    Aluno alunos[capacidadeMaxima];
    int quantidadeAlunos{0};

    bool adicionarAluno(const Aluno &aluno)
    {
        if (quantidadeAlunos >= capacidadeMaxima)
        {
            return false;
        }

        alunos[quantidadeAlunos++] = aluno;
        return true;
    }

    void exibirAlunos() const
    {
        if (quantidadeAlunos == 0)
        {
            cout << "Nenhum aluno cadastrado." << endl;
            return;
        }

        cout << "\n--- Lista de alunos ---" << endl;
        for (int i = 0; i < quantidadeAlunos; i++)
        {
            cout << "ID: " << alunos[i].id << " | Nome: " << alunos[i].name
                 << " | Idade: " << alunos[i].idade
                 << " | Media: " << fixed << setprecision(2) << alunos[i].media() << endl;
        }
    }

    const Aluno *buscarPorId(int id) const
    {
        for (int i = 0; i < quantidadeAlunos; i++)
        {
            if (alunos[i].id == id)
            {
                return &alunos[i];
            }
        }
        return nullptr;
    }

    double mediaGeral() const
    {
        if (quantidadeAlunos == 0)
        {
            return 0.0;
        }

        double soma = 0.0;
        for (int i = 0; i < quantidadeAlunos; i++)
        {
            soma += alunos[i].media();
        }
        return soma / quantidadeAlunos;
    }
};

int main()
{
    Turma turma;

    cout << "Quantos alunos deseja cadastrar (maximo 40)? ";
    int quantidadeCadastrar = 0;
    cin >> quantidadeCadastrar;

    if (quantidadeCadastrar > Turma::capacidadeMaxima)
    {
        cout << "Quantidade maior que a capacidade permitida. Serao cadastrados apenas 40 alunos." << endl;
        quantidadeCadastrar = Turma::capacidadeMaxima;
    }

    for (int i = 0; i < quantidadeCadastrar; i++)
    {
        Aluno aluno;
        cout << "\n--- Cadastro do aluno " << i + 1 << " ---" << endl;
        cout << "ID do aluno: ";
        cin >> aluno.id;
        cout << "Nome do aluno: ";
        cin >> aluno.name;
        cout << "Idade do aluno: ";
        cin >> aluno.idade;
        cout << "Nota 1 do aluno: ";
        cin >> aluno.nota1;
        cout << "Nota 2 do aluno: ";
        cin >> aluno.nota2;
        cout << "Nota 3 do aluno: ";
        cin >> aluno.nota3;

        if (!turma.adicionarAluno(aluno))
        {
            cout << "Nao foi possivel adicionar mais alunos." << endl;
            break;
        }
    }

    turma.exibirAlunos();

    cout << "\nDigite o ID do aluno para buscar: ";
    int idBusca = 0;
    cin >> idBusca;
    const Aluno *encontrado = turma.buscarPorId(idBusca);
    if (encontrado)
    {
        cout << "\nAluno encontrado:" << endl;
        cout << "ID: " << encontrado->id << endl;
        cout << "Nome: " << encontrado->name << endl;
        cout << "Idade: " << encontrado->idade << endl;
        cout << "Notas: " << encontrado->nota1 << ", " << encontrado->nota2 << ", " << encontrado->nota3 << endl;
        cout << fixed << setprecision(2) << "Media final: " << encontrado->media() << endl;
    }
    else
    {
        cout << "Aluno nao encontrado." << endl;
    }

    cout << fixed << setprecision(2);
    cout << "\nMedia geral da turma: " << turma.mediaGeral() << endl;

    return 0;
}
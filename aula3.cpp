#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Item
{
    string nome;
    int quantidade{0};
    double valorUnitario{0};
};

struct Pedido
{
    vector<Item> listaPedido;

    void adicionarItemAoPedido(Item item)
    {
        listaPedido.push_back(item);
    }

    void calcularValorTotal()
    {
        int valorTotal = 0;
        for (int i = 0; i < listaPedido.size(); i++)
        {
            valorTotal += listaPedido[i].quantidade * listaPedido[i].valorUnitario;
        }

        cout << "Valor total do pedido: " << valorTotal;
    }
};

enum Orientacao
{
    RETRATO,
    PAISAGEM
};

struct Impressora
{
    void imprimirItem(vector<Item> itens, Orientacao orientacao = RETRATO)
    {
        string modoStr = (orientacao == RETRATO) ? "Retrato" : "Paisagem";
        cout << "--- Imprimindo em Modo " << modoStr << " ---\n";
        for (int i = 0; i < itens.size(); i++)
        {
            cout << "Item [" << i << "]: " << itens[i].nome << " (Qtd: " << itens[i].quantidade << ", Valor: " << itens[i].valorUnitario << ")\n";
        }
    }

    void imprimirItem(Item item, Orientacao orientacao = RETRATO)
    {
        string modoStr = (orientacao == RETRATO) ? "Retrato" : "Paisagem";
        cout << "--- Imprimindo em Modo " << modoStr << " ---\n";
        cout << "Item: " << item.nome << " (Qtd: " << item.quantidade << ", Valor: " << item.valorUnitario << ")\n";
    }
};

int main()
{
    int quantidadeDeItens{0};

    cout << "Quantos itens deseja pedir? ";
    cin >> quantidadeDeItens;

    Pedido pedido;

    for (int i = 0; i < quantidadeDeItens; i++)
    {
        Item itemNovo;
        cout << "Digite o nome do item: ";
        cin >> itemNovo.nome;
        cout << "Digite a quantidade do item: ";
        cin >> itemNovo.quantidade;
        cout << "Digite o valor do item: ";
        cin >> itemNovo.valorUnitario;

        pedido.adicionarItemAoPedido(itemNovo);
    }

    pedido.calcularValorTotal();

    Impressora impressora;

    impressora.imprimirItem(pedido.listaPedido);
    impressora.imprimirItem(pedido.listaPedido[0]);
}
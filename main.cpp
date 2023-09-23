#include "ListaODE.h"

using namespace std;

int main()
{
    ListaODE **V, obj, *Resp;
    V = new ListaODE* [2];
    V[0] = NULL;
    V[1] = NULL;
    string nome, raca;
    int idade, tipo, op;
    bool achei;
    do{
        system("clear");
        cout << "1 - Cadastrar Pet\n";
        cout << "2 - Excluir Pet\n";
        cout << "3 - Listagem Geral\n";
        cout << "4 - Listagem de cães\n";
        cout << "5 - Listagem de gatos\n";
        cout << "6 - Pesquisar\n";
        cout << "7 - Sair\n";
        cout << "Informe a opção:";
        cin >> op;
        switch (op){

        case 1: // Cadastrar o pet
            cout << "Informe o nome: ";
            cin.ignore();
            getline(cin, nome);
            cout << "Informe a raça: ";
            cin.ignore();
            getline(cin, raca);
            cout << "Informe a idade: ";
            cin >> idade;
            cout << "Informe o tipo (1 - Cães ou 2 - Gatos): ";
            cin >> tipo;

            V = obj.Inserir(V, nome, raca, idade, tipo);
            cout << " Inserido com sucesso!!\n ";
            break;

        case 2: // Excluir algum pet
            if (V[0] == NULL){
                cout << "Sem registros para excluir!\n";
            }else{
                cout << "Informe o nome: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Informe o tipo((1 - Cães ou 2 - Gatos): ";
                cin >> tipo;
                V = obj.Excluir(V, nome, tipo, &achei);
                if (achei){
                    cout << "Deletado com sucesso!!\n";
                }else{
                    cout << "Informação não cadastrada...\n";
                }
            }
            break;

        case 3: // Listagem geral dos pets

            if (V[0] == NULL){
                cout << "Sem registros para listar!\n";
            }else{
                cout << "Listagem Geral de pets:\n";
                obj.Exibir(V, 3);
            }
            break;

        case 4: // Listagem dos cães
            if (V[0] == NULL){
                cout << " Sem registros para listar!\n";
            }else{
                cout << " Listagem de cães:\n";
                obj.Exibir(V, 1);
            }
            break;

        case 5: // Listagem dos gatos
            if (V[1] == NULL){
                cout << " Sem registros para listar!\n";
            }else{
                cout << " Listagem de gatos:\n";
                obj.Exibir(V, 2);
            }
            break;


        case 6: // Pesquisar algum pet
            if(V[0] == NULL){
                cout << "Lista vazia\n";
            } else {
                cout << "Informe o nome: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Informe o tipo (1 - Cães ou 2 - Gatos): ";
                cin >> tipo;
                Resp = obj.Pesquisar(V, nome, tipo);
                if (Resp == NULL){
                    cout << "Contato não cadastrado\n";
                }else{
                    cout << "Dados do contato: " << Resp->getNome() << " - "  << Resp->getRaca() << " - " << Resp->getIdade() <<
                    " - " << Resp->getTipo() << "\n";
                }
            }

            break;

        case 7:
            cout << " Espero que tenha tido um ótimo AUtendimento!!\n";
            break;

        default:
            cout << " Opção inválida!!\n";
        }
        cout << "Pressione ENTER para continuar";
        cin.ignore().get();
    } while (op != 7);
    return 0;
}

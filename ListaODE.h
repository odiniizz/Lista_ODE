#include <iostream>

class ListaODE {
    private:
        std::string Nome, Raca;
        int Tipo, Idade;
        ListaODE *anterior, *proximo;
    public :
        ListaODE** Inserir(ListaODE**, std::string, std::string, int, int);
        ListaODE** Excluir(ListaODE**, std::string, int, bool*) ;
        void Exibir(ListaODE**, int);
        ListaODE* Pesquisar(ListaODE**, std::string, int);
        std::string getNome();
        std::string getRaca();
        std::string getTipo();
        int getIdade();
};

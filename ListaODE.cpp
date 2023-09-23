#include "ListaODE.h"

//*****************************************************************************************//

ListaODE** ListaODE::Inserir (ListaODE **P, std::string N, std::string R, int I, int T){
    ListaODE *novo = new ListaODE();
    novo->Nome = N;
    novo->Raca = R;
    novo->Idade = I;
    novo->Tipo = T;

    //Primeiro elemento a ser inserido:
    if (P[0] == NULL){
        P[0] = novo;
        P[1] = novo;
        P[0]->anterior = NULL;
        P[1]->proximo = NULL;

    } else {

        ListaODE *atual = P[0];


        if(novo->Tipo == 1){
            while((atual != NULL) && (atual->Tipo == 1) && ( atual->Nome < novo->Nome)){
            // Caso o tipo seja diferente de 1 (o pet a ser inserido não é um cão), o while irá parar.
                atual = atual->proximo;
            }

        } else {
            atual = P[1];
            while((atual != NULL) && (atual->Tipo == 2) && ( atual->Nome > novo->Nome)){
            // Caso o tipo seja diferente de 2 (o pet a ser inserido não é um gato), o while irá parar.
                atual = atual->anterior;
            }
        }
        if ((atual == P[0] && novo->Tipo == 1) || (atual == NULL && novo->Tipo == 2)){
        /* O animal que está em primeiro lugar no vetor é um gato. Sendo assim, o animal (cão) será inserido
        anteriormente à posição em que o gato está, se tornando o primeiro elemento do vetor. */
            novo->proximo = P[0];
            P[0]->anterior = novo;
            P[0] = novo;
            P[0]->anterior = NULL;
        } else if ((atual == NULL && novo->Tipo == 1) || (atual == P[1] && novo->Tipo == 2)){
        /* O animal que está em primeiro lugar no vetor é um cão. Sendo assim, o animal (gato) será inserido
        posteriormente à posição em que o gato está, se tornando o primeiro elemento do vetor. */
            P[1]->proximo = novo;
            novo->anterior = P[1];
            P[1] = novo;
            P[1]->proximo = NULL;
        } else if(novo->Tipo == 1) {
        /* o animal será um cão (creio eu?) e será inserido em alguma posição no meio do vetor. */
            atual->anterior->proximo = novo;
            novo->anterior = atual->anterior;
            novo->proximo = atual;
            atual->anterior = novo;
        } else if (novo->Tipo == 2){
            novo->anterior = atual;
            atual->proximo->anterior = novo;
            novo->proximo = atual->proximo;
            atual->proximo = novo;
        }
    }
    return P;
};

//*****************************************************************************************//

ListaODE** ListaODE::Excluir(ListaODE **P, std::string N, int T, bool *achei){
    ListaODE *atual;
    if (T == 1){
        atual = P[0];
        while ((atual != NULL) && (atual->Nome != N) && (atual->Tipo == 1)){
        /* enquanto o nome e o tipo dos animais que estiverem ao longo do vetor forem diferentes daqueles digitados,
        o laço vai continuar até encontrar */
        atual = atual->proximo;
        }
    } else {
        atual = P[1];
        while ((atual != NULL) && (atual->Nome != N) && (atual->Tipo == 2)){

        atual = atual->anterior;
        }

    }
    if ((atual == NULL) || ((atual != NULL) && (atual->Tipo != T))){
        *achei = false;
    } else {
        *achei = true;
        if (atual == P[0]){
            P[0]->anterior = NULL;
            P[0] = P[0]->proximo;
        } else if (atual == P[1]){
            P[1]= P[1]->anterior;
            P[1]->proximo = NULL;
        } else if (T == 1){
            atual->anterior->proximo = atual->proximo;
            atual->proximo->anterior = atual->anterior;
        } else {
            atual->proximo->anterior = atual->anterior;
            atual->anterior->proximo = atual->proximo;
        }
        delete(atual);
    }
    return P;
};

//*****************************************************************************************//

void ListaODE::Exibir(ListaODE **P, int tipolistagem){
    ListaODE *aux;
    bool tem = false;
    if (tipolistagem == 1){
    // 1 - Listagem dos cães
        aux = P[0];
        while ((aux != NULL) && (aux->Tipo == 1)){
            tem = true;
            std::cout << "Nome: " << aux->getNome() << " - Raça: "
            << aux->Raca << " Tipo: " << aux->getTipo() << " - Idade: " << aux->Idade << " anos\n";
            aux = aux->proximo;
        }
        if(!tem){
            std::cout << "Não há nenhum cão cadastrado!\n";
        }
    } else if (tipolistagem == 2){
        // 2 - Listagem dos gatos
        aux = P[1];
        while ((aux != NULL) && (aux->Tipo == 2)){
            std::cout << "Nome: " << aux->getNome() << " - Raça: "
            << aux->Raca << " Tipo: " << aux->getTipo() << " - Idade: " << aux->Idade << " anos\n";
            aux = aux->anterior;
        }
        if(!tem){
            std::cout << "Não há nenhum gato cadastrado!\n";
        }
    } else {
        // Listagem geral dos pets
        aux = P[0];
        while ((aux != NULL)){
            std::cout << "Nome: " << aux->getNome() << " - Raça: "
            << aux->getRaca() << " Tipo: " << aux->getTipo() << " - Idade: " << aux->Idade << " anos\n";
            aux = aux->proximo;
        }
    }
};

//*****************************************************************************************//

ListaODE* ListaODE::Pesquisar(ListaODE **P, std::string N, int T){
    ListaODE *aux;
    if (T == 1){
        aux = P[0];
        while((aux != NULL) && (aux->Nome != N) && (aux->Tipo == 1)){
            aux = aux->proximo;
        }
    } else {
        aux = P[1];
        while((aux != NULL) && (aux->Nome != N) && (aux->Tipo == 2)){
            aux = aux->anterior;
        }
    }
    if ((aux != NULL) && (aux->Tipo != T)){
        aux = NULL;
    }
    return aux;
};

//*****************************************************************************************//


std::string ListaODE::getNome(){
    return this->Nome;
};

std::string ListaODE::getRaca(){
    return this->Raca;
};

std::string ListaODE::getTipo(){
    if(this->Tipo == 1){
        return "Cão";
    } else {
        return "Gato";
    }
};

int ListaODE::getIdade(){
    return this->Idade;
};



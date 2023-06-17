#include "CaixaEntrada.hpp"

// Construtor caixa de entrada
CaixaEntrada::CaixaEntrada(){
    this->head = nullptr;
}

void CaixaEntrada::limpa(){
    while(this->head != nullptr){
        Email *e;
        e = this->head;
        this->head = this->head->next;
        delete e;
    }
    this->size = 0;
}

CaixaEntrada::~CaixaEntrada(){
    limpa();
    delete this->head;
}

/* Recebe o email como parâmetro e armazena na fila de acordo 
com sua prioridade */
void CaixaEntrada::armazenarMensagens(Email *_email){
    Email* comeco = head;
    Email *temp = _email;
    if(this->head == nullptr)
        this->head = _email;
    else if (head->prioridade < _email->prioridade) {
        temp->next = this->head;
        this->head = temp;
    } else {
        while (comeco->next != nullptr && comeco->next->prioridade >= _email->prioridade)
            comeco = comeco->next;
        temp->next = comeco->next;
        comeco->next = temp;
    }
    size++;
}

/* Imprime o primeiro email da fila (maior prioridade) 
e em seguida o remove da fila */
void CaixaEntrada::lerEmail(){
    Email *temp = head;
    cout << head->mensagem << endl;
    LEMEMLOG((long int)&(this->head->mensagem), sizeof(string), 0);
    head = head->next;
    delete temp;
    size--;
}

/* Verifica se a caixa de entrada está vazia, ou seja,
se não tem nenhum email cadastrado*/
bool CaixaEntrada::verificarVazio(){
    if(this->head == nullptr)
        return true;
    return false;
}
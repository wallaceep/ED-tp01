#include "ListaUsuario.hpp"

void ListaUsuario::limpa(){
    Usuario *u = this->first->next;
    while (u!=nullptr){
        this->first->next = u->next;
        delete u;
        u = this->first->next;
    }
    this->last = this->first;
}


ListaUsuario::~ListaUsuario(){
    limpa();
    delete this->first;
}

/* Se o usuario com id passado por parâmetro não existir,
cadastra ele na lista*/
void ListaUsuario::cadastrarUsuario(int _id){

    Usuario *aux = new Usuario(_id);

    if(first == nullptr){
        first = aux;
        last = aux;
    } else if(verificarExistencia(_id)){
        cout << "ERRO: CONTA " << _id << " JA EXISTENTE" << endl;
        return;
    } else {
        aux->next = first;
        first = aux;    
    }
    cout << "OK: CONTA " << _id << " CADASTRADA" << endl;
}

/*Se o usuario passado por parâmetro existir, remove ele da luista*/
void ListaUsuario::removerUsuario(int _id){
    Usuario *temp = this->first;
    Usuario *prev = this->first;
    if(!verificarExistencia(_id))
        cout << "ERRO: CONTA " << _id << " NAO EXISTE" << endl;
    else{
        while(prev != nullptr){
            if(this->first->ID == _id)
                this->first = this->first->next;
            else if(prev->next == nullptr)
                break;
            else if(prev->next->ID == _id){
                temp = prev->next;
                prev->next = temp->next;
                delete temp;
                break;
            }
            prev = prev->next;
        }
    cout << "OK: CONTA " << _id << " REMOVIDA" << endl;
    }
    //remove o usuario e sua caixa de entrada com todos os e-mails.
}

/* Verifica se o usuario existe e armazena o email passado por parametro
de acordo com sua prioridade*/
void ListaUsuario::entregarMsg(int _id, int _pri, string _msg){
    if(verificarExistencia(_id)){
        Usuario *aux = retornaUser(_id);
        Email *e = new Email(_msg, _pri);
        aux->inbox.armazenarMensagens(e);
        cout << "OK: MENSAGEM PARA " << _id << " ENTREGUE" << endl;
        // ESCREVEMEMLOG((long int)(e), sizeof(Email), _id);
    } else {
        cout << "ERRO: CONTA " << _id << " NAO EXISTE" << endl;
    }
}

/* Consulta a caixa de entrada do usuário cujo id é passado 
por parâmetro, e caso exista e não esteja vazia, imprime o 
primeiro email da lista*/
void ListaUsuario::consultarInbox(int _id){
    if(verificarExistencia(_id)){
        Usuario *aux = retornaUser(_id);
        cout << "CONSULTA " << _id << ":";
        if(aux->inbox.verificarVazio()){
            cout << " CAIXA DE ENTRADA VAZIA" << endl;
            return;
        }
        aux->inbox.lerEmail();
    } else {
        cout << "ERRO: CONTA " << _id << " NAO EXISTE" << endl;
    }
}

/* Percorre a lista de usuários e retorna
o usuário com ID passado por parâmetro */
Usuario *ListaUsuario::retornaUser(int _id){
    Usuario *user = this->first; 
    while (user != nullptr) {
        if(user->ID == _id)
            return user;
        user = user->next;
    }
    return nullptr;
}

/* Percorre a lista de usuários e verifica
se o usuário com ID passado por parâmetro existe */
bool ListaUsuario::verificarExistencia(int _id){
    Usuario *user = this->first; 
    while (user != nullptr) {
        if(user->ID == _id)
            return true;
        user = user->next;
    }
    return false;
}
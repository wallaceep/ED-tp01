#include "CaixaEntrada.hpp"
#include "Email.hpp"
#include "Usuario.hpp"
#include "ListaUsuario.hpp"
#include "msgassert.h"
#include "memlog.h"

#include <getopt.h>
#include <string.h>
#include <fstream>

using namespace std;

char logname[10];
int regmem = 1;
extern char *optarg;

int main(int argc, char **argv){
    CaixaEntrada inbox;
    ListaUsuario user;
    string comando, MSG, filename;
    int ID, PRI, op;

    if(argc < 2 || argc>3){
        erroAssert(0, "Numero de argumentos inválido!");
        return 1;
    }

    filename = argv[1];

    while ((op = getopt(argc, argv, "p")) != EOF){
        switch(op){
        case 'p':
            strcpy(logname, "log.out");
            iniciaMemLog(logname);
            ativaMemLog();
            break;
        default:
            desativaMemLog();
            exit(1);
        }
    }

    ifstream file(filename);

    if(file.is_open()){
        while(file >> comando){
            if(comando == "CADASTRA"){
                file >> ID;
                user.cadastrarUsuario(ID);

            } else if(comando == "REMOVE"){
                file >> ID;
                user.removerUsuario(ID);

            } else if(comando =="ENTREGA"){
                file >> ID >> PRI;
                getline(file, MSG); 

                size_t found = MSG.find("FIM");
                if(found == string::npos)
                    avisoAssert(0, "MENSAGEM SEM FIM");
    
                MSG.erase(MSG.find("FIM"));
                user.entregarMsg(ID, PRI, MSG);

            } else if(comando =="CONSULTA"){
                file >> ID;
                user.consultarInbox(ID);

            } else {
                avisoAssert(0, "COMANDO INVALIDO!");
            }
        }
    } else
        erroAssert(0, "ERRO AO ABRIR ARQUIVO");

    file.close();

    if(argc > 2)
        finalizaMemLog();

    return EXIT_SUCCESS;
}
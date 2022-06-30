#ifndef Servidores_hpp
#define Servidores_hpp

#include "CanalTexto.hpp"
#include "Usuario.hpp"
#include <vector>
#include <iostream>

using namespace std;

class Servidores{

    private :
        unsigned int m_id;  //Identificador único para o este servidor
        Usuario* m_dono;    //Referência para o usuário que criou o servidor
        string m_nome;      //Nome do servidor, passado no comando create-server 
        vector<CanalTexto*> m_canaisTexto; //Um vetor contendo todos os canais de texto deste servidor
        vector<Usuario*> m_participantes; //Um vetor contendo referências para todos os participantes deste servidor.

    public :
        
        Servidores();
};

#endif //Servidores_hpp
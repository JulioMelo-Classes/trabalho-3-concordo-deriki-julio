#ifndef Mensagem_hpp
#define Mensagem_hpp

#include <iostream>
#include "Usuario.hpp"
using namespace std;

class Mensagem{

    private :

        unsigned int m_id;
        string m_dataHora;
        Usuario* m_enviadaPor;
        string m_conteudo;

    public :
};

#endif //Mensagem_hpp
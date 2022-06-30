#ifndef CanalTexto_hpp
#define CanalTexto_hpp

#include <vector>
#include <iostream>
#include "Usuario.hpp"
#include "Mensagem.hpp"

using namespace std;

class CanalTexto{

    private :
        
        unsigned int m_id;
        string m_nome;
        Usuario* m_dono;
        vector<Mensagem*> m_mensagens; // obs

    public :

};

#endif //CanalTexto_hpp
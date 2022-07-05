/**
 * @file Mensagem.hpp
 * @author Deriki Pereira (derikipereira@outlook.com)
 * @brief Header class Mensagem
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef Mensagem_hpp
#define Mensagem_hpp

#include <iostream>
#include "Usuario.hpp"

class Mensagem{

    private :

        unsigned int m_id;
        std::string m_dataHora;
        Usuario* m_enviadaPor;
        std::string m_conteudo;

    public :

        Mensagem(int id, std::string dataHora, Usuario* enviadaPor, std::string conteudo);

        int get_id();

        std::string get_dataHora();

        Usuario* get_enviadaPor();

        std::string get_conteudo();

};

#endif //Mensagem_hpp
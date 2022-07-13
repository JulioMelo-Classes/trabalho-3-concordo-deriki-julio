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

        /**
         * @brief Construct a new Mensagem object
         * 
         * @param id identificador.
         * @param dataHora string da data e hora da criação.
         * @param enviadaPor dono da mensagem.
         * @param conteudo conteudo da mensagem.
         */
        Mensagem(int id, std::string dataHora, Usuario* enviadaPor, std::string conteudo);

        /**
         * @brief Get the id object
         * 
         * @return int 
         */
        int get_id();

        /**
         * @brief Get the dataHora object
         * 
         * @return std::string 
         */
        std::string get_dataHora();

        /**
         * @brief Get the enviadaPor object
         * 
         * @return Usuario* 
         */
        Usuario* get_enviadaPor();

        /**
         * @brief Get the conteudo object
         * 
         * @return std::string 
         */
        std::string get_conteudo();

};

#endif //Mensagem_hpp
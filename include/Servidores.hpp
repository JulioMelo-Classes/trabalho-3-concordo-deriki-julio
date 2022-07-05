/**
 * @file Servidores.hpp
 * @author Deriki Pereira (derikipereira@outlook.com)
 * @brief Header class Servidores
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef Servidores_hpp
#define Servidores_hpp

#include "CanalTexto.hpp"
#include "Usuario.hpp"
#include <vector>
#include <iostream>


class Servidores{

    private :
        unsigned int m_id;  //Identificador único para o este servidor
        Usuario* m_dono;    //Referência para o usuário que criou o servidor
        std::string m_nome;      //Nome do servidor, passado no comando create-server 
        std::vector<CanalTexto*> m_canaisTexto; //Um vetor contendo todos os canais de texto deste servidor
        std::vector<Usuario*> m_participantes; //Um vetor contendo referências para todos os participantes deste servidor.

    public :
        
        Servidores(int id, Usuario* dono, std::string nome);

        /**
         * @brief Get the nome object.
         * 
         * @return std::string m_nome.
         */
        std::string get_nome();

        /**
         * @brief Get the id object
         * 
         * @return std::string 
         */
        int get_id();

        /**
         * @brief Get the dono object
         * 
         * @return Usuario* 
         */
        Usuario* get_dono();

        /**
         * @brief lista todos os m_canaisTexto no servidor
         * 
         */
        void list_channels();

};

#endif //Servidores_hpp
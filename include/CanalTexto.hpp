/**
 * @file CanalTexto.hpp
 * @author Deriki Pereira (derikipereira@outlook.com)
 * @brief Header class CanalTexto
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CanalTexto_hpp
#define CanalTexto_hpp

#include <vector>
#include <iostream>
#include "Usuario.hpp"
#include "Mensagem.hpp"


class CanalTexto{

    private :
        
        unsigned int m_id;
        std::string m_nome;
        Usuario* m_dono;
        std::vector<Mensagem*> m_mensagens; 

    public :

        /**
         * @brief Construct a new Canal Texto object
         * 
         * @param id identificador unico para o programa
         * @param nome nome do canal
         * @param dono usuario criador do canal
         */
        CanalTexto(int id, std::string nome, Usuario* dono);

        /**
         * @brief Destroy the Canal Texto object
         * 
         */
        ~CanalTexto();
        
        /**
         * @brief Get the nome object
         * 
         * @return std::string 
         */
        std::string get_nome();

        /**
         * @brief Get the dono object
         * 
         * @return Usuario* 
         */
        Usuario* get_dono();

        /**
         * @brief Get the id object
         * 
         * @return int 
         */
        int get_id();
};

#endif //CanalTexto_hpp
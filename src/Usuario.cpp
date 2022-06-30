/**
 * @file Usuario.cpp
 * @author Deriki Pereira (derikipereira@outlook.com)
 * @brief file Metodos Usuario.hpp
 * @version 0.1
 * @date 2022-06-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Usuario.hpp"

using namespace std;

    Usuario::Usuario(unsigned int id,string nome,string email,string senha){
        this->m_id = id;
        this->m_nome = nome;
        this->m_email = email;
        this->m_senha = senha;
    }

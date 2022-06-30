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

    bool Usuario::usuario_valido(){
        bool flagNome = true;
        bool flagEmail = true;
        bool flagSenha = true;

        // implementação para Nome valido
        if(this->m_nome == ""){
            flagNome = false;
        }

        // implementação para email valido

        if(this->m_email ==""){
            flagEmail = false;
        }

        //implementação para senha valida

        if(this->m_senha.find(' ')!=string::npos){
            flagSenha = false;
        }

        // Return
        if(flagEmail && flagNome && flagSenha) return true;
        else return false;
    }

    string Usuario::get_nome(){
        return this->m_nome;
    }

    string Usuario::get_email(){
        return this->m_email;
    }

    string Usuario::get_senha(){
        return this->m_senha;
    }

    unsigned int Usuario::get_id(){
        return this->m_id;
    }
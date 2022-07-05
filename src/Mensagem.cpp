/**
 * @file Mensagem.cpp
 * @author Deriki Pereira (derikipereira@outlook.com)
 * @brief Source class Mensagem
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Mensagem.hpp"

using namespace std;

    Mensagem::Mensagem(int id, string dataHora, Usuario* enviadaPor, string conteudo){
        this->m_id = id;
        this->m_dataHora = dataHora;
        this->m_enviadaPor = enviadaPor;
        this->m_conteudo = conteudo;
    }

        int Mensagem::get_id(){
            return this->m_id;
        }

        string Mensagem::get_dataHora(){
            return this->m_dataHora;
        }

        Usuario* Mensagem::get_enviadaPor(){
            return this->m_enviadaPor;
        }

        string Mensagem::get_conteudo(){
            return this->m_conteudo;
        }    
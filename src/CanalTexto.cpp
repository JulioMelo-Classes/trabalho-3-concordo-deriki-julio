/**
 * @file CanalTexto.cpp
 * @author Deriki Pereira (derikipereira@outlook.com)
 * @brief Source class CanalTexto
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "CanalTexto.hpp"

using namespace std;


    CanalTexto::CanalTexto(int id, string nome, Usuario* dono){

        this->m_id = id;
        this->m_dono = dono;
        this->m_nome = nome;

    }
    
    CanalTexto::~CanalTexto(){
        for(auto msg : this->m_mensagens) delete msg;
    }

    int CanalTexto::get_id(){
        return this->m_id;
    }

    string CanalTexto::get_nome(){
        return this->m_nome;
    }

    Usuario* CanalTexto::get_dono(){
        return this->m_dono;
    }
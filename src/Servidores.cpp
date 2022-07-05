/**
 * @file Servidores.cpp
 * @author Deriki Pereira (derikipereira@outlook.com)
 * @brief file Metodos class Servidores.hpp
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Servidores.hpp"

using namespace std;

    Servidores::Servidores(int id, Usuario* dono, std::string nome){
        this->m_id = id;
        this->m_nome = nome;
        this->m_dono = dono;
    }

    string Servidores::get_nome(){
        return this->m_nome;
    }

    int Servidores::get_id(){
        return this->m_id;
    }
    Usuario* Servidores::get_dono(){
        return this->m_dono;
    }

    void Servidores::list_channels(){
        if(this->m_canaisTexto.size()==0){
            cout<<"servidor sem canal de texto"<<endl;
        }
        else{
            for(auto channel : this->m_canaisTexto){
                cout<<channel->get_nome()<<endl;
            }
        }
    }
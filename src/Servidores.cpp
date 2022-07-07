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
        this->m_participantes.push_back(dono);
    }

    Servidores::~Servidores(){
        for(auto ct : this->m_canaisTexto) delete ct;
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

    void Servidores::list_participants(){
        for(auto participante : this->m_participantes)
            cout<<participante->get_nome()<<endl;
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

    void Servidores::create_channel(string nome, Usuario* dono){
        
        if((int)idCanalTextoLivres.size()==0){
            
            CanalTexto* ct = new CanalTexto(nextIdCanalTexto,nome,dono);
            this->m_canaisTexto.push_back(ct);
            nextIdCanalTexto++;
        }
        else{
            CanalTexto* ct = new CanalTexto(idCanalTextoLivres[0],nome,dono);
            this->m_canaisTexto.push_back(ct);
            idCanalTextoLivres.erase(idCanalTextoLivres.begin());
        }

        
        
    }

    bool Servidores::insert_participante(Usuario* participante){
        if(find_participante(participante)==NULL){
            this->m_participantes.push_back(participante);

            return true;
        }
        return false;
    
    }
    bool Servidores::remove_participante(Usuario* participante){
        if(participante == this->m_dono){
            return false;
        }
        for(int i=0 ; i<this->m_participantes.size(); i++){
            if(this->m_participantes[i]==participante){
                this->m_participantes.erase(this->m_participantes.begin()+i);
                return true;
            }
        }
        return false;
    }

    Usuario* Servidores::find_participante(Usuario* participante){
        for(auto part : this->m_participantes) if(part == participante) return part;

        return NULL;
    }
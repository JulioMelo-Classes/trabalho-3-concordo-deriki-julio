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
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std;


    CanalTexto::CanalTexto(int id, string nome, Usuario* dono){

        this->m_id = id;
        this->m_dono = dono;
        this->m_nome = nome;

    }
    
    CanalTexto::~CanalTexto(){
        for(auto msg : this->m_mensagens) delete msg;
        this->m_mensagens.clear();
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

    void CanalTexto::create_message(Usuario* user,string mensagem){
        
        using std::chrono::system_clock;
        system_clock::time_point today = system_clock::now();
        
        std::time_t t = std::chrono::system_clock::to_time_t(today);
        std::string ts = std::ctime(&t);
        if(this->idMensagemLivres.size() == 0){
            Mensagem* msg = new Mensagem(nextIdMensagem,ts,user,mensagem);
            this->m_mensagens.push_back(msg);
            this->nextIdMensagem++;
        }
        else{
            Mensagem* msg = new Mensagem(this->idMensagemLivres[0],ts,user,mensagem);
            this->m_mensagens.push_back(msg);
            this->idMensagemLivres.erase(this->idMensagemLivres.begin());
        }

    }

    void CanalTexto::list_messages(){
        for(auto msg : this->m_mensagens){
            cout<<msg->get_enviadaPor()<<"<"<<msg->get_dataHora()<<">: "<<msg->get_conteudo()<<endl;
        }
    }
#include "Sistema.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;
/* COMANDOS */
string Sistema::quit() {

	for(auto server : this->m_servidores) delete server;
	this->m_servidores.clear();

	for(auto user : this->m_usuarios) delete user;
	this->m_usuarios.clear();

  return "Saindo...";
}

string Sistema::create_user (const string email, const string senha, const string nome) {
	unsigned int id;
		if(email_eh_unico(email)){
			if(this->idUserLivres.size()==0){
				id = this->nextIdUser;
				Usuario * p = new Usuario(id,nome,email,senha);
				this->m_usuarios.push_back(p);
				this->nextIdUser++;
			}
			else{
				id = this->idUserLivres[0];
				Usuario * p = new Usuario(id,nome,email,senha);
				this->m_usuarios.push_back(p);
				this->idUserLivres.erase(idUserLivres.begin());
			}
			return "Usuário criado.";
		}
		else return "Usuário já existe!";
	
}

std::string Sistema::delete_user (const std::string email, const std::string senha){

	
	return "e.";
}

string Sistema::login(const string email, const string senha) {
	for(int i=0; i<this->m_usuarios.size();i++){
		if(this->m_usuarios[i]->get_email()==email){
			if(this->m_usuarios[i]->get_senha()==senha){
				this->m_usuariosLogados[m_usuarios[i]->get_id()] = {0,0};
				return "Logado como " + this->m_usuarios[i]->get_email();
			}
			else break;
		}
	}

	return "Senha ou usuário inválidos!";
}

string Sistema::disconnect(int id) {
	if(user_is_logged(id)){
		this->m_usuariosLogados.erase(id);
		for(auto user : this->m_usuarios){
			if(user->get_id()==id){
				return "Usuário " + user->get_email() + " desconectado!";
			}
		}
	}
	return "identificador não encontrado.";
}

string Sistema::create_server(int id, const string nome) {
	unsigned int idServer;
	if(server_nome_unico(nome)){
		if(user_is_logged(id)){
			if(this->idServerLivres.size()==0){
				for(auto user : this->m_usuarios){
					if(user->get_id()==id){
						idServer = this->nextIdServer;
						Servidores* s = new Servidores(idServer,user,nome);
						this->m_servidores.push_back(s);
						this->nextIdServer++;
						return "servidor " + nome + " criado";
					}
				}
			}
			else{
				idServer = this->idServerLivres[0];
				this->idServerLivres.erase(this->idServerLivres.begin());
				for(auto user : this->m_usuarios){
					if(user->get_id()==id){
						idServer = this->nextIdServer;
						Servidores* s = new Servidores(idServer,user,nome);
						this->m_servidores.push_back(s);
						return "servidor " + nome + " criado";
					}
				}
			}
		}
	}
	return "Servidor com esse nome já existe.";
}
string Sistema::list_servers(int id) {
	if(user_is_logged(id)){

		for(auto server : this->m_servidores){
			cout<<server->get_nome()<<endl;
		}

		return "";
	}

	return "identificador invalido";
}

string Sistema::remove_server(int id, const string nome) {
	return "remove_server NÃO IMPLEMENTADO";
}

string Sistema::enter_server(int id, const string nome) {
	if(user_is_logged(id)){
		for(auto server : this->m_servidores){
			if(server->get_nome()==nome){
				this->m_usuariosLogados[id] = {server->get_id(),0};
				return "enter_server sucess.";
			}
		}
	}
	return "Error enter_server.";
}

string Sistema::leave_server(int id, const string nome) {
	if(user_is_logged(id)){
		for(auto server : this->m_servidores){
			if(server->get_nome()==nome){
				this->m_usuariosLogados[id] = {0,0};
				return "leave_server sucess.";
			}
		}
	}
	return "Error leave_server.";
}

string Sistema::list_participants(int id) {
	if(user_is_logged(id)){
		int idServer = this->m_usuariosLogados[id].first;
		for (auto server : this->m_servidores){
			if(server->get_id()==idServer){
				for(auto userLogado : this->m_usuariosLogados){
					if(userLogado.second.first == idServer){
						cout<<user_name(userLogado.first)<<endl;
					}
				}
				return "";
			}
		}
	}
	return "Error list_participants";
}

string Sistema::list_channels(int id) {
	if(user_is_logged(id)){
		int serverID = this->m_usuariosLogados[id].first;
		if(serverID!=0){
			for(auto server : this->m_servidores){
				if(server->get_id()==serverID){
					server->list_channels();
					return "";
				}
			}
		}
		else return "Error list_channels: usuario não entrou em nenhum servidor.";
	}
	return "Error list_channels: usuario não logado.";
}

string Sistema::create_channel(int id, const string nome) {
	return "create_channel NÃO IMPLEMENTADO";
}

string Sistema::remove_channel(int id, const string nome) {
	return "remove_channel NÃO IMPLEMENTADO";
}

string Sistema::enter_channel(int id, const string nome) {
	return "enter_channel NÃO IMPLEMENTADO";
}

string Sistema::leave_channel(int id) {
	return "leave_channel NÃO IMPLEMENTADO";
}

string Sistema::send_message(int id, const string mensagem) {
	return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages(int id) {
	return "list_messages NÃO IMPLEMENTADO";
}

bool Sistema::email_eh_unico(string email){
	
	for(auto usuario : this->m_usuarios) if(usuario->get_email() == email) return false;
	return true;
			
}

bool Sistema::server_nome_unico(string nome){
	for(auto server : this->m_servidores){
		if(server->get_nome()==nome) return false;
	}
	return true;
}

bool Sistema::user_is_logged(int id){
	auto it = this->m_usuariosLogados.find(id);
	
	if (it != this->m_usuariosLogados.end()){
		return true;
	}
	return false;
}

string Sistema::user_name(int id){
	for(auto user : this->m_usuarios){
		if(user->get_id()==id){
			return user->get_nome();
		}
	}
	return "Error user_name : usuario não encontrado.";
}
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
		else return "Error create_user: Usuário já existe!";
	
}

std::string Sistema::delete_user (const std::string email, const std::string senha){
    unsigned int id;
	bool correto;
	correto = false;
    for(auto u : m_usuarios){
        if(u->get_email() == email && u->get_senha() == senha){
            id = u->get_id();
			correto = true;
			if(user_is_logged(id) == false){
				free(m_usuarios[id]);
				idUserLivres.push_back(id);
				return "Usuário <" + email + "> removido do sistema!";
			}
        }
    }
     if (correto = false){
		return "Usuário não cadastrado!";
	 }
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

	return "Error login: Senha ou usuário inválidos!";
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
	return "Error disconnect: Usuário não logado.";
}

string Sistema::create_server(int id, const string nome) {
	unsigned int idServer;
	if( server_nome_unico(nome) && user_is_logged(id)){
		if(this->idServerLivres.size()==0){
			Usuario* dono = find_user_by_id(id);
			idServer = this->nextIdServer;
			Servidores* s = new Servidores(idServer,dono,nome);
			this->m_servidores.push_back(s);
			this->nextIdServer++;
			return "servidor " + nome + " criado";
		}
		else{
			idServer = this->idServerLivres[0];
			this->idServerLivres.erase(this->idServerLivres.begin());
			Usuario* dono = find_user_by_id(id);
			Servidores* s = new Servidores(idServer,dono,nome);
			this->m_servidores.push_back(s);
			return "servidor " + nome + " criado";
		}
	}
	return "Error creat_server: nome existente ou Usuário não logado.";
}
string Sistema::list_servers(int id) {
	if(user_is_logged(id)){

		for(auto server : this->m_servidores){
			cout<<server->get_nome()<<endl;
		}

		return "";
	}

	return "Error list_servers: Usuário não logado.";
}

string Sistema::remove_server(int id, const string nome) {
	if(user_is_logged(id)){

	}
	return "Error remove_server: Usuário não logado.";
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
	return "Error enter_server: Usuário não logado.";
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
	return "Error leave_server: Usuário não logado.";
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
	return "Error list_participants: Usuário não logado.";
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
	return "Error list_channels: Usuário não logado.";
}

string Sistema::create_channel(int id, const string nome) {
	if(user_is_logged(id)){
		int idServer = this->m_usuariosLogados[id].first;
		for(auto server : this->m_servidores){
			if(server->get_id()==idServer){
				Usuario* dono = find_user_by_id(id);
				server->create_channel(nome,dono);
				return "sucess create_channel : canal criado.";
			}
		}
	}
	return "Error create_channel: Usuário não logado.";
}

string Sistema::remove_channel(int id, const string nome) {
	if(user_is_logged(id)){
		
		Servidores* server = find_server_by_id(this->m_usuariosLogados[id].first);
		
	}
	return "Error remove_channel: Usuário não logado.";
}

string Sistema::enter_channel(int id, const string nome) {
	if(user_is_logged(id)){

	}
	return "Error enter_channel: Usuário não logado.";
}

string Sistema::leave_channel(int id) {
	if(user_is_logged(id)){

	}
	return "Error leave_channel: Usuário não logado.";
}

string Sistema::send_message(int id, const string mensagem) {
	if(user_is_logged(id)){

	}
	return "Error send_message: Usuário não logado.";
}

string Sistema::list_messages(int id) {
	if(user_is_logged(id)){

	}
	return "Error list_messages: Usuário não logado.";
}
/* END COMANDOS */

/* VALIDAÇÃO */
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
/* END VALIDAÇÃO */

/* LOCALIZAÇÃO */
string Sistema::user_name(int id){
	for(auto user : this->m_usuarios){
		if(user->get_id()==id){
			return user->get_nome();
		}
	}
	return "Error user_name: usuario não encontrado.";
}

Usuario* Sistema::find_user_by_id(int id){
	
	for(auto user : this->m_usuarios) if(user->get_id()==id) return user;

	return NULL;
}

Servidores* Sistema::find_server_by_id(int id){

	for(auto server : this->m_servidores) if(server->get_id()==id) return server;

	return NULL;
}
/* END LOCALIZAÇÃO*/

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
  int i;
  i = 0;
    unsigned int id;
	bool correto;
	correto = false;
    for(auto u : m_usuarios){
        if(u->get_email() == email && u->get_senha() == senha){
            id = u->get_id();
			if(user_is_logged(id) == false){
				delete(u);
        			m_usuarios.erase(m_usuarios.begin()+i);
				idUserLivres.push_back(id);
        			correto = true;
				return "Usuário <" + email + "> removido do sistema!";
			}
          else if(user_is_logged(id) == true){
            return "Erro usuário <" + email + "> logado, deslogue para deletar o usuário";
          }
        }
      i++;
    }
     if (correto == false){
		return "Usuário não cadastrado!";
	 }
}

string Sistema::login(const string email, const string senha) {
	Usuario* user = find_user(email);
	if(user!=NULL){
		if(!user_is_logged(user->get_id())){
			if(user->get_senha()==senha){
				this->m_usuariosLogados[user->get_id()] = {0,0};
			}
			else return "Error login: senha inválida.";
		}
		else return "Error login: Usuário já está logado.";
	}
	else return "Error login: Usuário não criado.";

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
			Usuario* dono = find_user(id);
			idServer = this->nextIdServer;
			Servidores* s = new Servidores(idServer,dono,nome);
			this->m_servidores.push_back(s);
			this->nextIdServer++;
			return "servidor " + nome + " criado";
		}
		else{
			idServer = this->idServerLivres[0];
			this->idServerLivres.erase(this->idServerLivres.begin());
			Usuario* dono = find_user(id);
			Servidores* s = new Servidores(idServer,dono,nome);
			this->m_servidores.push_back(s);
			return "servidor " + nome + " criado";
		}
	}
	return "Error create_server: nome existente ou Usuário não logado.";
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
		Usuario* dono = find_user(id);
		Servidores* serverRemove = find_server(nome);
		if(serverRemove->get_dono()==dono){
			server_kick(serverRemove->get_id());
			for(int i = 0; i < this->m_servidores.size();i++ ){
				if(this->m_servidores[i]==serverRemove){
					this->m_servidores.erase(this->m_servidores.begin()+i);
					delete serverRemove;
					return "Sucess remove_server: Server removido.";
				}
			}
		}
		return "Error remove_server: Usuário não autorizado.";

	}
	return "Error remove_server: Usuário não logado.";
}

string Sistema::enter_server(int id, const string nome) {
	if(user_is_logged(id)){
		Usuario* user = find_user(id);
		Servidores* server = find_server(nome);
		this->m_usuariosLogados[id] = {server->get_id(),0};
		if(server->insert_participante(user)){
			return "Entrou no servidor com sucesso, add participantes sucess";
		}
		else return "Entrou no servidor com sucesso.";
	}
	return "Error enter_server: Usuário não logado.";
}

string Sistema::leave_server(int id, const string nome) {
	if(user_is_logged(id)){
		Usuario* user = find_user(id);
		Servidores* server = find_server(nome);

		if(server->remove_participante(user)) return "Saindo do servidor '"+server->get_nome()+"'";
		else return "Você não está nesse servidor.";

	}
	return "Error leave_server: Usuário não logado.";
}

string Sistema::list_participants(int id) {
	if(user_is_logged(id)){
		
		if(this->m_usuariosLogados[id].first !=0){
			Servidores* server = find_server(this->m_usuariosLogados[id].first);
			server->list_participants();
			return "";
		}
		else return "Error list_participants: Usuário não entrou no server.";
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
				Usuario* dono = find_user(id);
				server->create_channel(nome,dono);
				return "sucess create_channel : canal criado.";
			}
		}
	}
	return "Error create_channel: Usuário não logado.";
}

string Sistema::remove_channel(int id, const string nome) {
	if(user_is_logged(id)){
		
		Servidores* server = find_server(this->m_usuariosLogados[id].first);
		
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
Usuario* Sistema::find_user(int id){
	
	for(auto user : this->m_usuarios) if(user->get_id()==id) return user;

	return NULL;
}

Usuario* Sistema::find_user(string email){
	
	for(auto user : this->m_usuarios) if(user->get_email()==email) return user;

	return NULL;
}

Servidores* Sistema::find_server(int id){

	for(auto server : this->m_servidores) if(server->get_id()==id) return server;

	return NULL;
}

Servidores* Sistema::find_server(string nome){
	for(auto server : this->m_servidores) if(server->get_nome()==nome) return server;

	return NULL;
}
/* END LOCALIZAÇÃO*/

/* MANIPULAÇÃO */
void Sistema::server_kick(int id){
	for(auto usuarioLogado : this->m_usuariosLogados){
		if(usuarioLogado.second.first == id){
			usuarioLogado.second.first = 0;
			usuarioLogado.second.second = 0;
		}
	}
}
/* END MANIPULAÇÃO */
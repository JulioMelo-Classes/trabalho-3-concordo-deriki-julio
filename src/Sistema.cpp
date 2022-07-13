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

	for(auto userDeletado : this->usuariosDeletados) delete userDeletado;

	this->usuariosDeletados.clear();

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
			return "Usuário "+ nome +" criado.";
		}
		else return "Error create_user: Usuário já existe!";
	
}

std::string Sistema::delete_user (const std::string email, const std::string senha){
	Usuario* user = find_user(email);
	if(user!=nullptr){
		if(user->get_senha()==senha){
			if(!user_is_logged(user->get_id())){
				for(int i=0;i<(int)this->m_usuarios.size();i++){
					if(this->m_usuarios[i]==user){
						this->usuariosDeletados.push_back(user);
						this->m_usuarios.erase(this->m_usuarios.begin()+i);
						user->deletado();
						return "Usuário " + email + " removido";
					}
				}
			}
			else return "Error delete_user: Usuario está logado.";
		}
		else return "Error delete_user: Senha incorreta.";
	}
	else return "Error delete_user: Usuário não encontrado.";
}

string Sistema::login(const string email, const string senha) {
	Usuario* user = find_user(email);
	if(user!=nullptr){
		if(!user_is_logged(user->get_id())){
			if(user->get_senha()==senha){
				this->m_usuariosLogados[user->get_id()] = {0,0};
        return "Logado como " + user->get_email();
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
		Usuario* user = find_user(id);
		return "Usuário " + user->get_email() + " desconectado!";
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
      this->m_servidoresLogados.push_back(make_pair(id, nome));
			this->m_servidores.push_back(s);
			this->nextIdServer++;
			return "servidor " + nome + " criado";
		}
		else{
			idServer = this->idServerLivres[0];
			this->idServerLivres.erase(this->idServerLivres.begin());
			Usuario* dono = find_user(id);
			Servidores* s = new Servidores(idServer,dono,nome);
      this->m_servidoresLogados.push_back(make_pair(id, nome));
			this->m_servidores.push_back(s);
			return "servidor " + nome + " criado";
		}
	}
	return "Error create_server: nome existente ou Usuário não logado.";
}

string Sistema::list_servers(int id) {
	if(user_is_logged(id)){

		for(int i = 0; i < m_servidoresLogados.size(); i++){
			if(m_servidoresLogados.at(i).first == id){
				cout << m_servidoresLogados.at(i).second << endl;
			}
		}

		return "";
	}

	return "Error list_servers: Usuário não logado.";
}

string Sistema::remove_server(int id, const string nome) {
	if(user_is_logged(id)){
		Usuario* dono = find_user(id);
		Servidores* serverRemove = find_server(nome);
    if(serverRemove == nullptr){
      return "Servidor " + nome + " não encontrado";
    }
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
    if(server == nullptr){
      return "O servidor " + nome + " não existe";
    }
		this->m_usuariosLogados[id] = {server->get_id(),0};

    bool existe;
    existe = false;
    if(m_servidoresLogados.size() > 0){
      for(int i = 0; i < m_servidoresLogados.size(); i++){
        if(m_servidoresLogados.at(i).first == id && m_servidoresLogados.at(i).second == nome){
          existe = true;
        }
      }
      if(existe == false){
        m_servidoresLogados.push_back(make_pair(id, nome));
      }
    }else{
      m_servidoresLogados.push_back(make_pair(id, nome));
    }
    
		if(server->insert_participante(user)){
			return "Entrou no servidor com sucesso, add participantes sucess";
		}
		else return "Entrou no servidor com sucesso.";
	}
	return "Error enter_server: Usuário não logado.";
}

string Sistema::leave_server(int id, const string nome) {
	bool existe;
	existe = false;
    if(user_is_logged(id)){
        Usuario* user = find_user(id);
        Servidores* server = find_server(nome);
      if(server == nullptr){
        return "O servidor " + nome + " não existe";
      }

    if(server->remove_participante(user)){
      for(int i = 0; i < m_servidoresLogados.size(); i++){
        if(m_servidoresLogados.at(i).first == id && m_servidoresLogados.at(i).second == nome){
          m_servidoresLogados.erase(m_servidoresLogados.begin()+i);
        }
      }
      return "Saindo do servidor '"+server->get_nome()+"'";
    }
      else{
        for(int i = 0; i < m_servidoresLogados.size(); i++){
      		if(m_servidoresLogados.at(i).first == id){
      			existe = true;
      		}
	      }
        if(existe == false){
          return "Você não está em qualquer servidor";
        } else {
          return "Você não está nesse servidor.";
        }
      }
      }
  else {
    return "Error leave_server: Usuário não logado.";
    }
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
			Servidores* server = find_server(serverID);
			server->list_channels();
			return "";
		}
		else return "Error list_channels: usuario não entrou em nenhum servidor.";
	}
	return "Error list_channels: Usuário não logado.";
}

string Sistema::create_channel(int id, const string nome) {
	if(user_is_logged(id)){
		int idServer = this->m_usuariosLogados[id].first;
		Servidores * server = find_server(idServer);
		if(server!=nullptr){
				Usuario* dono = find_user(id);
				return server->create_channel(nome,dono);
		}else return "Error create_channel: Usuário não está em um servidor.";
	}
	return "Error create_channel: Usuário não logado.";
}

string Sistema::remove_channel(int id, const string nome) {
	if(user_is_logged(id)){
		
		Servidores* server = find_server(this->m_usuariosLogados[id].first);
		if(server!=nullptr){
			Usuario* user = find_user(id);
			CanalTexto* ct = server->find_channel(nome);
			if(ct!=nullptr){
				if(server->perm_remove_channel(user,ct)){
				channel_kick(server->get_id(),ct->get_id());
				return server->remove_channel(ct);
				}
				else return "Você não é dono do canal ou do servidor.";
			}
			else return "Canal de texto '"+ nome + "'não existe!";
		}
		else return "Error remove_channel: server não encontrado.";		
	}
	else return "Error remove_channel: Usuário não logado.";
}

string Sistema::enter_channel(int id, const string nome) {
	if(user_is_logged(id)){
		Usuario* user = find_user(id);
		Servidores* serverVisualizado = find_server(this->m_usuariosLogados[id].first);
		if(serverVisualizado != nullptr ){
			CanalTexto* ct=serverVisualizado->find_channel(nome);
			if(ct!=nullptr){
				this->m_usuariosLogados[id].second = ct->get_id();
				return "Entrou no canal '" + nome +"'. id: " + to_string(ct->get_id());
			}
			else return "Canal '" +nome + "' não existe.";
		}
		else return "Error enter_channel: Usuario não entrou em nenhum server.";
	}
	else return "Error enter_channel: Usuário não logado.";
}

string Sistema::leave_channel(int id) {
	if(user_is_logged(id)){
		if(this->m_usuariosLogados[id].second!=0){
			m_usuariosLogados[id].second = 0;
		}
		else return "Error leave_channel: Usuário não está visualizando nenhum canal.";
	}
	else return "Error leave_channel: Usuário não logado.";
}

string Sistema::send_message(int id, const string mensagem) {
	if(user_is_logged(id)){
			Servidores* server = find_server(this->m_usuariosLogados[id].first);
			Usuario* user = find_user(id);
			CanalTexto* ct = server->find_channel(this->m_usuariosLogados[id].second);
			if(ct!=nullptr){
				ct->create_message(user,mensagem);
				return "Success: mensagem gravada.";
			}
			else return "Error send_menssage: Canal de texto não encontrado.";
	}
	else return "Error send_message: Usuário não logado.";
}

string Sistema::list_messages(int id) {
	if(user_is_logged(id)){
			Servidores* server = find_server(this->m_usuariosLogados[id].first);
			CanalTexto* ct = server->find_channel(this->m_usuariosLogados[id].second);
			if(ct!=nullptr)
				ct->list_messages();
			else return "Error list_messages: canal nao encontrado.";
	}
	else return "Error list_messages: Usuário não logado.";
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

	return nullptr;
}

Usuario* Sistema::find_user(string email){
	
	for(auto user : this->m_usuarios) if(user->get_email()==email) return user;

	return nullptr;
}

Servidores* Sistema::find_server(int id){

	for(auto server : this->m_servidores) if(server->get_id()==id) return server;

	return nullptr;
}

Servidores* Sistema::find_server(string nome){
	for(auto server : this->m_servidores) if(server->get_nome()==nome) return server;

	return nullptr;
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

void Sistema::channel_kick(unsigned int idServer, unsigned int idChannel){
	for(auto usuarioLogado : this->m_usuariosLogados){
		if(usuarioLogado.second.first == idServer && usuarioLogado.second.second == idChannel){
			usuarioLogado.second.second = 0;
		}
	}
}
/* END MANIPULAÇÃO */

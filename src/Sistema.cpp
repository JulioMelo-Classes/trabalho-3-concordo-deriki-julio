#include "Sistema.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;
/* COMANDOS */
string Sistema::quit() {
  return "Saindo...";
}

string Sistema::create_user (const string email, const string senha, const string nome) {
	
	Usuario * p = new Usuario(this->m_usuarios.size(),nome,email,senha);
	if(p->usuario_valido()){
		if(email_eh_unico(email)){
			this->m_usuarios.push_back(p);
			return "Usuário criado.";
		}
	}
	return "Erro ao Criar Usuário.";
}

std::string Sistema::delete_user (const std::string email, const std::string senha){
	for(int i=0; i<this->m_usuarios.size();i++){
		if(this->m_usuarios[i]->get_email()==email){
			if(this->m_usuarios[i]->get_senha()==senha){
			
				this->m_usuarios.erase(this->m_usuarios.begin()+i);	
				return "Usuário deletado.";
			}
		}
	}
	
	return "email ou senha invalidos.";
}

string Sistema::login(const string email, const string senha) {
	for(int i=0; i<this->m_usuarios.size();i++){
		if(this->m_usuarios[i]->get_email()==email){
			if(this->m_usuarios[i]->get_senha()==senha){
				this->m_usuariosLogados[m_usuarios[i]->get_id()] = {0,0};
				break;
			}
		}
	}

	return "login NÃO IMPLEMENTADO";
}

string Sistema::disconnect(int id) {
	return "disconnect NÃO IMPLEMENTADO";
}

string Sistema::create_server(int id, const string nome) {
	return "create_server NÃO IMPLEMENTADO";
}
string Sistema::list_servers(int id) {
	return "list_servers NÃO IMPLEMENTADO";
}

string Sistema::remove_server(int id, const string nome) {
	return "remove_server NÃO IMPLEMENTADO";
}

string Sistema::enter_server(int id, const string nome) {
	return "enter_server NÃO IMPLEMENTADO";
}

string Sistema::leave_server(int id, const string nome) {
	return "leave_server NÃO IMPLEMENTADO";
}

string Sistema::list_participants(int id) {
	return "list_participants NÃO IMPLEMENTADO";
}

string Sistema::list_channels(int id) {
	return "list_channels NÃO IMPLEMENTADO";
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
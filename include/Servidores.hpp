/**
 * @file Servidores.hpp
 * @author Deriki Pereira (derikipereira@outlook.com)
 * @brief Header class Servidores
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef Servidores_hpp
#define Servidores_hpp

#include "CanalTexto.hpp"
#include "Usuario.hpp"
#include <vector>
#include <iostream>


class Servidores{

    private :
        unsigned int m_id;  //Identificador único para o este servidor
        Usuario* m_dono;    //Referência para o usuário que criou o servidor
        std::string m_nome;      //Nome do servidor, passado no comando create-server 
        std::vector<CanalTexto*> m_canaisTexto; //Um vetor contendo todos os canais de texto deste servidor
        std::vector<Usuario*> m_participantes; //Um vetor contendo referências para todos os participantes deste servidor.
        unsigned int nextIdCanalTexto = 1 ;
        std::vector<unsigned int> idCanalTextoLivres;

    public :
        
        /**
         * @brief Construct a new Servidores object
         * 
         * @param id 
         * @param dono 
         * @param nome 
         */
        Servidores(int id, Usuario* dono, std::string nome);
        
        /**
         * @brief Destroy the Servidores object
         * 
         */
        ~Servidores();

        /**
         * @brief Get the nome object.
         * 
         * @return std::string m_nome.
         */
        std::string get_nome();

        /**
         * @brief Get the id object
         * 
         * @return std::string 
         */
        int get_id();

        /**
         * @brief Get the dono object
         * 
         * @return Usuario* 
         */
        Usuario* get_dono();

        /**
         * @brief lista os participantes desse servidor com cout.
         */
        void list_participants();

        /**
         * @brief lista todos os m_canaisTexto no servidor
         * 
         */
        void list_channels();

        /**
         * @brief Create a channel object.
         * 
         * @param nome nome do canal.
         * @param dono usuario dono.
         * @return std::string resultado da criação.
         */
        std::string create_channel(std::string nome, Usuario* dono);

        /**
         * @brief insere referencia de um objeto Usuario em m_participantes.
         * 
         * @param participante Referencia ao objeto iserido.
         * @return true se for inserido.
         * @return false Error se nao for inserido.
         */
        bool insert_participante(Usuario* participante);

        /**
         * @brief remove participante do vector m_participantes.
         * 
         * @param participante participante para ser removido.
         * @return true se for removido.
         * @return false se nao foi encontrado ou não pode ser removido.
         */
        bool remove_participante(Usuario* participante);

        /**
         * @brief encontra objeto Usuario no vector m_participantes.
         * 
         * @param participante objeto procurado no vector.
         * @return Usuario* se achar, se nao nullptr.
         */
        Usuario* find_participante(Usuario* participante);

        /**
         * @brief encontra referencia ao objeto CanalTexto no vector m_canaisTexto.
         * 
         * @param nome string no nome do objeto.
         * @return CanalTexto* objeto nullptr se não achar.
         */
        CanalTexto* find_channel(std::string nome);

        /**
         * @brief sobrecarga da função para localizar canal pelo seu id.
         * 
         * @param id identificador do canal.
         * @return CanalTexto* se não encontrado retorna nullptr.
         */
        CanalTexto* find_channel(unsigned int id);

        /**
         * @brief remove o canal de texto passado como parametro.
         * 
         * @param ct canal de texto para ser removido.
         * @return std::string do resultado.
         */
        std::string remove_channel(CanalTexto* ct);

        /**
         * @brief verifica se o usuario  pode remover o canal de texto
         * 
         * @param user usuario para analisar
         * @param channel canal para analisar se o usuario tem permisao de remover.
         * @return true se o usuario tiver perm.
         * @return false se não.
         */
        bool perm_remove_channel(Usuario* user,CanalTexto* channel);


};

#endif //Servidores_hpp
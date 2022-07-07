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
         * @brief Create a channel object
         * 
         */
        void create_channel(std::string nome, Usuario* dono);

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
         * @return Usuario* se achar, se nao NULL.
         */
        Usuario* find_participante(Usuario* participante);


};

#endif //Servidores_hpp
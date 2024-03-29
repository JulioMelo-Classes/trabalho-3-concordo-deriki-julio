/**
 * @file Usuario.hpp
 * @author Deriki Pereira (derikipereira@outlook.com)
 * @brief Header class Usuario
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef Usuario_hpp
#define Usuario_hpp

#include <iostream>
#include <vector>

class Usuario{

    private :
        unsigned int m_id;
        std::string m_nome;
        std::string m_email;
        std::string m_senha;
        
    public :
        /**
         * @brief Construct a new Usuario object
         * 
         * @param nome nome do novo usuario
         * @param email email do novo usuario
         * @param senha senha do novo usuario
         */
        Usuario(unsigned int id, std::string nome, std::string email, std::string senha);

        /**
         * @brief validador para objeto Usuario
         * 
         * @todo aprimorar validação.
         * 
         * @return true se for um objeto valido para o programa.
         * @return false se não for.
         */
        bool usuario_valido();

        /**
         * @brief Get the nome object
         * 
         * @return std::string 
         */
        std::string get_nome();
        /**
         * @brief Get the email object
         * 
         * @return std::string 
         */
        std::string get_email();
        /**
         * @brief Get the senha object
         * 
         * @return std::string 
         */
        std::string get_senha();

        /**
         * @brief Get the id object
         * 
         * @return unsigned int 
         */
        unsigned int get_id();

        /**
         * @brief atualizando as informações do usuario para deletado.
         * 
         */
        void deletado();

};

#endif //Usuario_hpp
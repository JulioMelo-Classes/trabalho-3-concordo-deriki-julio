#ifndef Usuario_hpp
#define Usuario_hpp

#include <iostream>
#include <vector>

using namespace std;

class Usuario{

    private :
        unsigned int m_id;
        string m_nome;
        string m_email;
        string m_senha;
        
    public :

        /**
         * @brief Construct a new Usuario object
         * 
         * @param nome nome do novo usuario
         * @param email email do novo usuario
         * @param senha senha do novo usuario
         */
        Usuario(unsigned int id,string nome, string email, string senha);

};

#endif //Usuario_hpp
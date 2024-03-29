<div align="center">
<a href="https://www.metropoledigital.ufrn.br/portal/"><img width="323" src="img/IMD_logo.svg"></a>
<h1 align="center">Concordo.cpp</h1>
<h2 align="center"><b>Instituto Metrópole Digital, UFRN</b></h2>
<h3 align="center">Projeto 3 - Linguagem de Programação 1<br>Implementação de um Clone do Backend do Discord, com interface textual </h3>
</div>
<br>
<br>
<br>
Sistema chamado "Concordo" com recursos similares ao Discord, mas que vai funcionar somente em modo texto e sem recursos de rede. A ideia principal é simular o “backend” de um serviço com o discord, que, embora de forma simplificada, serve para dar uma boa ideia de como as coisas são feitas nesse nicho de aplicação.

<b><i>Documento de especificação detalhado : </i></b>
<br>
<a href="https://docs.google.com/document/d/1s4JKwg8HbIkrsXSfakeI5a9RZs6YNnzpK_w2Jp4tbQY/edit?usp=sharing"><img width="75" src="img/google_docs.png"></a>
<br>

[google docs](https://docs.google.com/document/d/1s4JKwg8HbIkrsXSfakeI5a9RZs6YNnzpK_w2Jp4tbQY/edit?usp=sharing)

## Para compilar

```console
mkdir build
cd build
cmake ..
cmake --build .
```

## Para executar
Você pode rodar o sistema e em logo depois digitar os comandos seguidos de ENTER
```console
cd build
./concordo
```

Ou pode criar um arquivo de texto com uma lista de comandos (um por linha) e executar o sistema redirecionando esse arquivo como entrada padrão:
```console
cd build
./concordo < ../data/script_comandos.txt
```

## Lista de comandos

| **Comando**     |**Argumentos**                 | **Descrição**                  |
|:----------------|:-----------------------------:|-------------------------------:|
|quit             | -                             |Parar o sistema.                |
|create-user      | "email" "senha" "nome"        |Criar usuário.                  |
|delete-user      | "email" "senha"               |Deletar um usuario.             |
|login            | "email" "senha"               |Entrar no sistema.              |
|disconnect       | "id usuario"                  |Desconectar do Concordo.        |
|create-server    | "id usuario" "nome do server" |Criar Servidor.                 |
|list-servers     | "id usuario"                  |Listar servers que tem o id.    |
|remove-server    | "id usuario" "nome do server" |Remover servidor.               |
|enter-server     | "id usuario" "nome do server" |Entrar em um servidor.          |
|leave-server     | "id usuario" "nome do server" |Sair de um servidor.            |
|list-participants| "id usuario"                  |Listar pessoas no servidor.     |
|list-channels    | "id usuario"                  |Listar canais do servidor.      |
|create-channel   | "id usuario" "nome do canal"  |Criar um canal no servidor.     |
|enter-channel    | "id usuario" "nome do canal"  |Entrar em um canal do servidor. |
|leave-channel    | "id usuario"                  |Sair do canal atual.            |
|remove-channel   | "id usuario" "nome do canal"  |Remover um canal no servidor.   |
|send-message     | "id usuario" "mensagem"       |Enviar mensagem para o canal.   |
|list-messages    | "id usuario"                  |Visualizar mensagens do canal.  |


## Executanto testes

Após os passos em [Para compilar](#para-compilar)
```console
cmake --build . --target teste_1
```

## Teste geral

Caso queira executar o teste geral digite:

```console
cd build
./concordo < ../data/script_teste_generico.txt
```

## testes

| **Teste**  | **Descrição**  |
|--------|------------|
| A1.0  |  ***Usuario invalido se não logado :***<br>para commandos que necessita de login no sistema  |
| A1.1  |   ***Parar o sistema:*** <br>comando quit  |
| A1.2  | ***Criar usuário: comando create-user <email> <senha_sem_espaços> <nome com espaços>***<br>
| A2.1  | ***Desconectar do Concordo: comando disconnect < id-de-usuario-logado >***<br>
| A2.2  | ***Criar servidores (nome): comando create-server < id-de-usuario-logado > < nome-do-servidor >***<br>
| A2.3  | ***Listar servidores: comando list-servers < id-de-usuario-logado >***<br>
| A2.4  | ***Remover servidor: comando remove-server < id-de-usuario-logado > < nome-do-servidor >***<br>
| A2.5  | ***Entrar em um servidor: comando enter-server < id-de-usuario-logado > < nome-do-servidor >***<br>
| A2.6  | ***Sair do servidor: comando leave-server < id-de-usuario-logado > < nome-do-servidor >***<br>
| A2.7  | ***Listar pessoas no servidor: comando list-participants < id-de-usuario-logado >***<br>

## Criar usuário (Create-user)

Comando o qual cadastra um usuário no sistema, com seu email, senha e usuário. O email passado deve ser único, caso contrário resultára em erro. O ID do usuário é criado automaticamente pelo sistema, começando em 1, depois 2, 3, 4, ... e assim por diante. Quando um usuário é deletado, o ID do próximo usuário criado será esse ID.

Para consultar as entradas dos casos de teste, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_in/A1.2.txt).

E para consultar a saída esperada, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_expected/A1.2_OUT.txt).

## Deletar um usuário (delete-user)

Deleta um usuário do sistema, passados seu email e senha, removendo-o de todos os servidores em que participa, invalidando suas mensagens e canais criados por ele. Após isso libera seu ID para o próximo usuário a ser cadastrado.

Para consultar as entradas dos casos de teste, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_in/A1.3.txt).

E para consultar a saída esperada, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_expected/A1.3_OUT.txt).

## Entrar no sistema (login)

Verifica se o email e senha passados existem no sistema, em caso afirmativo efetua o login do usuário, armazenando a informação de que o usuário está logado no sistema, adicionando o ID dele ao vetor usuariosLogados com valores nulos de Servidor e Canal.

Para consultar as entradas dos casos de teste, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_in/A1.4.txt).

E para consultar a saída esperada, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_expected/A1.4_OUT.txt).

## Desconectar do Concordo (disconnect)

Desconecta o usuário com o ID passado, atualizando o atributo que armazena os usuários atualmente logados. Para isso o usuário tem que estar logado no sistema, caso contrário uma mensagem de erro será mostrada.

Para consultar as entradas dos casos de teste, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_in/A2.1.txt).

E para consultar a saída esperada, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_expected/A2.1_OUT.txt).

## Criar servidores (create-server)

Cria um servidor com o nome passado. O servidor tem como dono o usuário do ID passado. Caso o servidor já exista, uma mensagem de erro será mostrada.

Para consultar as entradas dos casos de teste, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_in/A2.2.txt).

E para consultar a saída esperada, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_expected/A2.2_OUT.txt).

## Listar servidores (list-servers)

Exibe o nome dos servidores que o usuário com o ID passado entrou.

Para consultar as entradas dos casos de teste, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_in/A2.3.txt).

E para consultar a saída esperada, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_expected/A2.3_OUT.txt).

## Remover servidor (remove-server)

Remove um servidor informando seu nome. Só é possível remover o servidor se o dono dele for o usuário logado, caso contrário uma mensagem de erro é mostrada. Se um usuário remove o servidor que ele está visualizando, atualiza do vetor usuariosLogados de forma que ele não esteja mais visualizando esse servidor, assim como atualiza as informações de outros usuário que estão visualizando o servidor, fazendo com que os campos correspondentes ao Servidor e CanalTexto que estão sendo vistos recebam 0.

Para consultar as entradas dos casos de teste, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_in/A2.4.txt).

E para consultar a saída esperada, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_expected/A2.4_OUT.txt).

## Entrar em um servidor (enter-server)

Entra em um servidor com o nome passado e insere o ID do usuário na lista de participantes do servidor. Atualiza no vetor usuariosLogados o servidor que está sendo visualizado para esse.

Para consultar as entradas dos casos de teste, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_in/A2.5.txt).

E para consultar a saída esperada, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_expected/A2.5_OUT.txt).

## Sair do servidor (leave-server)

Desconecta de um servidor com o nome passado, removendo o usuário da lista de participantes desse servidor. Caso o usuário saia do servidor que ele estava visualizando, atualiza o vetor usuariosLogados para mostrar que nenhum servidor está sendo visualizado mais, atribuindo 0 aos campos Servidor e CanalTexto. Caso o usuário não seja membro de nenhum servidor ou não tenha entrado em nenhum, uma mensagem de erro será exibida.

Para consultar as entradas dos casos de teste, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_in/A2.6.txt).

E para consultar a saída esperada, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_expected/A2.6_OUT.txt).

## Listar pessoas no servidor (list-participants)

Exibe todos os usuários que estão no servidor que o usuário está visualizando no momento.

Para consultar as entradas dos casos de teste, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_in/A2.7.txt).

E para consultar a saída esperada, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_expected/A2.7_OUT.txt).

## Listar canais do servidor (list-channels)

Exibe todos os canais do servidor que o usuário está visualizando no momento.

Para consultar as entradas dos casos de teste, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_in/B1.1.txt).

E para consultar a saída esperada, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_expected/B1.1_OUT.txt).

## Criar um canal do servidor (create-channel)

Cria um canal, com o nome fornecido, no servidor que o usuário está visualizando. Caso o canal no servidor já exista, uma mensagem de erro será exibida.

Para consultar as entradas dos casos de teste, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_in/B1.2.txt).

E para consultar a saída esperada, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_expected/B1.2_OUT.txt).

## Entrar em um canal (enter-channel)

Entra em um canal presente na lista de canais do servidor que o usuário está visualizando. Quando um usuário entra em um canal, o sistema atualiza no vetor usuariosLogados o canal que o usuário está visualizando para esse em que acabou de entrar. Se o usuário tentar entrar em um canal que não existe, uma mensagem de erro será exibida.

Para consultar as entradas dos casos de teste, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_in/B1.3.txt).

E para consultar a saída esperada, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_expected/B1.3_OUT.txt).

## Sair de um canal (leave-channel)

Sai do canal que o usuário está visualizando no momento, atualizando o vetor usuarioLogados para indicar que nenhum canal mais está sendo visualizado por ele. Caso o usuário tente sair de um canal em que ele faz parte ou não exista, uma mensagem de erro será mostrada.

Para consultar as entradas dos casos de teste, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_in/B1.4.txt).

E para consultar a saída esperada, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_expected/B1.4_OUT.txt).

## Remover um canal do servidor (remove-channel)

Deleta um canal no servidor que está sendo visualizado pelo usuário informando seu nome. Em caso de um usuário estar visualizando um canal removido, atualiza a tabela para indicar que ele não está vendo mais canal algum, atribuindo 0 aos campos correspondentes ao Servidor e CanalTexto que estão sendo visualizados. Se o usuário tentar remover um canal que não exista ou que não é dono, uma mensagem de erro será exibida na tela.

Para consultar as entradas dos casos de teste, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_in/B1.5.txt).

E para consultar a saída esperada, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_expected/B1.5_OUT.txt).

## Enviar mensagem para o canal (send-message)

Cria uma mensagem com o conteúdo digitado, a data/hora atual e com o atributo enviadaPor com o ID do usuário recebido no comando, e adiciona na lista de mensagens do canal visualizado pelo usuário passado.

Para consultar as entradas dos casos de teste, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_in/B2.1.txt).

E para consultar a saída esperada, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_expected/B2.1_OUT.txt).

## Visualizar mensagens do canal (list-messages)

Mostra as mensagens de um canal que está sendo visualizado pelo usuário, assim como o nome do usuário que criou a mensagem e a data/hora da criação da mensagem. Caso o usuário tente visualizar as mensagens de um servidor em que ele não esteja vendo ou que não exista, uma mensagem de erro será exibida.

Para consultar as entradas dos casos de teste, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_in/B2.2.txt).

E para consultar a saída esperada, [clique aqui](https://github.com/JulioMelo-Classes/trabalho-3-concordo-deriki-julio/blob/main/data_expected/B2.2_OUT.txt).

  
## Authorship
**Docente: Julio Melo, <img width="18" src="img/email.gif">[julio@imd.ufrn.br](mailto:julio@imd.ufrn.br)**

**Dicente: Júlio César Braga Meirelles, <img width="18" src="img/email.gif">[julio.meirelles.700@ufrn.edu.br](mailto:julio.meirelles.700@ufrn.edu.br)**
  
**Dicente: Deriki Da Costa Pereira Cruz, <img width="18" src="img/email.gif">[deriki.pereira.702@ufrn.edu.br](mailto:deriki.pereira.702@ufrn.edu.br)**

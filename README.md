# Concordo.cpp

Sistema chamado "Concordo" com recursos similares ao Discord, mas que vai funcionar somente em modo texto e sem recursos de rede. A ideia principal é simular o “backend” de um serviço com o discord, que, embora de forma simplificada, serve para dar uma boa ideia de como as coisas são feitas nesse nicho de aplicação.

O documento de especificação detalhado
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

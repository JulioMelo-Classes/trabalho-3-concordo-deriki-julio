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

## Executanto testes

Após os passos em [Para compilar](#para-compilar)
```console
cmake --build . --target teste_1
```

## testes

| Teste  | Descrição  |
|--------|------------|
| noLogged  |  ***Usuario invalido se não logado :***<br>para commandos que necessita de login no sistema  |
|   |  ***A1 :***<br>Se não estiver logado(assim que entra no sistema)  |
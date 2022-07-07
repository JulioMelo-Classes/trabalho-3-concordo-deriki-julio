# Base para a atividade 03 de LP1

Use esse esqueleto de classes para iniciar a terceira atividade. O documento de especificação detalhado encontra-se
disponível no [google docs](https://docs.google.com/document/d/1s4JKwg8HbIkrsXSfakeI5a9RZs6YNnzpK_w2Jp4tbQY/edit?usp=sharing)

Existe um executor que faz a interpretação dos comandos e executa o método correto do sistema, seu trabalho aqui é implementar
a classe Sistema e as demais classes necessárias para o funcionamento do Concordo.

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

Veja que neste trabalho você precisa projetar e fornecer os testes. Tente iniciar de forma simples realizando testes de funcionalidades de acordo
com o documento de especificação e depois realizar testes complexos que executam vários comandos em cadeia!

## testes

| Teste  | Descrição  |
|--------|------------|
| in1  |  ***Usuario invalido se não logado :***<br>para commandos que necessita de login no sistema  |
| in2  |  ***A1 :***<br>Se não estiver logado(assim que entra no sistema)  |
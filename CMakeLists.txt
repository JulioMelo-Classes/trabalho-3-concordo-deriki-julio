cmake_minimum_required(VERSION 3.5)
project(concordo VERSION 0.1 LANGUAGES CXX )

# flags de compilação, aqui vc pode adicionar "-g" ou outras flags de compilação
set ( CMAKE_CXX_FLAGS "-Wall" )
# Enable Address Sanitizer (ASan) for GCC/Clang.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")

### Executável
# Diretório contendo os .hpp
include_directories( include )


# Cria um executável com nome "concordo", adiciona neste executável os arquivos src/concordo.cpp src/sistema.cpp src/executor.cpp
set( APP_NAME "concordo" )
add_executable( ${APP_NAME}
                src/Concordo.cpp
                src/Sistema.cpp 
				src/Executor.cpp
                src/Usuario.cpp
                src/Servidores.cpp
                src/CanalTexto.cpp
                src/Mensagem.cpp
                )

add_custom_target(
    teste_1
    COMMAND python3 ${CMAKE_SOURCE_DIR}/scripts/verify-inputs.py ./${APP_NAME}
    DEPENDS ${APP_NAME}
)

set_property(TARGET ${APP_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET teste_1 PROPERTY CXX_STANDARD 14)

# The end

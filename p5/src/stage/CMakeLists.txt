# Crea la librería 'catalog' a partir de sus ficheros fuente
add_library(stage stage.cc stage.h)

# Indica que la librería 'catalog' depende de la librería 'persons'
target_link_libraries(stage catalog persons)

# Hace que los includes de este directorio estén disponibles públicamente
target_include_directories(stage PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# Crea el ejecutable 'catalog-main'
add_executable(stage-main stage-main.cc)

# Enlaza el ejecutable con las librerías 'catalog' y 'persons' que necesita
target_link_libraries(stage-main PUBLIC stage catalog persons)
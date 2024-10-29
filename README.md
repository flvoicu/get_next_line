# get_next_line - Lectura de Líneas desde un Descriptor de Fichero en C

**get_next_line** es una función que permite leer una línea completa desde un **descriptor de fichero** (file descriptor) en **C**, desarrollada como parte del proyecto de la escuela **42**. La función puede manejar múltiples descriptores de fichero simultáneamente, y está diseñada para leer de cualquier fuente que se pueda tratar como un archivo, como archivos regulares o la entrada estándar.

## Funcionalidad

La función principal del proyecto es:
- **get_next_line(int fd)**: Lee una línea de texto del descriptor de fichero `fd`. Devuelve la línea completa o `NULL` si no hay nada más que leer o si ocurre un error.

Con el **bonus**, `get_next_line` es capaz de:
- Leer desde **múltiples descriptores de fichero** de forma independiente sin interferencias.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    unsigned char buffer[8];
    ssize_t bytes_leidos;

    // Leemos de a bloques de 8 bytes
    while ((bytes_leidos = read(0, buffer, 8)) > 0) {
        // Si leímos 8 bytes completos, el último es nuestro dato
        if (bytes_leidos == 8) {
            if (write(1, &buffer[7], 1) == -1) {
                perror("Error al escribir mensaje desencriptado");
               
                exit(EXIT_FAILURE);
            }
        }
    }

    exit(EXIT_SUCCESS);
}
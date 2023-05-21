#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* path = getenv("PATH"); // Get the value of the PATH environment variable

    if (path != NULL) {
        char* directory = strtok(path, ":"); // Tokenize the path using ":" delimiter

        while (directory != NULL) {
            printf("Directory: %s\n", directory);
            directory = strtok(NULL, ":"); // Get the next token
        }
    }

    return 0;
}


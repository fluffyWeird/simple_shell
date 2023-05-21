#include <stdio.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024

int main() {
    char current_path[MAX_PATH_LENGTH];
    
    if (getcwd(current_path, sizeof(current_path)) != NULL) {
        printf("Current path: %s\n", current_path);
    } else {
        perror("Error getting current path");
        return 1;
    }
    
    return 0;
}


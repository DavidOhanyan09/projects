#include <iostream>
#include <fcntl.h>  
#include <unistd.h>  

int main() {
    close(1);
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    std::cout << "Something....." << std::endl;
    close(fd);
    return 0;
}



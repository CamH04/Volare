
//TODO
//tokanise each line:
//      read every line: each line will be a label or instruction
//      if opcode is empty go next line
//      we add opcode to token array
//          if opcode takes args add to token array (eg PRINT)
//convert tokens to asm:
//      read from token array
//      convert token and args to an asm eqiuvilent
//      output to a .asm file of the same name as volare file

//IN PROGRESS

//DONE
// read from file with extention .vpl for linux

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int has_vpu_extension(const char *filename) {
    const char* dot = strrchr(filename, '.');
    return dot && strcmp(dot, ".vpu") == 0;
}

void printBuffer(FILE* _file){
    char buffer[256]; // oh no
    while (fgets(buffer, sizeof(buffer), _file)) {
        printf("%s", buffer);
    }
}

int main(int argc, char *argv[]) {
    //file checks
    //-------------------------------------------------------------------------
    char* volare_error = "\033[1;31mVolare Compler ERROR: ";
    char* volare_error_terminator = "\033[0m\n";
    if(argc < 2){
        //horrid
        snprintf(volare_error, 256, "Usage: %s <file.vpu>", argv[0]);
        return 1;
    }
    if(!has_vpu_extension(argv[1])){
        fprintf(stderr, "\033[1;31mVolare Compler ERROR: File must have a .vpu extension\033[0m\n");
        return 1;
    }
    FILE* file = fopen(argv[1], "r");
    if(!file){
        perror(strcat(volare_error, "File Not Found"));
        return 1;
    }
    //-------------------------------------------------------------------------
    printBuffer(file);
    fclose(file);
    return 0;
}

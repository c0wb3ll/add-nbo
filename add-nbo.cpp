#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>

void check_argc(int argc) {

    if (argc != 3) {
        
        printf("[+] usage : ./add-nbo <arg1> <arg2>\n");
        exit(1);

    }
}

uint32_t read_file(char argv[]) {

    FILE *fp;
    uint32_t tmp;
    uint32_t num;

    fp = fopen(argv, "rb");

    if(fp == NULL) {

        printf("[+] %s does not exist\n", argv);
        exit(1);

    } else {
        
        fread(&tmp, 4, 1, fp);
        num = ntohl(tmp);
        fclose(fp);

        return num;

    }

}

uint32_t sum(uint32_t num1, uint32_t num2) {

    return num1 + num2;

}

int main(int argc, char* argv[]) {

    uint32_t num1;
    uint32_t num2;
    uint32_t result;

    check_argc(argc);
    num1 = read_file(argv[1]);
    num2 = read_file(argv[2]);
    result = sum(num1, num2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, result, result);

    return 0;

}
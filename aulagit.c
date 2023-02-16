#include <stdio.h>
    
int main(){
    char opt;

    printf("Isso é só um teste ;)");

    do{
        printf("\nMenu: \n (1) - Continuar\n (2) - Sair\n > ");
        scanf("%c", opt);
        switch (opt)
        {
        case '1':
            continue;
        
        default:
            return 0;
            break;
        }
    } (while opt != '2');
    
    return 0;
}
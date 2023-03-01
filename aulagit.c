#include <stdio.h>

int EhImparPar(char *entrada);

int main(){
    int opt, char teste;
    char *entrada = "aba";

    printf("Isso é só um teste (:");

    do{
        printf("\nMenu: \n (1) - Teste goto\n (2) - Sair\n > ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("\nSaída: %d", EhImparPar(entrada));
            continue;
        
        default:
            break;
        }
    } while (opt != 2);
    
    return 0;
}

int EhImparPar(char *entrada) {
  
  AParBPar:
    if (*entrada == 'a') {
      entrada++;
      goto AImparBPar;
    } else if (*entrada == 'b') {
      entrada++;
      goto AParBImpar;
    } else {
       return 0;
    }

  AImparBPar:
    if (*entrada == 'a') {
      entrada++;
      goto AParBPar;
    } else if (*entrada == 'b') {
      entrada++;
      goto AImparBImpar;
    }
    else {
      return 1;
    }

  AImparBImpar:
    if (*entrada == 'a') {
      entrada++;
      goto AParBImpar;
    } else if (*entrada == 'b') {
      entrada++;
      goto AImparBPar;
    }
     else {
       return 0;
    }
  
  AParBImpar:
    if (*entrada == 'a') {
      entrada++;
      goto AImparBImpar;
    } else if (*entrada == 'b') {
      entrada++;
      goto AParBPar;
      } else {
       return 0;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

  char convertido1[40],
       convertido2[40];

  void parabin(int num1, int num2);
  void parahexa(int num1, int num2);
  void complemento(char convertido1[40], char convertido2[40]);

int  main() {

  int num1 = 80,
      num2 = 35;

  printf("A variavel A vale %d e a B vale %d\n\n", num1, num2);
  printf("Conversao binario:\n\n\n");

  parabin(num1, num2);

  printf("\n\n\n");
  printf("Conversao para hexadecimal:\n\n\n");

  parahexa(num1, num2);

  printf("\n\n\n");
  printf("Os complementos sao: \n\n\n");

  complemento(convertido1, convertido2);

  return 0;
}

void parabin(int num1, int num2){

  int quociente = 0,
      resto = 0,
      div = 0;

  char str1[10],
       str2[10],
       armazen[40];

  itoa(num1, str1, 10);
  itoa(num2, str2, 10);

  strcpy(convertido1, "");

  /* Conversão de A */

  quociente = num1;

  while(quociente >= 2){

    resto = quociente % 2;
    div = quociente / 2;
    quociente = div;

    sprintf(armazen, "%d", resto);

    strcat(convertido1, armazen);

  }

  sprintf(armazen, "%d", quociente);

  strcat(convertido1, armazen);

  printf("O valor A eh %s\n", strrev(convertido1));

/* Conversão de B */

  strcpy(convertido2, "");

  quociente = num2;

  while(quociente >= 2){

    resto = quociente % 2;
    div = quociente / 2;
    quociente = div;

    sprintf(armazen, "%d", resto);

    strcat(convertido2, armazen);

  }

  sprintf(armazen, "%d", quociente);

  strcat(convertido2, armazen);

  printf("E o valor B eh %s\n", strrev(convertido2));

  }

void parahexa(int num1, int num2){

  int quociente = 0,
      resto = 0,
      div = 0;

  char str1[10],
       str2[10],
       convertido[40],
       armazen[40];

  char* hexa = "0123456789ABCDEF";

  itoa(num1, str1, 10);
  itoa(num2, str2, 10);


/* Conversão de A */

  quociente = num1;

  strcpy(convertido, "");

  while(quociente >= 16){

    resto = quociente % 16;
    div = quociente / 16;
    quociente = div;

    sprintf(armazen, "%c", hexa[resto]);

    strcat(convertido, armazen);

  }

  sprintf(armazen, "%c", hexa[quociente]);

  strcat(convertido, armazen);

  printf("A eh: %s\n", strrev(convertido));

/* Conversão de B */

  quociente = num2;

  strcpy(convertido, "");

  while(quociente >= 16){

    resto = quociente % 16;
    div = quociente / 16;
    quociente = div;

    sprintf(armazen, "%c", hexa[resto]);

    strcat(convertido, armazen);

  }

  sprintf(armazen, "%c", hexa[quociente]);

  strcat(convertido, armazen);

  printf("E B eh: %s\n", strrev(convertido));


}

void complemento(char convertido1[40], char convertido2[40]){

  int i,
      tamanho,
      complementoA[40],
      complementoB[40],
      complemento2A[40],
      complemento2B[40],
      tamanhoA,
      tamanhoB,
      somaA,
      somaB,
      sobe = 0,
      x;

  char binarioa[40],
       binariob[40],
       soma[40];

/* Complemento de A */

  printf("Para A:\t");

  tamanho = strlen(convertido1);

  for (i = 0; i < tamanho; i++) {

    if (convertido1[i] == '0'){

      complementoA[i] = 1;

    } else {

      complementoA[i] = 0;

    }

    printf("%i", complementoA[i]);

  }

/* Complemento de B */

  printf("\n");
  printf("E para B:\t");

  tamanho = strlen(convertido2);

  for (i = 0; i < tamanho; i++) {

    if (convertido2[i] == '0'){

      complementoB[i] = 1;

    } else {

      complementoB[i] = 0;

    }

    printf("%i", complementoB[i]);

  }

  /* Complemento de 2 */

  printf("\n\n");
  printf("E o complemento a 2 eh:\n\n");

  tamanhoA = sizeof(complementoA)/sizeof(int);
  tamanhoB = sizeof(complementoB)/sizeof(int);

  /* Complemento a 2 de A */

  printf("A:\t");

  for(i = 0 ; i < tamanhoA ; i++){

    complemento2A[i] = complementoA[i];

  }

  for (i = tamanhoA-1; i >= 0; i--) {

    if(convertido1[i] == 1){

      complemento2A[i] = 0;

    } else {

      complemento2A[i] = 1;

      break;

    }

    printf("%d", complemento2A[i]);

  }

  /* Soma de A e B */

  while (tamanhoA > tamanhoB) {

    for (i = tamanhoB ; i >= 0; i--){

      binariob[i+1] = binariob[i];

    }

    binariob[0] = '0';

    tamanhoB++;

  }

  while (tamanhoA < tamanhoB) {

    for (i = tamanhoA; i >= 0; i--){

      binarioa[i+1] = binarioa[i];

    }

    tamanhoA++;

  }

  for(i = tamanhoA - 1 ; i >= 0 ; i--){

      x = sobe + (binarioa[i] - '0') + (binariob[i] - '0');

      if (x > 1){

        sobe = 1;

      } else {

        sobe = 0;

      }

      soma[i+1] = (x % 2) + '0';

  }

  soma[0] = sobe + '0';

  soma[tamanhoA+1] = '\0';

  printf("A soma entra A e B eh:\n");
  printf("\n %s\n +\n %s\n =\n%s\n", binarioa, binariob, soma);

}

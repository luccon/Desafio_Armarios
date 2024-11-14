#include <stdio.h>
#include <stdlib.h>

unsigned char armarios = 0, pos, mascara=0X01;
char menu = 0;

void DecimalBinario (int num) {
    for (int i = 7; i >= 0; i--){ 
        int bit = (num >> i) & 1;
        printf("%d",bit);
    }
  printf("\n");
}

int main () {
while (1) {
while(1) {
  printf("Mapa de Armarios: ");
  DecimalBinario(armarios);
  printf("\nMenu:\n[1] Ocupar armário.\n[2] Liberar armário.\n[3] Sair.\n");
  scanf(" %c",&menu);
  if(menu == '2' && armarios == 0){
    printf("Nenhum armário está ocupado.\n");
  }
   else if (menu < '1' || menu > '3') {
    printf("Opção inválida.\n");
  } else {
    break;
  }
 }
  switch (menu){
    case '1':
    mascara = 0X01;
    srand(time(NULL));
    pos = rand() % 8;
    mascara = mascara << (pos);
    
      int checar = 1 << pos;
        while(armarios & checar){
          mascara = 0X01;
          pos = rand() % 8;
          mascara = mascara << (pos);
          checar = 1 << pos;
        }
     
    armarios = armarios | mascara; 
    printf("Armário %d ocupado.\n",pos+1);
    break;
    
    case '2':
    mascara = 0X01;
    printf("Qual armário deseja desocupar?\n");
    scanf("%hhu",&pos);
      int checar2 = 1 << (pos-1);
      while ((armarios & checar2)==0){
        printf("O armario %d já está desocupado.\n",pos);
        printf("Qual armário deseja desocupar?\n");
        scanf("%hhu",&pos);
        checar2 = 1 << (pos-1);
      }
    armarios = armarios & ~(mascara << (pos-1));
    printf("Armário %d desocupado.\n",pos);
    break;
    case '3':
    break;
  }
  if (menu == '3') {
    printf("Programa finalizado!");
    break;
  }
}
}

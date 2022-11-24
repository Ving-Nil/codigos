#include <stdio.h>
#include <string.h>

int main(){
    char vehiculo[] = "Motocicleta";
    if( strcmp(vehiculo, "Autobus") == 0 ){
        printf("Es un autobus!!\n");
    }
    else if( strcmp(vehiculo, "Automovil") == 0 ){
        printf("Es un automovil!!\n");
    }
    else if( strcmp(vehiculo, "Motocicleta") == 0 ){
        printf("Es un motocicleta!!\n");
    }

    return 0;
}


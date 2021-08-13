
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_CONTACTOS 1000

void main()
{
    printf("Programa lista de contactos\n");
    char cuenta[MAX_CONTACTOS][20];
    char nombre[MAX_CONTACTOS][20];
    char direcion[MAX_CONTACTOS][20];
    char telefono[MAX_CONTACTOS][10];
    float saldo[MAX_CONTACTOS];
    int last_index = 0;
    
    //Para actualizar
    bool flag = false;
    char cuenta_remplazar[20];
    char nombre_nuevo[20];
    char telefono_nuevo[20];
    char direccion_nuevo[20];
    float saldo_nuevo;
    
    int opcion;
    while(1){
        printf("Menu\n");
        printf("1- Agregar nueva cuenta\n");
        printf("2- Listar cuentas\n");
        printf("3- Actualizar cuenta\n");
        printf("4- Eliminar cuenta\n");
        printf("5- Validar cuenta\n");
        printf("6- Salir\n");
        printf("Seleccione una opcion\n");
        scanf("%i", &opcion);
        
        switch(opcion){
            case 1:
            if(last_index >= MAX_CONTACTOS){
                printf("Maxima capacidad alcanzada:\n");
            }else{
                printf("Introduzca los datos de la cuenta:\n\n");
                printf("Cuenta: ");
                scanf("%s",cuenta[last_index]);
                printf("Nombre: ");
                scanf("%s",nombre[last_index]);
                printf("Direcion: ");
                scanf("%s",direcion[last_index]);
                printf("Telefono: ");
                scanf("%s",telefono[last_index]);
                printf("Fondos: ");
                scanf("%f",&saldo[last_index]);
                last_index +=1;
            }
            
            
            printf("Cuenta agregada...\n\n");
            break;
             
            case 2:
            printf("Cuentas disponibles\n\n");
           
            for (int i = 0; i <last_index ; i++) {
                printf("Cuenta: %s\n", cuenta[i]);
                printf("%s: %s, %s \n",nombre[i], direcion[i],telefono[i] );
                printf("Saldo: %0.2f\n\n", saldo[i]);
            }
            printf("\n\n");
            break;
            
            case 3:
            printf("Introduzca el numero de cuenta para actualizar: \n");
            scanf("%s", cuenta_remplazar);
            for (int i = 0; i < last_index; i++) {
                if(strcmp(cuenta[i], cuenta_remplazar) == 0){
                    printf("Cuenta encontrada, introduzca los nuevos datos: \n");
                    printf("Nombre: ");
                    scanf("%s",nombre_nuevo);
                    printf("Direcion: ");
                    scanf("%s",direccion_nuevo);
                    printf("Telefono: ");
                    scanf("%s",telefono_nuevo);
                    printf("Nuevo saldo: ");
                    scanf("%f",&saldo_nuevo);
                    strcpy(nombre[i],nombre_nuevo );
                    strcpy(direcion[i],direccion_nuevo );
                    strcpy(telefono[i],telefono_nuevo );
                    saldo[i] = saldo_nuevo;
                    printf("Cuenta %s actualizada... \n\n",cuenta[i] );
                    flag = true;
                }
            }
            
            if(!flag) printf("No se encontro el nombre...\n\n");
            break;
            
            case 4:
            
             printf("Introduzca la cuenta que va a eliminar: \n");
            scanf("%s", cuenta_remplazar);
            for (int i = 0; i < last_index; i++) {
                if(strcmp(cuenta[i], cuenta_remplazar) == 0){
                    for (int j = i; j < last_index-1; j++) {
                        strcpy(nombre[i],nombre[i+1] );
                        strcpy(direcion[i],direcion[i+1] );
                        strcpy(telefono[i],telefono[i+1] );
                        saldo[i] = saldo[i+1];
                    }
                    last_index -= 1;
                    printf("Cuenta %s  eliminada... \n\n",cuenta[i]);
                    flag = true;
                }
            }
            
            if(!flag) printf("No se encontro el nombre...\n\n");
            break;
            
            case 5:
            printf("Introduzca la cuenta para verificar: \n");
            scanf("%s", cuenta_remplazar);
            for (int i = 0; i < last_index; i++) {
                if(strcmp(cuenta[i], cuenta_remplazar) == 0){
                    printf("Cuenta: %s, verificada\n", cuenta[i]);
                    printf("%s: %s, %s \n",nombre[i], direcion[i],telefono[i] );
                    printf("Saldo: %0.2f\n\n", saldo[i]);
                    flag = true;
                }
            }
            
            if(!flag) printf("No se encontro la cuenta en el sistema...\n\n");
            
            break;
            
            case 6:
            
            return;
            break;
            
            default:
            printf("Opcion no valida...\n\n");
        }
        
    }

    
}


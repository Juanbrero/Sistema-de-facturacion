#include "ABM.h"
#include "ABM.c"


int main() {

    int op;

    while ((op = menu()) != 0) {
        
        switch (op) {
        
            case 1:
                altaClientes(true, 0);
                break;            
            case 2:
                altaProductos();
                break;            
            case 3:
                altaVentas();
                break;                    
            case 4:
                mostrarClientes();
                break;           
            case 5:
                mostrarProductos();
                break;
            case 6:
                mostrarVentas();
                break;            
            default:
                printf("\nSaliendo...\n\n");
                break;
            }
    }

    return 0;

}
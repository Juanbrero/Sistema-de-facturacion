#include <stdio.h>
#include <string.h>
#include "ABM.h"


struct Cliente {

    int codigo;
    char nombre[16];
    char apellido[16];
};

struct Producto {

    int codigo;
    char nombre[16];
    int stock;
    int precio;
};

struct Venta {

    int nroVta;
    int codCli;
};


// ---------------------------------------------------------------------------------------

// ##################################### CLIENTES ########################################

// ---------------------------------------------------------------------------------------

int buscarCodigoCliente(int codigo) {

    FILE *arch = fopen("Clientes.bin", "rb");
    int pos;

    if(arch != NULL) {

        struct Cliente reg;
        
        int nb = fread(&reg, sizeof(struct Cliente), 1, arch);
            
        while (nb > 0 && reg.codigo != codigo) {

            nb = fread(&reg, sizeof(struct Cliente), 1, arch); 
            
        }

        if (nb == 0) {

            pos = -1;           
        }
        else {

            pos = (ftell(arch) / sizeof(struct Cliente));
        }

        fclose(arch);
        
    }
    else {

        pos = -1;
    }
    
    return pos;

}

void altaClientes(bool cargaDirecta, int codExterno) {

    struct Cliente reg;

    if(cargaDirecta) {
    
        printf("\nIngresar codigo de cliente (0 para dejar de cargar)\n");
        scanf("%i", &reg.codigo);
        
            
        while (reg.codigo != 0) {

            int pos = buscarCodigoCliente(reg.codigo);

            if (pos == -1) {

                printf("\nIngresar apellido y nombre\n");

                scanf("%s %s", reg.apellido, reg.nombre);
                strtok(reg.apellido, "\n");
                strtok(reg.nombre, "\n");

                FILE *arch = fopen("Clientes.bin", "ab");

                if (arch != NULL) {
                    
                    fwrite(&reg, sizeof(struct Cliente), 1, arch);
                }

                fclose(arch);

            }
            else {

                printf("\nEl codigo del cliente #%i ya existe en la posicion %i.\n", reg.codigo, pos);

            }

            printf("\nIngresar codigo de cliente (0 para dejar de cargar)\n");
            scanf("%i", &reg.codigo);

        }
    }
    else {

        printf("\nIngresar apellido y nombre\n");

        reg.codigo = codExterno;
        scanf("%s %s", reg.apellido, reg.nombre);
        strtok(reg.apellido, "\n");
        strtok(reg.nombre, "\n");

        FILE *arch = fopen("Clientes.bin", "ab");

        if (arch != NULL) {
                    
            fwrite(&reg, sizeof(struct Cliente), 1, arch);
        }

        fclose(arch);

    }
        
}
    

void mostrarClientes() {

    FILE * arch = fopen("Clientes.bin", "rb");

    if (arch != NULL) {

        struct Cliente reg;
        int nb = fread(&reg, sizeof(struct Cliente), 1, arch);
        
        printf("\t\t***** CLIENTES *****\n");
        printf("\nCodigo\t\tApellido\tNombre\n\n");

        while (nb > 0) {

            printf("\n- # %i\t\t%s\t\t%s", reg.codigo, reg.apellido, reg.nombre);
            nb = fread(&reg, sizeof(struct Cliente), 1, arch);
        }

        fclose(arch);
    }
    else {

        printf("\nError al abrir archivo Clientes.\n\n");
    }

}


// ---------------------------------------------------------------------------------------

// ##################################### PRODUCTO ########################################

// ---------------------------------------------------------------------------------------


int buscarCodigoProducto(int codigo) {

    FILE *arch = fopen("Productos.bin", "rb");
    int pos;

    if(arch != NULL) {

        struct Producto reg;
        
        int nb = fread(&reg, sizeof(struct Producto), 1, arch);
            
        while (nb > 0 && reg.codigo != codigo) {

            nb = fread(&reg, sizeof(struct Producto), 1, arch); 
            
        }

        if (nb == 0) {

            pos = -1;           
        }
        else {

            pos = (ftell(arch) / sizeof(struct Producto));
        }

        fclose(arch);
        
    }
    else {

        pos = -1;
    }
    
    return pos;

}

void altaProductos() {

    struct Producto reg;

    printf("\nIngresar codigo de producto (0 para dejar de cargar)\n");
    scanf("%i", &reg.codigo);
    
        
    while (reg.codigo != 0) {

        int pos = buscarCodigoProducto(reg.codigo);

        if (pos == -1) {

            printf("\nIngresar nombre de producto\n");
            scanf("%s", reg.nombre);
            strtok(reg.nombre, "\n");
            
            fflush(stdin);

            printf("\nIngresar precio de producto\n");
            scanf("%i", &reg.precio);
            
            printf("\nIngresar cantidad en stock de producto\n");
            scanf("%i", &reg.stock);
            
            FILE *arch = fopen("Productos.bin", "ab");

            if (arch != NULL) {
                
                fwrite(&reg, sizeof(struct Producto), 1, arch);
            }

            fclose(arch);

        }
        else {

            printf("\nEl codigo de producto #%i ya existe en la posicion %i.\n", reg.codigo, pos);

        }

        printf("\nIngresar codigo de producto (0 para dejar de cargar)\n");
        scanf("%i", &reg.codigo);

    }
        
}
    

void mostrarProductos() {

    FILE * arch = fopen("Productos.bin", "rb");

    if (arch != NULL) {

        struct Producto reg;
        int nb = fread(&reg, sizeof(struct Producto), 1, arch);
        
        printf("\t\t***** Productos *****\n");
        printf("\nCodigo\t\tNombre\t\tPrecio\t\tEn Stock\n\n");

        while (nb > 0) {

            printf("\n- # %i\t\t%s\t\t%i\t\t%i", reg.codigo, reg.nombre, reg.precio, reg.stock);
            nb = fread(&reg, sizeof(struct Producto), 1, arch);
        }

        fclose(arch);
    }
    else {

        printf("\nError al abrir archivo Productos.\n\n");
    }

}


// ---------------------------------------------------------------------------------------

// ##################################### VENTAS ########################################

// ---------------------------------------------------------------------------------------


int buscarNroVta(int codigo) {

    FILE *arch = fopen("Ventas.bin", "rb");
    int pos;

    if(arch != NULL) {

        struct Venta reg;
        
        int nb = fread(&reg, sizeof(struct Venta), 1, arch);
            
        while (nb > 0 && reg.nroVta != codigo) {

            nb = fread(&reg, sizeof(struct Venta), 1, arch); 
            
        }

        if (nb == 0) {

            pos = -1;           
        }
        else {

            pos = (ftell(arch) / sizeof(struct Venta));
        }

        fclose(arch);
        
    }
    else {

        pos = -1;
    }
    
    return pos;

}

void altaVentas() {

    struct Venta reg;

    printf("\nIngresar nro de venta (0 para dejar de cargar)\n");
    scanf("%i", &reg.nroVta);
    
        
    while (reg.nroVta != 0) {

        int pos = buscarNroVta(reg.nroVta);

        if (pos == -1) {

            printf("\nIngresar codigo de cliente\n");
            scanf("%i", &reg.codCli);

            int cliente = buscarCodigoCliente(reg.codCli);

            if (cliente == -1) {

                printf("\nCliente no identificado. Registrando nuevo cliente...\n\n");
                altaClientes(false, reg.codCli);
                printf("\nSe dio de alta nuevo cliente. Codigo # %i\n", reg.codCli);
            }
            
            FILE *arch = fopen("Ventas.bin", "ab");

            if (arch != NULL) {
                
                fwrite(&reg, sizeof(struct Venta), 1, arch);
            }

            fclose(arch);

        }
        else {

            printf("\nEl nro de venta #%i ya existe en la posicion %i.\n", reg.nroVta, pos);

        }

        printf("\nIngresar nro de venta (0 para dejar de cargar)\n");
        scanf("%i", &reg.nroVta);

    }
        
}
    

void mostrarVentas() {

    FILE * arch = fopen("Ventas.bin", "rb");

    if (arch != NULL) {

        struct Venta reg;
        int nb = fread(&reg, sizeof(struct Venta), 1, arch);
        
        printf("\t\t***** Ventas *****\n");
        printf("\nNro Venta\tCod. Cliente\n\n");

        while (nb > 0) {

            printf("\n- # %i\t   -> \t# %i", reg.nroVta, reg.codCli);
            nb = fread(&reg, sizeof(struct Venta), 1, arch);
        }

        fclose(arch);
    }
    else {

        printf("\nError al abrir archivo Ventas.\n\n");
    }

}


// ---------------------------------------------------------------------------------------


int menu() {

    int op;

    printf("\n\n\t\t***** Menu Principal *****\n\n");
    
    printf("\t1- Cargar clientes\n");
    printf("\t2- Cargar productos\n");
    printf("\t3- Cargar ventas\n");
    printf("\t4- Mostrar cliente\n");
    printf("\t5- Mostrar productos\n");
    printf("\t6- Mostrar ventas\n");

    printf("\t\t0- Salir.\n\n");

    printf("Ingresar opcion: \n\n");

    scanf("%i", &op);

    return  op;

}

#include "libS8.h"
void main(){
    struct Recursos recurso[maxRecursos];
    struct Productos producto[maxProductos];
    srand(time(NULL)); 
    printBienvenida();
A:
    printf("-----------------------------------------------------\n");
    printf("|Ingrese el numero de recursos existentes(Maximo %d):\n",maxRecursos);
    printf("|");
    scanf("%d",&nR);
        if (nR>0&&nR<=maxRecursos){
        }else{
            printf("-----------------------------------------------------\n");
            printf("----Numero de Recursos Invalido, ingrese de nuevo----\n");
            goto A;}
//DECLARACION DE RECURSOS
    for (int i = 0; i < nR; i++) {
        printf("-----------------------------------------------------\n");
        printf("| Nombre del Recurso #%d: ",i+1);
        scanf("%s", recurso[i].nombre);
    B:
        printf("| Cantidad inicial de %s: ",recurso[i].nombre);
        scanf("%f", &recurso[i].cantidad);
            if (recurso[i].cantidad>=0){
            }else{
                printCantRecursosInvalid();
            goto B;}
        recurso[i].id = idRandom();
        printf("| ID de %s: %d\n", recurso[i].nombre, recurso[i].id);
    }
    //DECLARACION DE PRODUCTOS
    printf("-----------------------------------------------------\n");
    printf("--------------DECLARACION DE PRODUCTOS---------------\n");
        for (int i = 0; i < maxProductos; i++) {
            printf("-----------------------------------------------------\n");
            printf("| Nombre del Producto #%d: ",i+1);
            scanf("%s", producto[i].nombre);  
        C:
            printf("| Ingrese la cantidad de Recursos que %s necesita\n",producto[i].nombre);
            printf("| MAXIMO %d Recursos: ",nR);
            scanf("%d",&cR);
                if (cR>0&&cR<=nR){
                    producto[i].cantRecursos=cR;
                }else{     
                    printCantRecursosInvalid();
                    goto C;}
                for (int j = 0; j < cR; j++) {
                D:
                    printf("-----------------------------------------------------\n");
                    printf("| Id del recurso #%d de %s: ",j+1,producto[i].nombre);
                    scanf("%d", &producto[i].caR[j].id);  
                        if ((buscarRecursoPorID(recurso,maxRecursos,producto[i].caR[j].id))!=-1){
                        }else{
                            printidRecursosInvalido();
                            goto D;};
                E:
                    printf("| Cantidad necesaria de %s: ",recurso[buscarRecursoPorID(recurso,maxRecursos,producto[i].caR[j].id)].nombre);
                    scanf("%f", &producto[i].caR[j].cantidad);
                        if (producto[i].caR[j].cantidad>0){
                        }else{
                            printCantRecursosInvalid();
                            goto E;}
                        printf("%s necesita %.2f de %s\n", producto[i].nombre,producto[i].caR[j].cantidad,recurso[buscarRecursoPorID(recurso,maxRecursos,producto[i].caR[j].id)].nombre);
                    }
            printf("-----------------------------------------------------\n");
            printf("| Tiempo de fabricacion en minutos para 1 %s: ",producto[i].nombre);
            scanf("%f",&producto[i].mP);
            producto[i].id = idRandom();
            printf("\n============== DETALLES DEL PRODUCTO %d ==============\n",i+1);
            printf("Nombre del Producto: %s\n", producto[i].nombre);
            printf("ID del Producto: %d\n", producto[i].id);
            printf("Tiempo de produccion por unidad: %.2f minutos\n", producto[i].mP);
            printf("================ RECURSOS REQUERIDOS ================\n");
                for (int j = 0; j < cR; j++) {
                    int pos = buscarRecursoPorID(recurso, nR, producto[i].caR[j].id);
                        if (pos != -1) {
                            printf("Recurso %s (ID: %d), Cantidad requerida: %.2f\n",recurso[pos].nombre,producto[i].caR[j].id,producto[i].caR[j].cantidad);}
                    }
            printf("=====================================================\n");
        }

//MENU DE OPCIONES
    F:
    printMenuP();
    scanf("%d",&opcion);
    switch (opcion){
                case 1:
                    int i,id;
                    float cantRequerida,tiemRequerido,tiemTotal;
                    bool demanda;
                G:
                    printf("| Ingrese el ID del producto : \n|" );
                    scanf("%d",&id);
                        if (buscarProductoPorID(producto,maxProductos,id)!=-1){
                            i=buscarProductoPorID(producto,maxProductos,id);
                        }else{
                            printIdProductoInvalid();
                            goto G;}
                H:
                    printf("| Ingrese la cantidad requerida de %s : \n",producto[i].nombre );
                    scanf("%f",&cantRequerida);
                        if (cantRequerida>0){
                        }else{
                            printf("-----------------------------------------------------\n");
                            printf("----Cantidad Requerida Invalida, ingrese de nuevo----\n");  
                            printf("-----------------------------------------------------\n");  
                            goto H;}
                I:
                    printf("| Ingrese el tiempo (minutos) solicitado para la entrega de %.2f %s : \n",cantRequerida,producto[i].nombre );//recurso[i].nombre, recurso[i].id
                    scanf("%f",&tiemRequerido);
                        if (tiemRequerido>0){
                        }else{
                            printf("-----------------------------------------------------\n");
                            printf("-----Tiempo Requerido Invalido, ingrese de nuevo-----\n");  
                            printf("-----------------------------------------------------\n");  
                            goto I;}
                    tiemTotal=producto[i].mP*cantRequerida;
                    printf("| Tiempo total de producion para %.2f %s: %.2f minutos\n",cantRequerida,producto[i].nombre,tiemTotal);
                    printf("| POSIBILIDAD DE ENTREGA EN TIEMPO ACORDADO: ");    
                        if (tiemTotal<=tiemRequerido){
                            printf("SI\n"); 
                            demanda=true;   
                        }else{
                            printf("NO\n");
                            demanda=false;}
                    printf("| CANTIDAD DE RECURSOS REQUERIDO PARA %.2f %s: \n",cantRequerida,producto[i].nombre);
                    for (int j = 0; j < (producto[i].cantRecursos); j++) {
                        int pos = buscarRecursoPorID(recurso, nR, producto[i].caR[j].id);
                            if (pos != -1) {
                                printf("| Recurso %s (ID: %d), Cantidad requerida: %.2f\n| Cantidad actual de %s: %.2f\n",recurso[pos].nombre,producto[i].caR[j].id,producto[i].caR[j].cantidad*cantRequerida,recurso[pos].nombre,recurso[pos].cantidad);
                            }
                            if (producto[i].caR[j].cantidad*cantRequerida<=recurso[pos].cantidad){
                                printf("|Existencia de recursos:\n| SI cumple con los recursos necesitados\n");    
                                demanda=demanda && true;
                            }else{
                                printf("|Existencia de recursos: \n| NO cumple con los recursos necesitados\n");
                                demanda=demanda && false;}
                    }
                    if (demanda==true){
                        printf("| SE PUEDE PROCEDER CON LA DEMANDA\n");
                    }else{
                        printf("| NO PUEDE PROCEDER CON LA DEMANDA\n");}
                goto F;

                case 2:
                    int l,ld,opC2;
                J:
                    printf("| Ingrese el ID del producto a Editar : \n|" );
                    scanf("%d",&ld);
                        if (buscarProductoPorID(producto,maxProductos,ld)!=-1){
                            l=buscarProductoPorID(producto,maxProductos,ld);
                        }else{
                            printIdProductoInvalid();
                            goto J;}
                K:
                    printf("-----------------------------------------------------\n");
                    printf("| MENU DE EDICION DEL PRODUCTO #%d: %s\n",l+1,producto[l].nombre);
                    printf("-----------------------------------------------------\n");
                    printf("|1. EDITAR NOMBRE\n");
                    printf("|2. EDITAR MATERIALES REQUERIDOS PARA FABRICAR 1 %s\n",producto[l].nombre);
                    printf("|3. EDITAR TIEMPO DE FABRICACION DE 1%s\n",producto[l].nombre);
                    printf("|4. SALIR\n");
                    printf("-----------------------------------------------------\n|");
                    scanf("%d",&opC2);
                        switch (opC2){
                                    case 1:
                                        printf("-----------------------------------------------------\n");
                                        printf("| Nuevo nombre del Producto #%d: ",l+1);
                                        scanf("%s", producto[l].nombre); 
                                    goto K;

                                    case 2:
                                    L:
                                        printf("| Ingrese la cantidad de Recursos que %s necesita\n",producto[l].nombre);
                                        printf("| MAXIMO %d Recursos: ",nR);
                                        scanf("%d",&cR);
                                            if (cR>0&&cR<=nR){
                                                producto[i].cantRecursos=cR;
                                            }else{     
                                                printCantRecursosInvalid();
                                                goto L;}
                                            for (int j = 0; j < cR; j++) {
                                            M:
                                                printf("-----------------------------------------------------\n");
                                                printf("| Id del recurso #%d de %s: ",j+1,producto[l].nombre);
                                                scanf("%d", &producto[l].caR[j].id);  
                                                    if ((buscarRecursoPorID(recurso,maxRecursos,producto[l].caR[j].id))!=-1){
                                                    }else{
                                                        printidRecursosInvalido();
                                                        goto M;};
                                            N:
                                                printf("| Cantidad necesaria de %s: ",recurso[buscarRecursoPorID(recurso,maxRecursos,producto[l].caR[j].id)].nombre);
                                                scanf("%f", &producto[l].caR[j].cantidad);
                                                    if (producto[l].caR[j].cantidad>0){
                                                    }else{
                                                        printCantRecursosInvalid();  
                                                        goto N;}
                                                printf("%s necesita %.2f de %s\n", producto[l].nombre,producto[l].caR[j].cantidad,recurso[buscarRecursoPorID(recurso,maxRecursos,producto[l].caR[j].id)].nombre);
                                            }
                                        printf("-----------------------------------------------------\n");
                                    goto K;

                                    case 3:
                                        printf("-----------------------------------------------------\n");
                                        printf("| Nuevo tiempo de Fabricacion en minutos para 1 %s: ",producto[l].nombre);
                                        scanf("%f", &producto[l].mP); 
                                    goto K;

                                    case 4:
                                    goto F;

                                    default:
                                        printf("-----------------------------------------------------\n");
                                        printf("----OPCION INVALIDA, VOLVIENDO AL MENU DE EDICION----\n");
                                    goto K;
                                }

                case 3:
                    printf("| Ingrese el ID del producto a eliminar:\n| ");
                    scanf("%d", &ld);
                    l = buscarProductoPorID(producto, maxProductos, ld);
                        if (l != -1) {
                            char confirmacion[5];
                            printf("| Para confirmar la eliminación del producto escriba 'SI', para cancelar 'NO':\n| ");
                            scanf("%s", confirmacion);
                                if (strcmp(confirmacion, "SI") == 0) {
                                    producto[l].id = -1; 
                                    printf("| Producto eliminado correctamente.\n");
                                } else {
                                    printf("| Eliminación cancelada.\n");}
                        } else {
                            printf("| ID de producto no encontrado.\n");}
                goto F;

                case 4:
                break;

                default:
                    printf("-----------------------------------------------------\n");
                    printf("----OPCION INVALIDA, VOLVIENDO AL MENU PRINCIPAL-----\n");
                goto F;
        }
}

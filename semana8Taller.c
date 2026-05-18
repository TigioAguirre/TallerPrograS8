//TALLER SEMANA 8
//AGUIRRE REMIGIO-MACÍAS ISSAC-HIDALGO MATEO
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
    getchar();//LIMPIAR EL SALTO DE LINEA /n que se genera al dar enter para el fget
        if (nR>0&&nR<=maxRecursos){
        }else{
            printf("-----------------------------------------------------\n");
            printf("----Numero de Recursos Invalido, ingrese de nuevo----\n");
            goto A;}
//DECLARACION DE RECURSOS
    for (int i = 0; i < nR; i++) {
        printf("-----------------------------------------------------\n");
        printf("| Nombre del Recurso #%d: ",i+1);
        fgets(recurso[i].nombre, 50, stdin);
        limpiarSaltoLinea(recurso[i].nombre);    
        //scanf("%s",recurso[i].nombre );
        printf("| Ingrese la unidad de medida de cantidad para 1 %s: ",recurso[i].nombre);
        fgets(recurso[i].magnitud, 50, stdin);
        limpiarSaltoLinea(recurso[i].magnitud);    
        //scanf("%s", recurso[i].magnitud);
        
    B:
        printf("| Cantidad inicial de %s: ",recurso[i].nombre);
        scanf("%f", &recurso[i].cantidad);
        getchar();//LIMPIAR EL SALTO DE LINEA /n que se genera al dar enter para el fget
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
            fgets(producto[i].nombre, 50, stdin);
            limpiarSaltoLinea(producto[i].nombre);   
            //scanf("%s", producto[i].nombre);  
        C:
            printf("| Ingrese la cantidad de Recursos que %s necesita\n",producto[i].nombre);
            printf("| MAXIMO %d Recursos: ",nR);
            scanf("%d",&cR);
            getchar();//LIMPIAR EL SALTO DE LINEA /n que se genera al dar enter para el fget
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
                    getchar();//LIMPIAR EL SALTO DE LINEA /n que se genera al dar enter para el fget
                        if ((buscarRecursoPorID(recurso,maxRecursos,producto[i].caR[j].id))!=-1){
                        }else{
                            printidRecursosInvalido();
                            goto D;};
                E:
                    printf("| Cantidad necesaria en %s de %s: ",recurso[buscarRecursoPorID(recurso,maxRecursos,producto[i].caR[j].id)].magnitud,recurso[buscarRecursoPorID(recurso,maxRecursos,producto[i].caR[j].id)].nombre);
                    scanf("%f", &producto[i].caR[j].cantidad);
                    getchar();//LIMPIAR EL SALTO DE LINEA /n que se genera al dar enter para el fget
                        if (producto[i].caR[j].cantidad>0){
                        }else{
                            printCantRecursosInvalid();
                            goto E;}
                        printf("%s necesita %.2f %s de %s\n", producto[i].nombre,producto[i].caR[j].cantidad,recurso[buscarRecursoPorID(recurso,maxRecursos,producto[i].caR[j].id)].magnitud,recurso[buscarRecursoPorID(recurso,maxRecursos,producto[i].caR[j].id)].nombre);
                    }
            printf("-----------------------------------------------------\n");
            printf("| Tiempo de fabricacion en minutos para 1 %s: ",producto[i].nombre);
            scanf("%f",&producto[i].mP);
            getchar();//LIMPIAR EL SALTO DE LINEA /n que se genera al dar enter para el fget
            producto[i].id = idRandom();
            printf("\n============== DETALLES DEL PRODUCTO %d ==============\n",i+1);
            printf("Nombre del Producto: %s\n", producto[i].nombre);
            printf("ID del Producto: %d\n", producto[i].id);
            printf("Tiempo de produccion por unidad: %.2f minutos\n", producto[i].mP);
            printf("================ RECURSOS REQUERIDOS ================\n");
                for (int j = 0; j < cR; j++) {
                    int pos = buscarRecursoPorID(recurso, nR, producto[i].caR[j].id);
                        if (pos != -1) {
                            printf("Recurso %s (ID: %d), Cantidad requerida: %.2f %s\n",recurso[pos].nombre,producto[i].caR[j].id,producto[i].caR[j].cantidad,recurso[pos].magnitud);}
                    }
            printf("=====================================================\n");
        }

//MENU DE OPCIONES
    F:
    printMenuP();
    scanf("%d",&opcion);
    getchar();//LIMPIAR EL SALTO DE LINEA /n que se genera al dar enter para el fget
    switch (opcion){
                case 1:
                    int i,id;
                    float cantRequerida,tiemRequerido,tiemTotal;
                    bool demanda;
                G:
                    printf("| Ingrese el ID del producto : \n|" );
                    scanf("%d",&id);
                    getchar();//LIMPIAR EL SALTO DE LINEA /n que se genera al dar enter para el fget
                        if (buscarProductoPorID(producto,maxProductos,id)!=-1){
                            i=buscarProductoPorID(producto,maxProductos,id);
                        }else{
                            printIdProductoInvalid();
                            goto G;}
                H:
                    printf("| Ingrese la cantidad requerida por el cliente de %s : \n",producto[i].nombre );
                    scanf("%f",&cantRequerida);
                    getchar();//LIMPIAR EL SALTO DE LINEA /n que se genera al dar enter para el fget
                        if (cantRequerida>0){
                        }else{
                            printf("-----------------------------------------------------\n");
                            printf("----Cantidad Requerida Invalida, ingrese de nuevo----\n");  
                            printf("-----------------------------------------------------\n");  
                            goto H;}
                I:
                    printf("| Ingrese el tiempo (minutos) solicitado para la entrega de %.2f %s : \n",cantRequerida,producto[i].nombre );//recurso[i].nombre, recurso[i].id
                    scanf("%f",&tiemRequerido);
                    getchar();//LIMPIAR EL SALTO DE LINEA /n que se genera al dar enter para el fget
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
                                printf("| Recurso %s (ID: %d), Cantidad requerida: %.2f %s\n| Cantidad actual de %s: %.2f %s\n",recurso[pos].nombre,producto[i].caR[j].id,producto[i].caR[j].cantidad*cantRequerida,recurso[pos].magnitud,recurso[pos].nombre,recurso[pos].cantidad,recurso[pos].magnitud);
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
                    getchar();//LIMPIAR EL SALTO DE LINEA /n que se genera al dar enter para el fget
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
                    printf("|3. EDITAR TIEMPO DE FABRICACION DE 1 %s\n",producto[l].nombre);
                    printf("|4. SALIR AL MENU PRINCIPAL\n");
                    printf("-----------------------------------------------------\n|");
                    scanf("%d",&opC2);
                    getchar();//LIMPIAR EL SALTO DE LINEA /n que se genera al dar enter para el fget
                        switch (opC2){
                                    case 1:
                                        printf("-----------------------------------------------------\n");
                                        printf("| Nuevo nombre del Producto #%d: ",l+1);
                                        fgets(producto[l].nombre, 50, stdin);
                                        limpiarSaltoLinea(producto[l].nombre);    
                                        //scanf("%s", producto[l].nombre); 
                                    goto K;

                                    case 2:
                                    L:
                                        printf("| Ingrese la cantidad de Recursos que %s necesita\n",producto[l].nombre);
                                        printf("| MAXIMO %d Recursos: ",nR);
                                        scanf("%d",&cR);
                                        getchar();//LIMPIAR EL SALTO DE LINEA /n que se genera al dar enter para el fget
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
                                                getchar();//LIMPIAR EL SALTO DE LINEA /n que se genera al dar enter para el fget
                                                    if ((buscarRecursoPorID(recurso,maxRecursos,producto[l].caR[j].id))!=-1){
                                                    }else{
                                                        printidRecursosInvalido();
                                                        goto M;};
                                            N:
                                                printf("| Cantidad necesaria de %s en %s: ",recurso[buscarRecursoPorID(recurso,maxRecursos,producto[l].caR[j].id)].nombre,recurso[buscarRecursoPorID(recurso,maxRecursos,producto[l].caR[j].id)].magnitud);
                                                scanf("%f", &producto[l].caR[j].cantidad);
                                                getchar();//LIMPIAR EL SALTO DE LINEA /n que se genera al dar enter para el fget
                                                    if (producto[l].caR[j].cantidad>0){
                                                    }else{
                                                        printCantRecursosInvalid();  
                                                        goto N;}
                                                printf("%s necesita %.2f %s de %s\n", producto[l].nombre,producto[l].caR[j].cantidad,recurso[buscarRecursoPorID(recurso,maxRecursos,producto[l].caR[j].id)].magnitud,recurso[buscarRecursoPorID(recurso,maxRecursos,producto[l].caR[j].id)].nombre);
                                            }
                                        printf("-----------------------------------------------------\n");
                                    goto K;

                                    case 3:
                                        printf("-----------------------------------------------------\n");
                                        printf("| Nuevo tiempo de Fabricacion en minutos para 1 %s: ",producto[l].nombre);
                                        scanf("%f", &producto[l].mP); 
                                        getchar();//LIMPIAR EL SALTO DE LINEA /n que se genera al dar enter para el fget
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
                    getchar();//LIMPIAR EL SALTO DE LINEA /n que se genera al dar enter para el fget
                    l = buscarProductoPorID(producto, maxProductos, ld);
                        if (l != -1) {
                            char confirmacion[5];
                            printf("| Para confirmar la eliminaciOn del producto escriba 'SI':\n| ");
                            scanf("%s", confirmacion);
                            getchar();//LIMPIAR EL SALTO DE LINEA /n que se genera al dar enter para el fget
                                if (strcmp(confirmacion, "SI") == 0) {
                                    producto[l].id = -1; 
                                    printf("| Producto eliminado correctamente.\n");
                                } else {
                                    printf("| Eliminacion cancelada.\n");}
                        } else {
                            printf("| ID de producto no encontrado.\n");}
                goto F;

                case 4:
                printf("-----------------------------------------------------\n");
                for (int id = 1000; id < 10000; id++) {
                    int idx = buscarProductoPorID(producto, maxProductos, id);
                    if (idx != -1) {
                        printf("| Producto #%d:\n", idx + 1);
                        printf("| NOMBRE: %s ID: %d\n", producto[idx].nombre, producto[idx].id);
                        printf("-----------------------------------------------------\n");}
                }
                goto F;

                case 5:
                break;

                default:
                    printf("-----------------------------------------------------\n");
                    printf("----OPCION INVALIDA, VOLVIENDO AL MENU PRINCIPAL-----\n");
                goto F;
        }
}



<?xml version="1.0" encoding="UTF-8"?>
<form xmlns="http://www.intellij.com/uidesigner/form/" version="1" bind-to-class="ec.edu.evaluacion.Ventana">
  <grid id="27dc6" binding="panel1" default-binding="true" layout-manager="GridLayoutManager" row-count="1" column-count="1" same-size-horizontally="false" same-size-vertically="false" hgap="-1" vgap="-1">
    <margin top="0" left="0" bottom="0" right="0"/>
    <constraints>
      <xy x="20" y="20" width="500" height="529"/>
    </constraints>
    <properties/>
    <border type="none"/>
    <children>
      <tabbedpane id="634f3" binding="tabbedPane1" default-binding="true">
        <constraints>
          <grid row="0" column="0" row-span="1" col-span="1" vsize-policy="3" hsize-policy="3" anchor="0" fill="3" indent="0" use-parent-layout="false">
            <preferred-size width="200" height="200"/>
          </grid>
        </constraints>
        <properties/>
        <border type="none"/>
        <children>
          <grid id="bc7f" layout-manager="GridLayoutManager" row-count="11" column-count="1" same-size-horizontally="false" same-size-vertically="false" hgap="-1" vgap="-1">
            <margin top="0" left="0" bottom="0" right="0"/>
            <constraints>
              <tabbedpane title="REGISTRO"/>
            </constraints>
            <properties/>
            <border type="none"/>
            <children>
              <component id="9591b" class="javax.swing.JLabel">
                <constraints>
                  <grid row="0" column="0" row-span="1" col-span="1" vsize-policy="0" hsize-policy="0" anchor="8" fill="0" indent="0" use-parent-layout="false"/>
                </constraints>
                <properties>
                  <text value="CARRERA"/>
                </properties>
              </component>
              <component id="be116" class="javax.swing.JComboBox" binding="comboBox1" default-binding="true">
                <constraints>
                  <grid row="1" column="0" row-span="1" col-span="1" vsize-policy="0" hsize-policy="2" anchor="8" fill="1" indent="0" use-parent-layout="false"/>
                </constraints>
                <properties>
                  <model>
                    <item value="Software"/>
                    <item value="Cyberseguridad"/>
                    <item value="Medicina"/>
                    <item value="Multimedia"/>
                  </model>
                </properties>
              </component>
              <component id="85594" class="javax.swing.JLabel">
                <constraints>
                  <grid row="2" column="0" row-span="1" col-span="1" vsize-policy="0" hsize-policy="0" anchor="8" fill="0" indent="0" use-parent-layout="false"/>
                </constraints>
                <properties>
                  <text value="Codigo"/>
                </properties>
              </component>
              <component id="b6fd" class="javax.swing.JSpinner" binding="spinner1" default-binding="true">
                <constraints>
                  <grid row="3" column="0" row-span="1" col-span="1" vsize-policy="0" hsize-policy="6" anchor="8" fill="1" indent="0" use-parent-layout="false"/>
                </constraints>
                <properties/>
              </component>
              <component id="c10ed" class="javax.swing.JLabel">
                <constraints>
                  <grid row="4" column="0" row-span="1" col-span="1" vsize-policy="0" hsize-policy="0" anchor="8" fill="0" indent="0" use-parent-layout="false"/>
                </constraints>
                <properties>
                  <text value="Nombre"/>
                </properties>
              </component>
              <component id="130cd" class="javax.swing.JLabel">
                <constraints>
                  <grid row="6" column="0" row-span="1" col-span="1" vsize-policy="0" hsize-policy="0" anchor="8" fill="0" indent="0" use-parent-layout="false"/>
                </constraints>
                <properties>
                  <text value="Promedio"/>
                </properties>
              </component>
              <component id="e0f0e" class="javax.swing.JTextField" binding="textField2" default-binding="true">
                <constraints>
                  <grid row="7" column="0" row-span="1" col-span="1" vsize-policy="0" hsize-policy="6" anchor="8" fill="1" indent="0" use-parent-layout="false">
                    <preferred-size width="150" height="-1"/>
                  </grid>
                </constraints>
                <properties/>
              </component>
              <component id="c7817" class="javax.swing.JTextField" binding="textField1" default-binding="true">
                <constraints>
                  <grid row="5" column="0" row-span="1" col-span="1" vsize-policy="0" hsize-policy="6" anchor="8" fill="1" indent="0" use-parent-layout="false">
                    <preferred-size width="150" height="-1"/>
                  </grid>
                </constraints>
                <properties/>
              </component>
              <component id="5eee6" class="javax.swing.JButton" binding="AGREGARESTUDIANTEButton" default-binding="true">
                <constraints>
                  <grid row="8" column="0" row-span="1" col-span="1" vsize-policy="0" hsize-policy="3" anchor="0" fill="1" indent="0" use-parent-layout="false"/>
                </constraints>
                <properties>
                  <text value="AGREGAR ESTUDIANTE"/>
                </properties>
              </component>
              <component id="5f397" class="javax.swing.JLabel">
                <constraints>
                  <grid row="9" column="0" row-span="1" col-span="1" vsize-policy="0" hsize-policy="0" anchor="8" fill="0" indent="0" use-parent-layout="false"/>
                </constraints>
                <properties>
                  <text value="ESTUDIANTES:"/>
                </properties>
              </component>
              <component id="591a0" class="javax.swing.JList" binding="list1" default-binding="true">
                <constraints>
                  <grid row="10" column="0" row-span="1" col-span="1" vsize-policy="6" hsize-policy="2" anchor="0" fill="3" indent="0" use-parent-layout="false">
                    <preferred-size width="150" height="50"/>
                  </grid>
                </constraints>
                <properties>
                  <model/>
                </properties>
              </component>
            </children>
          </grid>
          <grid id="735d9" layout-manager="GridLayoutManager" row-count="7" column-count="1" same-size-horizontally="false" same-size-vertically="false" hgap="-1" vgap="-1">
            <margin top="0" left="0" bottom="0" right="0"/>
            <constraints>
              <tabbedpane title="BUSQUEDA y ORDENAMIENTO"/>
            </constraints>
            <properties/>
            <border type="none"/>
            <children>
              <component id="be5ff" class="javax.swing.JTextField" binding="txtCodigo">
                <constraints>
                  <grid row="1" column="0" row-span="1" col-span="1" vsize-policy="0" hsize-policy="6" anchor="8" fill="1" indent="0" use-parent-layout="false">
                    <preferred-size width="150" height="-1"/>
                  </grid>
                </constraints>
                <properties/>
              </component>
              <component id="80792" class="javax.swing.JButton" binding="btnBuscar">
                <constraints>
                  <grid row="2" column="0" row-span="1" col-span="1" vsize-policy="0" hsize-policy="3" anchor="0" fill="1" indent="0" use-parent-layout="false"/>
                </constraints>
                <properties>
                  <text value="BUSCAR POR CODIGO"/>
                </properties>
              </component>
              <component id="c7faa" class="javax.swing.JButton" binding="btnListar">
                <constraints>
                  <grid row="3" column="0" row-span="1" col-span="1" vsize-policy="0" hsize-policy="3" anchor="0" fill="1" indent="0" use-parent-layout="false"/>
                </constraints>
                <properties>
                  <text value="BUSCAR POR NOMBRE"/>
                </properties>
              </component>
              <component id="b94d4" class="javax.swing.JLabel">
                <constraints>
                  <grid row="0" column="0" row-span="1" col-span="1" vsize-policy="0" hsize-policy="0" anchor="8" fill="0" indent="0" use-parent-layout="false"/>
                </constraints>
                <properties>
                  <text value="CODIGO"/>
                </properties>
              </component>
              <component id="c8cbb" class="javax.swing.JButton" binding="btnOrdenar">
                <constraints>
                  <grid row="4" column="0" row-span="1" col-span="1" vsize-policy="0" hsize-policy="3" anchor="0" fill="1" indent="0" use-parent-layout="false"/>
                </constraints>
                <properties>
                  <text value="ORDENAR POR PROMEDIO"/>
                </properties>
              </component>
              <component id="9e6a4" class="javax.swing.JButton" binding="ORDENARPORCODIGOASCENDENTEButton" default-binding="true">
                <constraints>
                  <grid row="5" column="0" row-span="1" col-span="1" vsize-policy="0" hsize-policy="3" anchor="0" fill="1" indent="0" use-parent-layout="false"/>
                </constraints>
                <properties>
                  <text value="ORDENAR POR CODIGO ASCENDENTE"/>
                </properties>
              </component>
              <component id="9d21b" class="javax.swing.JList" binding="list2" default-binding="true">
                <constraints>
                  <grid row="6" column="0" row-span="1" col-span="1" vsize-policy="6" hsize-policy="2" anchor="0" fill="3" indent="0" use-parent-layout="false">
                    <preferred-size width="150" height="50"/>
                  </grid>
                </constraints>
                <properties/>
              </component>
            </children>
          </grid>
          <grid id="665f6" layout-manager="GridLayoutManager" row-count="2" column-count="1" same-size-horizontally="false" same-size-vertically="false" hgap="-1" vgap="-1">
            <margin top="0" left="0" bottom="0" right="0"/>
            <constraints>
              <tabbedpane title="RECURSIVIDAD"/>
            </constraints>
            <properties/>
            <border type="none"/>
            <children>
              <component id="2217c" class="javax.swing.JLabel">
                <constraints>
                  <grid row="0" column="0" row-span="1" col-span="1" vsize-policy="0" hsize-policy="0" anchor="8" fill="0" indent="0" use-parent-layout="false"/>
                </constraints>
                <properties>
                  <text value="Total Estudiantes"/>
                </properties>
              </component>
              <component id="cadc3" class="javax.swing.JTextArea" binding="textArea1" default-binding="true">
                <constraints>
                  <grid row="1" column="0" row-span="1" col-span="1" vsize-policy="6" hsize-policy="6" anchor="0" fill="3" indent="0" use-parent-layout="false">
                    <preferred-size width="150" height="50"/>
                  </grid>
                </constraints>
                <properties/>
              </component>
            </children>
          </grid>
        </children>
      </tabbedpane>
    </children>
  </grid>
</form>





    package ec.edu.evaluacion;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class Ventana extends JFrame {
    // Declaración de los componentes "bindeados" desde el archivo .form
    private JPanel panel1;
    private JTabbedPane tabbedPane1;
    private JComboBox<String> comboBox1;
    private JSpinner spinner1;
    private JTextField textField1; // Nombre
    private JTextField textField2; // Promedio
    private JButton AGREGARESTUDIANTEButton;
    private JList<Estudiante> list1;
    
    private JTextField txtCodigo; // Actúa como entrada tanto para código como para nombre
    private JButton btnBuscar;
    private JButton btnListar; // En el form tiene el texto "BUSCAR POR NOMBRE"
    private JButton btnOrdenar;
    private JButton ORDENARPORCODIGOASCENDENTEButton;
    private JList<Estudiante> list2;
    
    private JTextArea textArea1;

    // Lógica e Integración
    private GestionEstudiantes gestion;
    private DefaultListModel<Estudiante> modeloLista1;
    private DefaultListModel<Estudiante> modeloLista2;

    public Ventana() {
        // Configuración básica de la ventana
        setContentPane(panel1);
        setTitle("Sistema de Gestión Académica - Programación III");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(700, 500);
        setLocationRelativeTo(null); // Centrar en la pantalla

        // Inicializar la lógica y los modelos de las listas
        gestion = new GestionEstudiantes();
        modeloLista1 = new DefaultListModel<>();
        modeloLista2 = new DefaultListModel<>();
        list1.setModel(modeloLista1);
        list2.setModel(modeloLista2);

        // Evitar que el spinner tenga valores negativos o nulos
        spinner1.setModel(new SpinnerNumberModel(1, 1, 99999, 1));

        // Cargar los datos precargados en la pestaña 1
        actualizarLista1();

        // ==========================================
        // EVENTOS DE LA PESTAÑA 1: REGISTRO
        // ==========================================
        AGREGARESTUDIANTEButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                agregarEstudiante();
            }
        });

        // ==========================================
        // EVENTOS DE LA PESTAÑA 2: BÚSQUEDA Y ORDENAMIENTO
        // ==========================================
        btnBuscar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                buscarPorCodigo();
            }
        });

        btnListar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                buscarPorNombre();
            }
        });

        btnOrdenar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                ordenarPorPromedio();
            }
        });

        ORDENARPORCODIGOASCENDENTEButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                ordenarPorCodigo();
            }
        });

        // ==========================================
        // EVENTOS DE LA PESTAÑA 3: RECURSIVIDAD
        // ==========================================
        // Se actualiza automáticamente cada vez que el usuario entra a la pestaña 3
        tabbedPane1.addChangeListener(e -> {
            if (tabbedPane1.getSelectedIndex() == 2) {
                actualizarRecursividad();
            }
        });
    }

    // --- MÉTODOS DE INTEGRACIÓN Y LÓGICA ---

    private void actualizarLista1() {
        modeloLista1.clear();
        // Usamos este método para obtener la lista actual y poblar el JList
        ArrayList<Estudiante> estudiantes = gestion.ordenarPorCodigoAscendente();
        for (Estudiante est : estudiantes) {
            modeloLista1.addElement(est);
        }
    }

    private void agregarEstudiante() {
        try {
            int codigo = (int) spinner1.getValue();
            String nombre = textField1.getText().trim();
            String carrera = (String) comboBox1.getSelectedItem();
            double promedio = Double.parseDouble(textField2.getText().trim());

            if (nombre.isEmpty()) {
                JOptionPane.showMessageDialog(this, "El nombre no puede estar vacío.", "Error", JOptionPane.ERROR_MESSAGE);
                return;
            }

            Estudiante nuevo = new Estudiante(codigo, nombre, carrera, promedio);
            boolean exito = gestion.agregarEstudiante(nuevo);

            if (exito) {
                JOptionPane.showMessageDialog(this, "Estudiante agregado con éxito.", "Éxito", JOptionPane.INFORMATION_MESSAGE);
                actualizarLista1();
                // Limpiar campos
                textField1.setText("");
                textField2.setText("");
            } else {
                JOptionPane.showMessageDialog(this, "El código del estudiante ya existe. Intente con otro.", "Error de Unicidad", JOptionPane.WARNING_MESSAGE);
            }
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Por favor, ingrese un promedio válido (número).", "Error de Formato", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void buscarPorCodigo() {
        try {
            int codigo = Integer.parseInt(txtCodigo.getText().trim());
            Estudiante encontrado = gestion.buscarPorCodigoBinario(codigo);
            
            modeloLista2.clear();
            if (encontrado != null) {
                modeloLista2.addElement(encontrado);
            } else {
                JOptionPane.showMessageDialog(this, "Estudiante no encontrado por código.", "Aviso", JOptionPane.INFORMATION_MESSAGE);
            }
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "El código debe ser un número entero válido.", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void buscarPorNombre() {
        String nombre = txtCodigo.getText().trim();
        if (nombre.isEmpty()) {
            JOptionPane.showMessageDialog(this, "Ingrese un nombre para buscar.", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        Estudiante encontrado = gestion.buscarPorNombreSecuencial(nombre);
        modeloLista2.clear();
        if (encontrado != null) {
            modeloLista2.addElement(encontrado);
        } else {
            JOptionPane.showMessageDialog(this, "Estudiante no encontrado por nombre.", "Aviso", JOptionPane.INFORMATION_MESSAGE);
        }
    }

    private void ordenarPorPromedio() {
        ArrayList<Estudiante> ordenados = gestion.ordenarPorPromedioDescendente();
        modeloLista2.clear();
        for (Estudiante est : ordenados) {
            modeloLista2.addElement(est);
        }
    }

    private void ordenarPorCodigo() {
        ArrayList<Estudiante> ordenados = gestion.ordenarPorCodigoAscendente();
        modeloLista2.clear();
        for (Estudiante est : ordenados) {
            modeloLista2.addElement(est);
        }
    }

    private void actualizarRecursividad() {
        int total = gestion.contarRecursivo(0);
        double promedioGral = gestion.promedioGeneralRecursivo();
        double mayorPromedio = gestion.mayorPromedioRecursivo(0);

        String reporte = "=== REPORTE RECURSIVO ===\n\n" +
                "Total de estudiantes: " + total + "\n" +
                "Promedio General (Suma Recursiva): " + String.format("%.2f", promedioGral) + "\n" +
                "Mayor Promedio Registrado: " + String.format("%.2f", mayorPromedio) + "\n";

        textArea1.setText(reporte);
    }

    // Método Main para probar la ventana directamente si lo deseas
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            Ventana v = new Ventana();
            v.setVisible(true);
        });
    }
}

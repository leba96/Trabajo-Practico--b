//2do TP Lucas Brancatelli 1er Año ICO
#include <stdio.h>
#include <stdlib.h>

int validar();
int cargar_vec(int vec[], int vec1[], int vec2[], int vec3[], int n);
void mostrar_vec(int vec[], int vec1[], int vec2[], int vec3[], int n);
int generar(int vec_o[], int n, int vec_n[], int vec_c[]);
int promedio_vec(int vec[], int n);
void mostrar2_vec(int vec[], int n);
void mayor_ventas(int vec[], int n);

int main()
{
    int dim=100, dim2;
    int clientes[dim], facturas[dim], cantidades[dim], articulos[dim];
    int vec_prom[dim];
    dim=cargar_vec(clientes,facturas,cantidades,articulos,dim);
    if(dim==0)
        printf("No se ingresaron datos");
    else
    {
        mostrar_vec(clientes,facturas,cantidades,articulos,dim);
        dim2=generar(facturas,dim,vec_prom,cantidades);
        printf("\nEl vector de las facturas mayores es:");
        mostrar2_vec(vec_prom, dim2);
    }
    return 0;
}

int validar(int lim_inf, int lim_sup, char texto[50])
{
    int numero;
    do
    {
        printf("\n%s",texto);
        scanf("%d", &numero);
    }
    while(numero<lim_inf || numero>lim_sup);
    return numero;
}
int cargar_vec(int vec_c[], int vec_f[], int vec_ca[], int vec_a[], int n)
{
    int i=0, fact_ant=0;
    do
    {
        vec_c[i]=validar(0,50,"\nIngrese numero Cliente: ");
        if(vec_c[i]!=0)
        {
            vec_f[i]=validar(fact_ant,10000,"\nIngrese factura: ");
            fact_ant=vec_f[i]++;
            vec_ca[i]=validar(1,100,"\nIngrese la cantidad: ");
            vec_a[i]=validar(1,10,"\nIngrese el articulo: ");
            i++;
        }
    }
    while(i<n && vec_c[i] !=0);
    return i;
}

void mostrar_vec(int vec_c[], int vec_f[], int vec_ca[], int vec_a[], int n)
{
    int i;
    printf("\nNro Cliente\tNro Factura\tCantidad\tCod Articulo\n");
    for(i=0; i<n; i++)
    {
        printf("%10d %10d  %10d             %10d\n", vec_c[i], vec_f[i], vec_ca[i], vec_a[i]);
    }
}

int generar(int vec_o[], int n, int vec_n[], int vec_c[])
{
    int i, promedio, j=0;
    promedio=promedio_vec(vec_c,n);
    for(i=0;i<n;i++)
    {
        if(vec_c[i]>promedio)
        {
            vec_n[j]=vec_o[i];
            j++;
        }
    }
    return j;
}

int promedio_vec(int vec[], int n)
{
    int i, acum;
    for(i=0; i<n; i++)
    {
        acum+=vec[i];
    }
    return acum/n;
}

void mostrar2_vec(int vec[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("   %d", vec[i]);//No se, por que no muestra el valor.
    }
    return;
}

void mayor_ventas(int vec[], int n)
{
    int cant_veces_vend[10]={0}, i;
    for(i=0; i<n; i++)
    {
        cant_veces_vend[vec[i]-1]++;
    }
    for(i=0; i<10; i++)
    {
        printf("El articulo %d se vendio %d veces", i+1, cant_veces_vend[i]);
    }
    int max=cant_veces_vend[0];
    for(i=1; i<10; i++)
    {
        if(cant_veces_vend[i]>max)
            max=cant_veces_vend[i];
    }
    printf("El articulo de mayor veces vendido es el: %d", max);
}

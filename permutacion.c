/*
* Programa para obtener permutaciones de una palabra ingresada por teclado y consola
* Autor: Giron Peregrina Ramon Alonso
* Github link: 
**/


#include <stdio.h>  //Biblioteca estandar de entrdas y salidas de C
#include <string.h> //Biblioteca de C para uso y manejo de String


//Funcion para cambiar valores ade los punteros
void cambiar(char *x, char *y) 
{ 
    char temp; //Creamos una variable temporal
    temp = *x; //Guardamos el valor de un puntero en la variable temporal
    *x = *y;  //Intercambiamos los valores del puntero y a x
    *y = temp; //Guardamos en el puntero y, el valor de la variable temporal que es lo que tenia el puntero x
} 


/*
* Funcion para imprimir el las permutaciones del string con 3 parametros pasados
* Priemer parametro hace referencia al string ingresado por el usuario
* segundo parametro hace referencia indice del string
* tercer parametro hace referencia al 
*/
void permutacion(char *a, int l, int r){

    //Caso base donde valor inicial del string es igual al final, funcion importante para el manejo de la logica y uso de la recursividad 
    if (l == r) 
        printf("%s\n", a); 
    else
    { 
        for (int i = l; i <= r; i++) 
        { 
            /*
            * Llamamos la funcion cambiar para la logica de del acomodo de las letras del string donde tomamos el primer valor del string
            * ejemplo tomando la palabra sol, aqui tomamos la letra a y para evaluar su posibles casos 
            */
            cambiar((a+l), (a+i)); 
            //printf("Permutacion [%d]: ",i);
            //printf("\n");
            permutacion(a, l+1, r); //Recursividad pra recorrer todos las permutaciones
            /*
            * LLamamos la funcion de cambio de valores, para este caso ya estamos evaluando la letra S del ejemplo sol
            * y hacemos un cambio con los demas valores
            * ejemplo: sol y slo, paraeste caso al ser recursiva haceun llamado hasta que se cumpla la condicion 
            */
            cambiar((a+l), (a+i));
        } 
    } 
}


/*Se define la funcion factorial*/
/*Realiza la operacion de encontrar el factorial del numero ingresado en la funcion principal*/
/*
* Dado que la formula para la permutacion es p = n!/(n-k)! en este caso,
* como al ingresar una palabra como [libro] el numero n seria igual a k, dando que la parte
* (n-k)! se igual a 0! por ende no afecta solo queda n!, opte por solo crear una funcion factorial y retornar ese valor
* como numero total de permutaciones a obtener. Eso seria una "PERMUTACION LINEAL".
*/
int factorial(int n){

    if (n == 0){ /*Comprueba que un número sea igual a 0*/
        return 1;
    }else{
        return (n*factorial(n-1)); /*Regresa el valor ingresado multiplicado por el factorial de su predecesor*/
    }
} //cierre de la funcion factorial



/*Programa principal donde llamamos a las funciones requeridas para el correcto funcionamiento del sistema*/
int main(){ 

    char str[100]; //Variable para guardar el string a ingresar tamaño de 100 caracteres
    printf("Ingresa un string: "); //Mensaje en pantalla para indicar al usuario
    scanf("%s",str); //Funcion en C para leer datos de entrada
    printf("String ingresado: %s\n",str); //Indicamos cual fue el string ingresado
    int n = strlen(str); //Funcion que retorna en entero en valor o tamaño de un string
    
    /*Condicional para evaluar que el string ingresado sea mayor a 3 caracteres
    *Caso qeu se cumpla se devuelve un mensaje en pantalla explicando el error
    *Caso contrario se llama a la funcion permutacion y pasampomos como parametro en string, inicio de la string y valor final del strig
    */
    if(n<3){
        printf("El string debe contener un minimo de 3 caracteres!\nIntentelo de nuevo por favor.....\n");
    }else{
        printf("Numero de permutaciones: %d\n",factorial(n)); //Indicamos en numero total de permutaciones a obtener
        printf("Permutaciones:\n");
        permutacion(str, 0, n-1); 
    } 
    return 0; 
} ///Cierre de la funcion principal

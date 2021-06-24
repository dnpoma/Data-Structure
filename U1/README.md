# U1
## 1. Templete
- Tipo de datos abstractos retorna un TDA

```
template <typename T>

class Operaciones{
	private: 
		T valor1;
		T valor2;
	public:
		Operaciones(T _valor1,T _valor2){
			valor1=_valor1;
			valor2=_valor2;
		}
		T resta();
		T multiplicacion();
		T suma();
		T division();
};
```
- Templetes retorna un tipo de dato primitivo
```
```

### Ejemplo:
- 	Se desde sumar, restar, multiplicar y dividir haciendo uso de templates y clases. [here](./Homework_1).

✅ Cuando se utiliza templetes es preferible dejarlo todo en el archivo .h porque genera errores en visual code.

#

## 2. Métodos sobrecargados
Es un método o función con un mismo nombre pero con diferente número de parametros.

- El constructor es un método sobrecargado.

```
int suma(int);
int suma(int,float);
float suma(float,int);

int suma(int v){
	return v*5;
}

int suma(int v,float a){
	return int(v)+a; //cating
}

float suma(float v,int a){
	return float(a)+v;
}
```

### Ejemplo:
- 	Realice 15 operadores sorecargados, utilizando TDA y referencia. [here](./Homework_2).


##

## 3. Operadores sobrecargados
Se utiliza la palabra reservada **operator** y permite definir ciertos operadores para utilizarlos.

- Sintaxis:

    tipo_dato operator operador(argumentos);


```
void operator ++(int);
int operator ++(int a){
	return a+10;
}
```


```
++(5);
```

### Ejemplo:
- 	Realice metodos sobrecargados. [here](./Homework_2M).

#

## 4. Operaciones con vectores
- Encerrar
- Ingresar
- Procesar
- Imprimir

- Enviar el vector como referencia
### Ejemplo:
- 	Realizar las operaciones básicas con vectores, los datos se deben de insertar aleatoriamente. [here](./Class_work_1).


#
## 5. Memoria dinámica

Los punteros son identificadores que almacenan direcciones de memoria de otros identifiacores.

Un identificador puede ser una variable, clase, función o un método.

Su principal característica es que ocupa un espacio de memoria.


Indirección apunta a la dirección y luego al valor.

```
// Donde 

// & dirección
// * indirección

int* p = nullptr;

int i = 5;

p = &i; 
```
#
## Recursividad
Es cuando una función se inboca así misma

- Realice el facorial. [here](./Class_work_2).
#

## 6. Operaciones con matrices 
- Segmentar
- Encerrar
- Ingresar
- Calcular
- Imprimir

### Ejemplo:
- Realice las operaciones básicas con matrices. [here](./Class_work_3).

- Realice el triángulo de pascal de forma matemática utilizando matrices con memoria dinámica. [here](./Homework_3).

#

## 7. Listas Simples
Listas con TDA. [here](./Homework_4).



#

## 8. Listas Dobles

Listas dobles con TDA. [here](./Homework_5).






#include <stdio.h>

int main()
{
	struct estructura_amigo
	{
		char nombre[30];
		char apellido[40];  
		char telefono[10]; 
		int edad;
	};	
		struct estructura_amigo amigo;	/* Declaramos la variable amigo con esa estructura */
		
		
			
			printf( "Escribe el nombre del amigo: " );  
			scanf( "%s", &amigo.nombre );
			printf( "Escribe el apellido del amigo: " ); 
			scanf( "%s", &amigo.apellido );
			printf( "Escribe el n�mero de tel�fono del amigo: " );  
			scanf( "%s", &amigo.telefono );
			printf( "Mi amigo %s %s tiene el n�mero: %s.\n", amigo.nombre, amigo.apellido, amigo.telefono );
			
	
	
	return 0;
}

#include <stdio.h> 
#include <string.h>

struct amigo
{
	int id;
	char nombre[20];  
	char dir[20];
};

int main()
{
	struct amigo record = {0}; //declarar la estructura
	
	// asignar datos a cada elemento de la estructura  record.id=1;
	strcpy(record.nombre, "Raju");
	strcpy(record.dir, "catamarca 30");
	
	// mostrar por pantalla los datos de la estructura  printf(" Id es: %d \n", record.id);
	printf(" Name es: %s \n", record.nombre); 
	printf(" Direcci�n es: %s \n", record.dir); 
	return 0;
}

#include <stdio.h>
#include <string.h>

struct agenda
{
	int id;
	char nombre[20];  char dir[20];
};

int main()
{
	int i;
	
	struct agenda record[2]; //declarar la estructura
	
	// asignar datos a cada elemento de la estructura
	record[0].id=1; 
	strcpy(record[0].nombre, "Raju"); 
	strcpy(record[0].dir, "catamarca 30");
	
	record[1].id=1;  
	strcpy(record[1].nombre, "Pepito"); 
	strcpy(record[1].dir, "Paz 350");
	
	record[2].id=1; 
	strcpy(record[2].nombre, "Silvia"); 
	strcpy(record[2].dir, "cordoba 130");
	
	for(i=0; i<3; i++)
	{
		printf("	Registro de Estudiantes : %d \n", i+1);
		printf(" Id es: %d \n", record[i].id);
		printf(" Nombre es: %s \n", record[i].nombre);  printf(" Direcci�n  es: %s \n", record[i].dir);
	}
	return 0;
}
	
#include <stdio.h> 
 #define ELEMENTOS 3 

 struct estructura_amigo
{
	char nombre[30]; 
	char apellido[40]; 
	char telefono[10]; 
	int edad;
 };

int main()
{
	struct estructura_amigo amigo[ELEMENTOS]; 
	int num_amigo;
	
	for( num_amigo=0; num_amigo<ELEMENTOS; num_amigo++ )
	{
		printf( "\nDatos del amigo n�mero %i:\n", num_amigo+1 ); 
		printf( "Nombre: " );
		gets(amigo[num_amigo].nombre); 
		printf( "Apellido: " ); 
		gets(amigo[num_amigo].apellido);  
		printf( "Tel�fono: " ); 
		gets(amigo[num_amigo].telefono); 
		printf( "Edad: " );
		scanf( "%i", &amigo[num_amigo].edad );
		
		while(getchar()!= '\n'); /* Vac�a el buffer de entrada */ }
	/* Impresi�n de los datos */
	
	for( num_amigo=0; num_amigo<ELEMENTOS; num_amigo++ )
	{
		printf( "Mi amigo %s ", amigo[num_amigo].nombre ); 
		printf( "%s tiene ", amigo[num_amigo].apellido ); 
		printf( "%i a�os ", amigo[num_amigo].edad );
		printf( "y su tel�fono es el %s.\n" , amigo[num_amigo].telefono );
	}
	return 0;
}

#include <stdio.h>  
#include <conio.h> 
# define nro 3



struct cuentas
{
	int nro_cuenta;  
	int saldo;
	
};

int main()
	
{
	struct cuentas cuen[nro]; 
	struct cuentas t[nro]; 
	int i,j;
	int total;
	
	//Carga del Arreglo Cuentas
	for(i=0;i<nro;i++)
	{
		printf("Ingrese datos Estructura: %d\n",i+1);
		
		printf("\nIngrese Nro de Cuenta\n");  
		scanf("%i",&cuen[i].nro_cuenta);
		printf("Ingrese Saldo del Cliente\n");  
		scanf("%d",&cuen[i].saldo); 
		printf("\n");
	}
	//Mostramos por pantalla los registros cargados
	
	for(i=0;i<nro;i++)
	{
		printf("Nro Cuenta= %d\n",cuen[i].nro_cuenta);
		printf("Saldo= %d\n",cuen[i].saldo);
	}
	
/*ordenar_estructura*/

	for(i = 0; i < nro; i++)
		for(j = nro-1; j >= i; j--)
		if (cuen[j].nro_cuenta > cuen[j+1].nro_cuenta) /* orden ascendente */
	{
			t[0].nro_cuenta = cuen[j].nro_cuenta;
			t[0].saldo = cuen[j].saldo;
			
			cuen[j].nro_cuenta=cuen[j+1].nro_cuenta;
			cuen[j].saldo=cuen[j+1].saldo;
			
			cuen[j+1].nro_cuenta = t[0].nro_cuenta;
			cuen[j+1].saldo = t[0].saldo;

	}//Mostramos por pantalla los registros con formato de informe
	printf("------------------------------------------------\n"); 
	printf("------------Listado de clientes -----------------\n");
	printf("------------------------------------------------\n");
	printf("-Nro Cuenta----------Saldo---------------\n");
	total=0;
	for(i=0;i<nro;i++)
	{
		printf("%d" , cuen[i].nro_cuenta);
		printf("             %d\n",cuen[i].saldo);
		total=total+cuen[i].saldo;
	}
	printf("------------------------------------------------\n");
	printf(" Total Saldo:%d\n",total);
	//Informamos por Cliente Estados de las Cuentas.  

	
	}

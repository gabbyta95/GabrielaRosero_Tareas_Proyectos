class Persona:
	nombre = ''
	apellido = ''
	cedula = 0

class Fecha:
	dia = 0
	mes = 0
	anio = 0

class Habitacion:
	numHabitacion = 0
	estadoHabitacion = False

s1 = Persona()
s2 = Fecha()
s3 = Habitacion()


def pedirNumeroEntero():

    correcto=False
    num=0
    while(not correcto):
        try:
            num = int(input("Introduce un numero entero: "))
            correcto=True
        except ValueError:
            print('Error, introduce un numero entero')

    return num

salir = False
opcion = 0

while not salir:

    print ("1. Agregar")
    print ("2. Eliminar")
    print ("3. Buscar")
    print ("4. Salir")

    print ("Elige una opcion")

    opcion = pedirNumeroEntero()

    if opcion == 1:
        print ("Agregar")
        numero = int(input("Dígame cuántos clientes tiene la lista: "))

        if numero < 1:
            print("¡Imposible!")
        else:
            lista = []
        for i in range(numero):
            s1.nombre = input("Ingrese su nombre: ")
            lista += [s1.nombre]
            s1.apellido = input("Ingrese su apellido: ")
            lista += [s1.apellido]
            s1.cedula = input("Ingrese su cedula: ")
            lista += [s1.cedula]
            print ("Ingrese fecha de entrada")
            s2.dia = int(input("Ingrese dia: "))
            lista += [s2.dia]
            s2.mes = int(input("Ingrese mes: "))
            lista += [s2.mes]
            s2.anio = int(input("Ingrese anio: "))
            lista += [s2.anio]
            print ("Ingrese fecha de salida")
            s3.dia = int(input("Ingrese dia: "))
            lista += [s3.dia]
            s3.mes = int(input("Ingrese mes: "))
            lista += [s3.mes]
            s3.anio = int(input("Ingrese anio: "))
            lista += [s3.anio]
    elif opcion == 2:
        print ("Eliminar")
        #print(nombre +" "+ apellido +" "+ cedula)
        eliminar = input("Palabra a eliminar: ")
        for i in range(len(lista)-1, -1, -1):
            if lista[i] == eliminar:
                del(lista[i])
        print("La lista es ahora:", lista)
    elif opcion == 3:
        print("Buscar")
        buscar = input("Palabra a buscar: ")
        for i in range(len(lista)-1, -1, -1):
            if lista[i] == buscar:
                print("Se encuentra en la lista.")
            print("NO esta en la lista.")
    elif opcion == 4:
        salir = True
    else:
        print ("Introduce un numero entre 1 y 3")

print ("Fin")

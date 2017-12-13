#----------------------------------------------
#UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
#INTEGRANTES:GRABRIELA ROSERO,ASTUDILLO EDWIN
#TEMA:HOTEL
#FECHA:29/11/2017
#----------------------------------------------

global lista
lista = list()

#defino los atributos de un alumno
class Alumno:
    ID=" "
    nombre=" "
    edad = " "
    NumHab = " "
    entrada = " "
    salida = " "
def registrarAlumno():
    print "------------------"
    print "Registrar Clientes"
    a = Alumno()
    
    a.nombre = raw_input("Ingrese el Nombre: ")
    a.ID = raw_input("Ingerse su Cedula: ")
    a.edad = raw_input("Ingrese su Edad: ")
    a.NumHab = raw_input("Ingrese el Numero de Habitación: ") 
    a.entrada = raw_input("Ingrese la hora de Entrada ") 
    a.salida = raw_input("Ingrese la hora de Salida ")
    
    lista.append(a)
    
def listarAlumno():
    print "----------------------"
    print "REGISTRO DE CLIENTES"
    for a in lista :
        print "-------------------------------"
        print "NOMBRE: ",a.nombre
        print "CEDULA: ",a.ID
        print "EDAD: ",a.edad
        print "N° HABITACIONES: ",a.NumHab
        print "HORA DE ENTRADA: ",a.entrada
        print "HORA DE SALIDA: ",a.salida
        print "-------------------------------"
        
        
def buscarAlumno():
    print "------------------"
    print"Buscar Clientes"

    buscar = raw_input("Ingrese el rut a buscar: ")

    #Recorrer la lista
    for a in lista :
        if a.ID == buscar:
            print "-------------------------------"
            print "NOMBRE: ",a.nombre
            print "CEDULA: ",a.ID
            print "EDAD: ",a.edad
            print "N° HABITACIONES: ",a.NumHab
            print "HORA DE ENTRADA: ",a.entrada
            print "HORA DE SALIDA: ",a.salida
            print "-------------------------------"
            break
        else: print" Dato NO Encontrado"
        
def eliminar():
    Eliminar = raw_input("Ingrese el rut a Eliminar: ")

    #Recorrer la lista
    for a in lista :
        if a.ID == Eliminar:
            del a.ID 
            del a.nombre 
            del a.edad
            del a.NumHab
            del a.entrada
            del a.salida
            print "Dato eliminado"
            break
        else: print" Dato NO Encontrado"
    
def  salir():
    print"5.-Salir"

def menu():
    op=0
    while op !=5 :
            #mostrar el menu
            print"--------------------------------------------------"
            print"\t Universidad de las Fuerzas Armadas ESPE"
            print " \t\tMOTELES GABY "
            print"1.-Registrar Cliente."
            print"2.-Listar todos los clientes."
            print"3.-Buscar un cliente."
            print"4.-Eliminar a un cliente."
            print"5.-Salir"
            print"--------------------------------------------------"
            op=input("Digite una opción ")

            if op==1:
                registrarAlumno()
            elif op==2:
                listarAlumno()
            elif op==3:
                buscarAlumno()
            elif op==4:
                eliminar()
            elif op==5:
                salir()
menu()
            

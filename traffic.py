import os
import random
import time
import threading
from threading import Thread
class Street:
    def __init__(self, identifier, name, length, topSpeed):
        self.identifier = identifier
        self.name = name
        self.length = length
        self.topSpeed = topSpeed
        self.nextStreet = []
        self.cars = []
        self.carsWhoHaveArrived = []
        self.lightStop = Lightstop(self.name)
    def navigates(self):
        for x in range(len(self.cars), 0, -1):
            if(len(self.cars) == 0):
                break;  
            for i in self.cars:
                if(self.lightStop.state == 'green' and i.position >= int(self.length) and i.hasArrived == False):
                    i.timer = i.timer + 1
                    if(self.nextStreet != []):
                        x = random.randint(0, len(self.nextStreet)-1)
                        i.position = i.position - int(self.length)
                        print("Coche: " + str(i.name) + " cruzo a " + self.name)
                        if(self.name == i.destination):
                            print("    ")
                            print("El Coche: " + str(i.name) + " Ha llegado a su destino")
                            print("    ")
                            i.hasArrived = True
                            self.carsWhoHaveArrived.append(i)
                            self.cars.remove(i)
                        else:
                            self.nextStreet[x].cars.append(i)
                            self.cars.remove(i)
                elif(self.lightStop.state == 'green' and i.position < int(self.length)):
                    i.speed = self.topSpeed
                    i.position = i.position + int(i.speed)
                    i.timer = i.timer + 1
#            time.sleep(1)
        print("Calle: "+self.name + "    Coches " + str(len(self.cars)) + " ")
        
    def checker(self):
        for i in range(0, len(self.cars)):
            self.cars[i].position = self.cars[i].position + i*4
    
        
class Lightstop:
    def __init__(self, streetName):
        self.name = streetName
        self.state = 'red'
class Car:
    def __init__(self, name, destination):
        self.name = name
        self.destination = destination
        self.hasArrived = False
        self.speed = 16
        self.position = 0
        self.carLength = 4
        self.timer = 0
        
        

streets = []
cars = []
x = True
cont = 0
n = input("Cuantas calles quieres mterw: ")
    
while(cont < int(n)):
    streetid = input("Dime el id de la calle: ")
    street = input("Dime el nombre de la calle: ")
    length = input("Dime el largo de la calle en metros: ")
    topSpeed = input("Dime La Velocidad maxima de la calle: ")
    cont = cont + 1
    streets.append(Street(streetid,street, length, topSpeed))
    os.system('clear')
    print("    ")
    
cont = 0
x = True
cont2 = 0
y = True
while(x == True):
    option = input(streets[cont2].name +" Tiene calles adyacentes? 1.SI,     2.NO: ")
    cont = 1
    y = True
    while(y == True):
        if(int(option) == 1 and len(streets) > 1):
            for i in streets:
                print(str(cont)+".-" +i.identifier)
                cont = cont + 1
                if(cont == len(streets)+1):
                    lanes = input("Cual? :")
                    l = int(lanes) - 1
                    streets[cont2].nextStreet.append(streets[l])
            y = False
        elif(int(option) == 2):
            cont2 = cont2 + 1
            y = False
    if(len(streets) == cont2):
        x = False
    

for i in range(0,10):
    x = random.randint(0, len(streets)-1)
    y = random.randint(0, len(streets)-1)
    streets[x].cars.append(Car(i, streets[y].name))    
    
for i in range(0, len(streets)):
    streets[i].checker();
    
    
    
    
cont = 0#Esto puto, es para que todos los carros recorran todos los semaforos
while(cont < 9):
    for i in streets:
        i.lightStop.state = 'green'
        Thread(target = i.navigates())
        for j in i.nextStreet:
            j.lightStop.state = 'green'
            i.lightStop.state = 'red'
            Thread(target = j.navigates())
            
    cont = cont +1
            
for i in streets:
    for j in i.carsWhoHaveArrived:
        print("Coche "+str(j.name)+" llego en "+str(j.timer) + " Segundos")
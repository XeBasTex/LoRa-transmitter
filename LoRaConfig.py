import sys
from PyQt5.QtWidgets import QMainWindow, QApplication, QPushButton, QWidget, QAction, QInputDialog,QTabWidget,QVBoxLayout,QLineEdit, QLabel
from PyQt5.QtGui import QIcon, QPixmap
from PyQt5.QtCore import pyqtSlot
from random import *
import numpy as np
import time
import queue
import serial
import os
import csv

os.chdir("C:/Users/Polo/Google Drive/ECL/PE/RN2483-Python") #remplacer le dossier de travail
 
class App(QMainWindow):
 
    def __init__(self):
        super().__init__()
        self.title = 'LoRa configuration'
        self.left = 0
        self.top = 0
        self.width = 320
        self.height = 480
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)
        
 
        self.table_widget = MyTableWidget(self)
        self.setCentralWidget(self.table_widget)
        self.statusBar().showMessage(self.table_widget.com.rcvd)
        
        self.show()
        
    
 
        
 
class MyTableWidget(QWidget):        
 
    def __init__(self, parent):   
        super(QWidget, self).__init__(parent)
        self.layout = QVBoxLayout(self)
        self.com = ComSerial() #On place l'objet COM ici !!
        
 
        # Initialize tab screen
        self.tabs = QTabWidget()
        self.tab1 = QWidget()	
        self.tab2 = QWidget()
        self.tabs.resize(320,480) 
 
        # Creation des deux onglets
        self.tabs.addTab(self.tab1,"Main")
        self.tabs.addTab(self.tab2,"Configure")
 
        # Creation de tous les boutons dans les deux onglets (Main et Configure)
        self.tab1.layout = QVBoxLayout(self)
        self.tab2.layout = QVBoxLayout(self)
        
        self.pushButtonStart = QPushButton('Start transmission')
        self.pushButtonStart.clicked.connect(self.startConf)
        
        
        self.pushButtonLoRa = QPushButton('Mode LoRa')
        self.pushButtonLoRa.clicked.connect(lambda: self.com.setMod('lora'))
        
        self.pushButtonFreq = QPushButton('freq = 868 Mhz')
        self.pushButtonFreq.clicked.connect(lambda: self.com.setFreq(868000000))
        
        self.pushButtonSF = QPushButton('Set Spreading Factor')
        self.pushButtonSF.clicked.connect(self.getSF)
        
        self.pushButtonBW = QPushButton('Set Bandwidth')
        self.pushButtonBW.clicked.connect(self.getBW)
        
        self.pushButtonPwr = QPushButton('Set Power')
        self.pushButtonPwr.clicked.connect(self.getPwr)
        
        self.pushButtonCrc = QPushButton('Set CRC')
        self.pushButtonCrc.clicked.connect(self.getCRC) 
        
        self.pushButtonPrlen = QPushButton('Set preamble length')
        self.pushButtonPrlen.clicked.connect(self.getPrlen)
        
        self.pushButtonWDT = QPushButton('Set WatchDog timer')
        self.pushButtonWDT.clicked.connect(self.getWDT)
        
        self.label = QLabel(self)
        self.pixmap = QPixmap('PE17.jpg')
        self.label.setPixmap(self.pixmap)
        self.tabs.resize(self.pixmap.width(),self.pixmap.height())
        self.tab1.layout.addWidget(self.label)
         
        
        self.tab1.layout.addWidget(self.pushButtonStart)
        self.tab1.setLayout(self.tab1.layout)
        
        self.tab2.layout.addWidget(self.pushButtonLoRa)
        self.tab2.layout.addWidget(self.pushButtonFreq)
        self.tab2.layout.addWidget(self.pushButtonSF)
        self.tab2.layout.addWidget(self.pushButtonBW)
        self.tab2.layout.addWidget(self.pushButtonPwr)
        self.tab2.layout.addWidget(self.pushButtonCrc)
        self.tab2.layout.addWidget(self.pushButtonPrlen)
        self.tab2.layout.addWidget(self.pushButtonWDT)
        self.tab2.setLayout(self.tab2.layout)
 
        # Add tabs to widget        
        self.layout.addWidget(self.tabs)
        self.setLayout(self.layout)
    
    
        
    @pyqtSlot()
            
    def getSF(self): #cree un menu deroulant avec les valeurs possibles de Spreading Factor
        items = ("7","8","9","10","11","12")
        item, okPressed = QInputDialog.getItem(self, "Set Spreading Factor","Spreading Factor:", items, 0, False)
        if okPressed and item:
            self.com.setSf(item)
            
    def getBW(self): #cree un menu deroulant pour els differentes valeurs de Bandwith possibles
        items = ("125","250","500")
        item, okPressed = QInputDialog.getItem(self, "Set Bandwidth","Bandwidth:", items, 0, False)
        if okPressed and item:
            self.com.setSf(item)
            
    def getPwr(self):#cree un menu pour choisir la puissance du signal, chiffres a la fin : Pdefaut, Pmin, Pmax
        i, okPressed = QInputDialog.getInt(self, "Set Transceiver output power","Transceiver output power:", 4, -3, 15, 1)
        if okPressed:
            self.com.setPwr(i)
            
    def getCRC(self):#Menu pour choisir le statut du Header CRC (On a priori)
        items = ("On","Off")
        item, okPressed = QInputDialog.getItem(self, "Set CRC Header","CRC Header:", items, 0, False)
        if okPressed and item:
            if item == "On":
                self.com.setCrc(True)
            else:
                self.com.setCRC(False)

    def getPrlen(self):#cree un menu pour choisir la longueur du preambule (8 par defaut)
        i, okPressed = QInputDialog.getInt(self, "Set Preamble length","Preamble length:", 8, 0, 65535, 1)
        if okPressed:
            self.com.setPrlen(i)
            
    def getWDT(self):#cree un menu pour choisir la duree du watchDog (0 par defaut)
        i, okPressed = QInputDialog.getInt(self, "Set WatchDog timer","WatchDog timer:", 0, 0, 4294967295, 1)
        if okPressed:
            self.com.setPrlen(i)
            
    def startConf(self):
        dure, okPressed = QInputDialog.getInt(self, "Nombre d'acquisitions :","Nombre:", 1200, 0, 3000, 1)
        
        fichier, okPressed = QInputDialog.getText(self, "Configuration initiale","Nom du fichier:", QLineEdit.Normal, "")
        if okPressed and fichier != '' and dure != 0:
            self.com.startReceive(fichier, dure)
            
            
    
        
 


 
class ComSerial():
     
    def __init__(self):
         
        self.__portCOM = 'COM4'
        self.__bRate = 57600
        self.__timeOut = 500
        self.__ser = serial.Serial(self.__portCOM, self.__bRate, timeout = self.__timeOut)
        self.__bool = True
        self.rcvd = ""
        self.timer = 0
         
     
    def startSerial(self):
        
        self.__ser = serial.Serial(self.__portCOM, self.__bRate, self.__timeOut)
         
   
    def stopSerial(self):
        self.__ser.close()
         
     
         
    def cmdLoRa(self, cmd):
    
        print(cmd)
        self.__ser.write(cmd.encode())
        
        print(self.__ser.readline())
         
    def setMod(self, mode): #verified
         
        if mode == 'lora' :
            self.cmdLoRa('radio set mod lora\r\n')
        elif mode == 'fsk' :
            self.cmdLoRa('radio set mod fsk\r\n')
             
    def setFreq(self, freq): #verified
        self.cmdLoRa('radio set freq '+str(freq)+'\r\n')
         
    def setSf(self, sf): #verified
        self.cmdLoRa('radio set sf sf'+str(sf)+'\r\n')
        
    def setBw(self, bw): #verified
        self.cmdLoRa('radio set bw '+str(bw)+'\r\n')
         
    def setPwr(self, pwr): #verified
        self.cmdLoRa('radio set pwr '+str(pwr)+'\r\n')
         
    def setCrc(self, crc): #verified
        if crc == True:
            self.cmdLoRa('radio set crc on\r\n')
        else:
            self.cmdLoRa('radio set crc off\r\n')
    
    def setPrlen(self, prlen): #verified
        self.cmdLoRa('radio set prlen '+str(prlen)+'\r\n')
    
    def setBitrate(self, br): #verified
        self.cmdLoRa('radio set bitrate '+str(br)+'\r\n')
        
    def setWdt(self, wdt): #verified
        self.cmdLoRa('radio set wdt '+str(wdt)+'\r\n')
         
    def startReceive(self, fichier, dure):
        self.timer = 0
        file = open(fichier,'w')
        f = csv.writer(file, delimiter = ';', lineterminator='\n')
        
        while self.timer < dure :
            self.cmdLoRa('radio rx 0\r\n')
            retour = self.__ser.readline()
            print(retour)
            f.writerow([self.timer,retour])
            self.timer += 1
        
        file.close()
        self.__ser.close()
        print("reception terminee")
    

        

app = QApplication(sys.argv)
#app.setWindowIcon(QtGui.QIcon('logo_clc.png'))
ex = App()
sys.exit(app.exec_())
    
    
    
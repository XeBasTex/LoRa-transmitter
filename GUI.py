from tkinter import ttk
from tkinter import *
from tkinter.scrolledtext import ScrolledText
from threading import *
from random import *
import numpy as np
import time
import queue
import serial
import os
import csv

class FenPrincipale(Tk):
    
    def __init__(self):
        Tk.__init__(self)
        self.title('LoRa recepteur')
        self.com = ComSerial
        
        self.nb = ttk.Notebook(self)
        mainpage = ttk.Frame(self.nb)
        setpage = ttk.Frame(self.nb)
        getpage = ttk.Frame(self.nb)
        
        self.nb.add(mainpage, text='Main')
        self.nb.add(setpage, text='Set')
        self.nb.add(getpage, text='Get')
        
        self.nb.pack(expand=1, fill="both")
        
    
        self.mainloop()


class ComSerial():
     
    def __init__(self):
         
        self.__portCOM = 'COM4'
        self.__bRate = 57600
        self.__timeOut = 500
        self.__ser = serial.Serial(self.__portCOM, self.__bRate, timeout = self.__timeOut)
        self.__bool = True
        self.__rcvd = ""
         
     
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
         
    def startReceive(self):
        while self.__bool:
            self.cmdLoRa('radio rx 0\r\n')
            self.__rcvd = self.__ser.readline()
        
        print("reception terminee")
    
    def stopReceive(self):
        self.__bool = False

        


#fen = FenPrincipale()
#fen.mainloop()
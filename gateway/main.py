import sys
import time

from Adafruit_IO import MQTTClient
from time import sleep
from hardware_connector import *
import threading
from detect_image import *

AIO_FEED_ID = ["iot-hk222.light","iot-hk222.pump"]
# AIO_USERNAME = "leanhthi"
# AIO_KEY = "aio_gnpH48euPc15Q9oSGo9XgOUve9yi"


AIO_USERNAME = "vynguyen08122002"
AIO_KEY = "aio_YFQC77B8wsKgkLbbXNj8HrHDIxPp"


def connected(client):
    print("Ket noi thanh cong ...")
    for topic in AIO_FEED_ID:
        client.subscribe(topic)

def subscribe(client , userdata , mid , granted_qos):
    print("Subscribe thanh cong ...")

def disconnected(client):
    print("Ngat ket noi ...")
    sys.exit (1)

def message(client , feed_id , payload):
    if feed_id=="iot-hk222.light":
        print(payload)
        if payload=="0":
            sendSerial("!BOF#")
            print("avb")
        elif payload=="1":
            sendSerial("!BON#")

client = MQTTClient(AIO_USERNAME , AIO_KEY)
client.on_connect = connected
client.on_disconnect = disconnected
client.on_message = message
client.on_subscribe = subscribe
client.connect()
client.loop_background()
# sleep(5)

def ReadSerial():
    while True:
        readSerial(client)

threading.Thread(target=ReadSerial).start()
counter_ai = 5
while True:


    counter_ai = counter_ai - 1
    if counter_ai <= 0:
        counter_ai = 5
        ai_result = image_detector(client)
        print(ai_result)
        client.publish("iot-hk222.ai", ai_result)
    time.sleep(1)

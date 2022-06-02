import urllib.request
import http
import time

base = "http://192.168.1.11/"


def transfer(data1):  # use to send and receive data
    try:
        n = urllib.request.urlopen(base + data1).read()
        n = n.decode("utf-8")
        return n

    except http.client.HTTPException as e:
        return e


while 1:
    transfer("1")  # Send this data
    time.sleep(1)
    transfer("0")  # Send this data
    time.sleep(1)

import urllib.request
import http
import time

url = "http://192.168.1.11/"


def transfer(data1):  # use to send and receive data
    try:
        n = urllib.request.urlopen(url + data1).read()
        n = n.decode("utf-8")
        return n

    except http.client.HTTPException as e:
        return e


# start of the code
def start():
    while True:
        command = ""
        command = input("Commands: A | B | C | D \n: ")
        transfer(command)


if __name__ == "__main__":
    start()

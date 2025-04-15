#!/usr/bin/env python3
import requests
import threading
import time

def make_request():
    while True:
        try:
            response = requests.get('http://localhost:9080/')
            print(f"Response: {response.status_code}")
        except Exception as e:
            print(f"Error: {e}")
        time.sleep(0.1)

threads = []
for _ in range(10):
    t = threading.Thread(target=make_request)
    t.daemon = True
    threads.append(t)
    t.start()

time.sleep(30)
# -*- coding: utf-8 -*-

import requests
f
import time
from bs4 import BeautifulSoup

URL = 'https://www.tapngo.com.hk/chi/apply.html#part2'

counter = 0

headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.97 Safari/537.36'}

def checker():
    page = requests.get(URL, headers=headers)
    soup = BeautifulSoup(page.content, 'html.parser')
    title = soup.find(id = 'stop_selfie_service').get_text()
    title = title.strip()
    print (title)

    if (title == '唔好意思，內容正在更新中，「拍住賞」Selfie-A-Card服務暫時停止。'):
        print ('still not available')

    elif (title != '唔好意思，內容正在更新中，「拍住賞」Selfie-A-Card服務暫時停止。'):
        print ('MAKE THE CARD!!!!!')

while (True):
    counter += 1
    print ('hour ', counter)
    checker()
    time.sleep(1)

import threading
import time
from bs4 import BeautifulSoup

urls = [
    'https://gameofthrones.fandom.com/wiki/Game_of_Thrones',
    'https://www.bbc.com/news',
]
def fetch_content(url):
    import requests
    response = requests.get(url)
    if response.status_code == 200:
        soup = BeautifulSoup(response.text, 'html.parser')
        title = soup.title.string if soup.title else 'No Title Found\n'
        print(f"Fetched from {url}:\n {title}\n")
    else:
        print(f"Failed to fetch {url}:\n Status code {response.status_code}\n")
# Without multithreading
# print("Without Multithreading:")
# t = time.time()
# for url in urls:
#     fetch_content(url)
# print(f"Time taken without multithreading: {time.time() - t} seconds\n")

# With multithreading -> reducing total time taken
print("With Multithreading:")
t = time.time()
threads = []
for url in urls:
    thread = threading.Thread(target=fetch_content, args=(url,))
    threads.append(thread)
    thread.start()
# Waiting for all threads to complete
print("Waiting for threads to complete...\n")
for thread in threads:
    thread.join()
print(f"Time taken with multithreading: {time.time() - t} seconds\n")

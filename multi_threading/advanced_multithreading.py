from concurrent.futures import ThreadPoolExecutor
import time
def printNumbers(thread_id):
    for i in range(1, 6):
        print(f"Thread {thread_id}: {i}")
        time.sleep(1)
# With advanced multithreading using ThreadPoolExecutor -> reducing total time taken to around 5 seconds
print("With Advanced Multithreading (ThreadPoolExecutor):\n")
t = time.time()
with ThreadPoolExecutor(max_workers=2) as executor:
    results = executor.map(printNumbers,[1,2])
print("Waiting for threads to complete...\n")
print(f"Time taken with advanced multithreading: {(time.time() - t):.2f} seconds\n")
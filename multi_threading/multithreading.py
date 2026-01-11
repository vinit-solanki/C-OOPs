import threading
import time

def printNumbers():
    for i in range(1, 6):
        print(i)
        time.sleep(1)
def printLetters():
    for letter in ['A', 'B', 'C', 'D', 'E']:
        print(letter)
        time.sleep(1)

# Without multithreading
# print("Without Multithreading:")
# t = time.time()
# printNumbers()
# printLetters()
# print(f"Time taken without multithreading: {time.time() - t} seconds\n")

# With multithreading -> reducing total time taken to around 5 seconds
print("With Multithreading:")
t = time.time()
thread1 = threading.Thread(target=printNumbers)
thread2 = threading.Thread(target=printLetters)
# Starting threads
thread1.start()
thread2.start()
# Waiting for both threads to complete
print("Waiting for threads to complete...")
thread1.join()
thread2.join()
print(f"Time taken with multithreading: {time.time() - t} seconds")

import multiprocessing
import time

def printNumbers():
    for i in range(1,5):
        print(i)
        time.sleep(1)
def printLetters():
    for letter in ['A', 'B', 'C', 'D', 'E']:
        print(letter)
        time.sleep(1)
# Without multiprocessing
# print("Without Multiprocessing:")
# t = time.time()
# printNumbers()
# printLetters() 
# print(f"Time taken without multiprocessing: {time.time() - t} seconds\n")

# With multiprocessing -> reducing total time taken to around 5 seconds
if __name__ == '__main__':
    print("With Multiprocessing:")
    t = time.time()
    process1 = multiprocessing.Process(target=printNumbers)
    process2 = multiprocessing.Process(target=printLetters)
    # Starting processes
    process1.start()
    process2.start()
    # Waiting for both processes to complete
    print("Waiting for processes to complete...")
    process1.join()
    process2.join()
    print(f"Time taken with multiprocessing: {time.time() - t} seconds")

import threading
import time

# Number of Philosophers
num_philosophers = 5

# Enumerate states
THINKING = 0
HUNGRY = 1
EATING = 2

# Mutex for protecting critical sections
mutex = threading.Lock()

# List to represent the state of each philosopher
state = [THINKING] * num_philosophers

# List to represent the forks (mutex for each fork)
forks = [threading.Lock() for _ in range(num_philosophers)]

# Function to simulate philosopher behavior
def philosopher(i):
    while True:
        # Philosophers think
        time.sleep(2)
        print(f"Philosopher {i} is thinking")

        # Philosopher becomes hungry
        with mutex:
            state[i] = HUNGRY
            print(f"Philosopher {i} is hungry")
            test(i)

        # Philosopher waits to get both forks
        forks[i].acquire()
        forks[(i + 1) % num_philosophers].acquire()

        # Philosopher starts eating
        with mutex:
            state[i] = EATING
            print(f"Philosopher {i} is eating")

        # Release forks when done eating
        forks[i].release()
        forks[(i + 1) % num_philosophers].release()

        # Philosopher is done eating
        with mutex:
            state[i] = THINKING
            print(f"Philosopher {i} is done eating")

# Function to check if a philosopher can start eating
def test(i):
    if (
        state[i] == HUNGRY
        and state[(i + 4) % num_philosophers] != EATING
        and state[(i + 1) % num_philosophers] != EATING
    ):
        state[i] = EATING
        forks[i].release()
        forks[(i + 1) % num_philosophers].release()

# Create philosopher threads
philosopher_threads = [threading.Thread(target=philosopher, args=(i,)) for i in range(num_philosophers)]

# Start philosopher threads
for thread in philosopher_threads:
    thread.start()

# Wait for all philosopher threads to finish
for thread in philosopher_threads:
    thread.join()

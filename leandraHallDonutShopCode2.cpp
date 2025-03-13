#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <atomic>

using namespace std;

/*

I decided to declare the variables with atomic as things got more complicated when I was using more than one
mutex in the code. Based off documentation, atomic is a more simple and efficient way of that shared data is 
accessed and modified safely by multiple threads compared to traditional locking mechanisms 

https://en.cppreference.com/w/cpp/atomic/atomic

*/

//Global variables
atomic<int> donut_count = 0;            //Number of doughnuts produced by the factory
atomic<bool> inventory_full = false;    //Flag indicating if the warehouse is full
int inventory_count = 0;                //Number of saleable boxes in the warehouse
pthread_mutex_t inventory_mutex = PTHREAD_MUTEX_INITIALIZER;   //Mutex for accessing inventory_count
/*I used one mutex function just to ensure access to the inventory_count variable is synchronized using the inventory_mutex mutex.
Only one thread can access or modify it at a time.*/

//Factory thread function
void* factory_thread(void* vp) {
    /*This thread simulates the production of doughnuts in a doughnut factory. It increments the donut_count variable to keep track of the total number of doughnuts produced
     Additionally, when 12 donutes have been produced, the factory thread increments the inventory_count variable. */
    while (1) {
        //Checks to see if inventory is not full
        if (!inventory_full) {
            pthread_mutex_lock(&inventory_mutex);
            donut_count++; //Produces a doughnut and adds it to donut_count
            cout << "F: Production in progress... Doughnut count: " << donut_count << endl;
            usleep(500000); //Introduce a delay of 0.5 seconds after producing each doughnut
            
            //Condition that executes if the number of donuts exceeds 12
            if (donut_count % 12 == 0) {
                inventory_count++; //Increment the number of boxes in inventory
                cout << "W: " << inventory_count << " boxes in inventory" << endl;
                donut_count = 0; //Resets donut_count after adding a box to inventory
                
                //Condition that executes if the number of boxes in the factory's inventory
                if (inventory_count == 10) {
                    cout << "W: Inventory full" << endl;
                }
            }
            pthread_mutex_unlock(&inventory_mutex);
        } else {
            
            //If inventory is full, wait for signal from main thread
            usleep(500000); //Sleeps for 0.5 seconds
        }
    }
    return NULL;
}


//Warehouse thread function
void* warehouse_thread(void* vp) {
    // This thread continuously monitors the inventory and updates the inventory_full flag accordingly
    while (1) {
        // Check if inventory is full
        if (inventory_count >= 10) {
            inventory_full = true; // Set inventory_full flag to true (modified by warehouse thread only)
        } else {
            inventory_full = false; // Set inventory_full flag to false (modified by warehouse thread only)
        }
        usleep(1000000); // Check inventory status every 1 second
    }
    return NULL;
}

int main() {
    pthread_t factory, warehouse;
    int factory_status, warehouse_status;

    //Creates factory thread
    factory_status = pthread_create(&factory, NULL, factory_thread, NULL);
    if (factory_status) {
        cerr << "Error creating factory thread: " << factory_status << endl;
        return 1;
    }

    //Creates warehouse thread
    warehouse_status = pthread_create(&warehouse, NULL, warehouse_thread, NULL);
    if (warehouse_status) {
        cerr << "Error creating warehouse thread: " << warehouse_status << endl;
        return 1;
    }

    //Loop that continously prompts the user to enter the number of boxes they want to purchase unless they input a negative value
    while (1) {
        int sale;
        cout << "Enter number of boxes to purchase (enter a negative number to quit): ";
        cin >> sale;
        if (sale < 0) {
            exit(0); //Exits the program if a negative number is entered
        }

        //Locks the inventory mutex so that no other thread can access or modify it while the current thread is updating its value.
        pthread_mutex_lock(&inventory_mutex);

        //Condition that executes depending on the number of boxes purchased.
        if (sale <= inventory_count) {
            cout << "S: Thank you for your business" << endl;
            inventory_count -= sale; //Decrements the inventory count (modified by sales thread)
        } else {
            cout << "S: Insufficient inventory. Please enter a new order." << endl;
        }
        pthread_mutex_unlock(&inventory_mutex);
    }

    return 0;
}
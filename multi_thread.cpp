#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>

using namespace std;

static float bearing;
static float temp;
mutex m;  
void * thread_write() {
    while(1) {
        temp++;
        m.lock();
        bearing = temp;
        cout << "bearing = " << bearing << endl;
        m.unlock();
        if(temp > 65535)
           temp  = 0;
        sleep(1);
    }
}

void thread_get() {
     float data = 0;
     while(1) {
         m.lock();
         data= bearing;
         cout << "data = " << data <<endl;
         m.unlock();
         sleep(1);
     }
}

using namespace std;
int main()
{
    thread th(thread_write);
    //th.detach();

    thread th1(thread_get);
    //th1.detach();

    cout << "jonable =" << th.joinable() << endl;
    th.join();
    th1.join();    
}

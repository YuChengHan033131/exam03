#include "mbed.h"
#include "accelerometer.h"

Thread thread1;
EventQueue queue1;
void getVelocity(){
    float x,y,z;
    accelerometer(x,y,z);
    float velocity=z*0.1;
}

int main(){
    thread1.start(callback(&queue1,&EventQueue::dispatch_forever));
    queue1.call_every(100,getVelocity)
}
#include "mbed.h"
#include "accelerometer.h"
#include "mbed_rpc.h"

Thread thread1;
EventQueue queue1;
float Vbatch[1000]=0;
int Vcount=0;
void getVelocity(){
    float x,y,z;
    accelerometer(x,y,z);
    if(Vcount<=1000)Vbatch[Vcount++]=z*0.1;
}

int main(){
    thread1.start(callback(&queue1,&EventQueue::dispatch_forever));
    queue1.call_every(100,getVelocity)
}
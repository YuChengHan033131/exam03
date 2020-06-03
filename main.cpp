#include "mbed.h"
#include "accelerometer.h"
#include "mbed_rpc.h"
#include <math.h> 

Thread thread1;
EventQueue queue1;
float Vbatch[1000]=0;//Vbatch=velocity batch
int Vcount=0;
void getVelocity(){
    float x,y,z;
    accelerometer(x,y,z);
    if(Vcount<=1000)Vbatch[Vcount++]=sqrt(x*x+y*y)*0.1;
}

void getVbatch(Arguments *in, Reply *out);
RPCFunction rpcf(&getVbatch,"getVbatch");
void getVbatch(Arguments *in, Reply *out){

}

int main(){
    thread1.start(callback(&queue1,&EventQueue::dispatch_forever));
    queue1.call_every(100,getVelocity)
}
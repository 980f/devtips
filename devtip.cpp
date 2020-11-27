#include <cortexm/systick.h>
#include "timer.h"
const Timer tim{1};//timer 1 has the full set of features.


#include "core_cmInstr.h"

#include "pinconfigurator.h"
#if 1

#define DeclSwitch(bitnum) ConfPin(E,bitnum,PinOptions::input,PinOptions::slow, PinOptions::U, 0);\
static const LogicalPin sw##bitnum({PE,bitnum},false)

#define DeclLed(bitnum) ConfPin(E,bitnum,PinOptions::output,PinOptions::slow, PinOptions::F, 0);\
static const LogicalPin led##bitnum({PE,bitnum},false)


DeclSwitch(10);
DeclSwitch(11);
DeclSwitch(12);

DeclLed(13);
DeclLed(14);
DeclLed(15);

#endif

#include "fpu.h"
InitStep(InitCore)
const FpuOptions useFpu(true,false); //loading a floating point value without having turned on the FPU causes an infinite vector through our "generate reset on fault" logic.


#pragma ide diagnostic ignored "EndlessLoop"
int main() {

  SystemTimer::startPeriodicTimer(1000);//traditional kHz wakeup.

  tim.init();
  tim.setPrescaleFor(10000);

  while(true){
    MNE(WFE);
    led13=sw10;
    led14=sw11;
    led15=sw12;
  }
}

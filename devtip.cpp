#include <cortexm/systick.h>


#include "core_cmInstr.h"
#include "pinconfigurator.h"

#if 1

#define DeclSwitch(bitnum) ConfPin(E,bitnum,PinOptions::input,PinOptions::slow, PinOptions::Up, 0);\
static const LogicalPin sw##bitnum({PE,bitnum},false)

#define DeclLed(bitnum) ConfPin(E,bitnum,PinOptions::output,PinOptions::slow, PinOptions::Float, 0);\
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

#include "timer.h"

const Timer tim {4};//timer 4 has all 4 channels on handy pins

const CCUnit ch[4] = {{tim, 1},
                      {tim, 2},
                      {tim, 3},
                      {tim, 4}};
//PD 12..15 af3
#define CHPIN(port, bitnum) ConfPin(port,bitnum,PinOptions::function,PinOptions::slow, PinOptions::Float, 2);//todo: AF codes in timer constants table.
CHPIN(D, 12)
CHPIN(D, 13)
CHPIN(D, 14)
CHPIN(D, 15)

ConfPin(D, 10, PinOptions::output, PinOptions::slow, PinOptions::Float, 0);
const LogicalPin D10 {{PD, 10}};

#pragma ide diagnostic ignored "EndlessLoop"

int main() {

  bool initit = false;
  bool confit = false;
  bool runit = false;

  SystemTimer::startPeriodicTimer(1000);//traditional kHz wakeup.

  while (true) {
    MNE(WFE);
    if (changed(initit, sw10)) {
      led13 = initit;
      if (initit) {
        tim.init();
        tim.setPrescaleFor(100000);
        tim.setCycler(200);
      }
    }
    if (changed(confit, sw11)) {
      led14 = confit;
      if (confit) {
        u8 mode = 0b1'110'0'0'00;//mode pwm
        for (unsigned chi = 4; chi-- > 0;) {
          ch[chi].setTicks(100 + 20 * chi);
          ch[chi].setmode(mode);
          ch[chi].takePin(true);
        }
      }
    }

    if (changed(runit, sw12)) {
      led15 = runit;
      tim.beRunning();
    }
  }
}

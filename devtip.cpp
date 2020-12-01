#include "systick.h"
#include "core_cmInstr.h"
#include "fpu.h"

#include "pinconfigurator.h"



InitStep(InitCore)
const FpuOptions useFpu(true, false); //loading a floating point value without having turned on the FPU causes an infinite vector through our "generate reset on fault" logic.

#include "timer.h"

const Timer tim {3};//

const CCUnit ch[4] = {{tim, 1},
                      {tim, 2},
                      {tim, 3},
                      {tim, 4}};

#define CHPIN(port, bitnum) ConfPin(port,bitnum,PinOptions::function,PinOptions::slow, PinOptions::Float, 2);//todo: AF codes in timer constants table.
CHPIN(C, 6)
CHPIN(C, 7)
CHPIN(C, 8)
CHPIN(C, 9)

#pragma ide diagnostic ignored "EndlessLoop"

int main() {

  SystemTimer::startPeriodicTimer(84000);

  tim.init();
  tim.setPrescaleFor(100000);
  tim.setCycler(200);

  u8 mode = 0b1'110'0'0'00;//mode pwm
  for (unsigned chi = 4; chi-- > 0;) {
    ch[chi].setTicks(100 + 20 * chi);
    ch[chi].setmode(mode);
    ch[chi].takePin(true);
  }

  tim.beRunning();

  while (true) {
    MNE(WFE);
  }
}

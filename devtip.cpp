

#include "timer.h"

Timer tim{1};//timer 1 has the full set of features.


#include "core_cmInstr.h"

#include "pinconfigurator.h"
#if 1
ConfPin(E,5,PinOptions::function,PinOptions::slow, PinOptions::F, 3);
ConfPin(A,3,PinOptions::function,PinOptions::fast, PinOptions::F, 4);
ConfPin(A,4,PinOptions::function,PinOptions::fastest, PinOptions::F, 5);
ConfPin(A,6,PinOptions::input,PinOptions::slow, PinOptions::U, 0);
#endif

#pragma ide diagnostic ignored "EndlessLoop"
int main() {

  PinInitializer makem;

  tim.init();
  tim.setPrescaleFor(10000);

  while(true){
    MNE(WFE);
  }
}



#include "timer.h"

Timer tim{1};


#include "core_cmInstr.h"

#include "pinconfigurator.h"

MakeObject(PinConfigurator,timeroutput,'E',5,PinOptions::function,PinOptions::slow, PinOptions::F, 3);
MakeObject(PinConfigurator,uarttx,'A',3,PinOptions::function,PinOptions::slow, PinOptions::F, 3);
ConfPin(A,4,PinOptions::function,PinOptions::slow, PinOptions::F, 3);

ConfPin(A,6,PinOptions::input,PinOptions::slow, PinOptions::U, 0);



#pragma ide diagnostic ignored "EndlessLoop"
int main() {

  PinInitializer makem;

  tim.init();
  tim.setPrescaleFor(10000);

  while(true){
    MNE(WFE);
  }
}

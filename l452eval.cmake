#no ext osc on nucleo without playing with solder bridges. This is an opportunity to learn how to trim using the LSE (hah! they have automation for it, we don't have to code a PID loop)
ADD_DEFINITIONS("-DEXT_MHz=0")
ADD_DEFINITIONS("-DLSE_kHz=32")


# project include paths, separate lines for each git repo to make maintenance a smidgeon easier
INCLUDE_DIRECTORIES(".")
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/cortexm ${PROJECT_SOURCE_DIR}/cortexm/stm32)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/safely/cppext)

LIST(APPEND SOURCES
  cortexm/stm32/timer.cpp cortexm/stm32/timer.h
  cortexm/stm32/stm32.cpp cortexm/stm32/stm32.h
  cortexm/stm32/gpiof4.cpp cortexm/stm32/gpiof4.h cortexm/stm32/gpio.h
  cortexm/stm32/pinconfigurator.cpp
  cortexm/stm32/clocksl4.cpp
  #cortexm/stm32/flashf4.cpp

  #cortexm/stm32/gpiof1.cpp cortexm/stm32/gpiof1.h cortexm/stm32/gpio.h
  #cortexm/stm32/irqnums.h
  )

LIST(APPEND SOURCES
  #cortexm/core_cmfunc.cpp
  #cortexm/fpu.cpp
  #cortexm/systick.cpp
  #cortexm/nvic.cpp nvicTable.inc
  #cortexm/cortexm3.s
  )

LIST(APPEND SOURCES
  ${PROJECT_NAME}.cpp
  #safely/cppext/minimath.cpp
  )


/* first include your processor's MEMORY layout stuff.*/
INCLUDE cortexm/stm32/l452re.ld

STACKINCCM = 1 ;  /* If STACKINCCM is defined then stack goes there and you must remember that DMA can't access that memory (this might be false for L452). The value does not matter, use comments to control this. */

/* Rowley builder likes to reference stuff that never actually gets referenced, we dummy those to map to an actual function that does nothing. Sometimes they go away on their own and we comment them back out.  */
/* __do_debug_operation = do_nothing ; /* */
/* __vfprintf = do_nothing ; /* */
/* __vfscanf = do_nothing ; /* */
/* __vfprintf = do_nothing ; /* */
/* __vfscanf = do_nothing ; /* */
/*  printf = do_nothing ;  /* */
/* __putchar = do_nothing ;  /* ref'ed by vfprintf */
/* __aeabi_errno_addr = do_nothing ;  /* */
/*__aeabi_read_tp = do_nothing ; /* */

 __cxa_pure_virtual = do_nothing; /* appears when you exclude std libs: -nostdlib */
 /* abort = do_nothing ; /* __cxa_pure_virtual from std lib */
/* __dso_handle = do_nothing ; /* try commenting out once you have hunted down unexpected visitors in the link map */
/* end = 0 ;/* used by _sbrk, which should not be getting called */


/* then the generic "flash only" stuff, which presently is tightly tied into cstartup.cpp */
INCLUDE cortexm/cortexm.ld

/* INCLUDE cortexm/ccmfast.ld  /** build descriptor for vectors into ram  */


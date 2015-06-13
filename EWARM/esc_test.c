#define LOOP_DELAY 27134
void usDelay( void )
{
   for (int i = 0; i < LOOP_DELAY; i++)
   {
   }
}


void msDelay( int ms )
{
   for (int i = 0; i < 1000*ms; i++)
   {
      usDelay();
   }
}


int test(void)
{
  while(1) {
    
    
  }
}
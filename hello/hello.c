#define UART_BASE       0xF0001000
#define UART_OFF_RXTX   0x00
#define UART_OFF_TXFULL 0x04

#define LB(base, off)       (*((char volatile *)(base + off)))
#define SB(base, off, byte) (*((char volatile *)(base + off)) = byte)

void putchr(char c) {
  while (LB(UART_BASE, UART_OFF_TXFULL))
    ;
  SB(UART_BASE, UART_OFF_RXTX, c);
}

int main() {
  const char str[14] = "Hello World!\n";

  for (int i = 0; i < 14; i++)
    putchr(str[i]);

  return 0;
}
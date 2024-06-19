#define UART_BASE        0xF0001000
#define UART_OFF_RXTX    0x00
#define UART_OFF_TXFULL  0x04
#define UART_OFF_RXEMPTY 0x08
#define UART_OFF_EVPEND  0x10

#define UART_TX 0x01
#define UART_RX 0x10

#define LB(base, off)       (*((char volatile *)(base + off)))
#define SB(base, off, byte) (*((char volatile *)(base + off)) = byte)

void putchr(char c) {
  while (LB(UART_BASE, UART_OFF_TXFULL))
    ;
  SB(UART_BASE, UART_OFF_RXTX, c);
}

char readchr() {
  while (LB(UART_BASE, UART_OFF_RXEMPTY))
    ;

  char byte = LB(UART_BASE, UART_OFF_RXTX);
  
  /* Clearing Pending Bit Pops Character off Rx Queue */
  SB(UART_BASE, UART_OFF_EVPEND, ~UART_RX);

  return byte;
}

void printstr(char *str, int len) {
  for (int i = 0; i < len; i++)
    putchr(str[i]);
}

int main() {
  char str1[] = "Input Name: ";
  char buff[100] = "Hello ";

  printstr(str1, 12);

  int len = 6;
  while ((buff[len] = readchr()) != '\n') {
    putchr(buff[len]);
    len++;
  }

  putchr('\r');
  putchr('\n');

  printstr(buff, len);
  return 0;
}
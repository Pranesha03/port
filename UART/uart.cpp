#include <lpc214x.h> 
class UART { 
public: 
// Constructor to initialize UART0 
UART() { 
// Configure the UART0 pins for TXD and RXD (P0.0 and P0.1) 
PINSEL0 |= 0x05;  // Set P0.0 as TXD and P0.1 as RXD 
// Configure UART0 settings 
U0LCR = 0x83;  // 8-bit data, 1 stop bit, no parity, enable DLAB 
U0DLL = 97;    // Baud rate 9600 (assuming PCLK = 15 MHz) 
U0LCR = 0x03;  // Disable DLAB, normal operation 
} 
// Function to send a character via UART0 
void sendChar(char ch) { 
while (!(U0LSR & 0x20));  // Wait for the Transmitter Holding Register (THR) to be empty 
U0THR = ch;  // Transmit the character 
} 
}; 
int main() { 
UART uart;  // Create an object of the UART class 
while (1) { 
uart.sendChar('M');  // Send 'H' through UART0 
} 
return 0; 
}

#include <lpc214x.h> // Include LPC214x library for hardware access
class SevenSegmentDisplay {
	public:
		SevenSegmentDisplay() { // Set IO0 pins as output for controlling the 7-segment display
		IO0DIR |= 0xFF; // Set lower 8 bits of IO0DIR as output (for 7-segment display)
		}
		void displayDigit(int digit) { // Array holding the segment codes for digits 0 to 9
			unsigned char segmentCodes[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F,
			0x6F};

			if (digit >= 0 && digit <= 9) {

			IO0SET = segmentCodes[digit]; // Set the corresponding segment code
			}
		}
		void clearDisplay(int digit) {
			unsigned char segmentCodes[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F,
			0x6F};
			if (digit >= 0 && digit <= 9) {
			IO0CLR = segmentCodes[digit]; // Clear the corresponding segment code
			}
			}
			void delay(int k) { // Simple software delay (not precise, could be improved with timers)
			for (int i = 0; i < k; i++) {
			for (int j = 0; j < 1000; j++) { // Empty loop to create delay
			}
		}
	}
};
int main() {
	SevenSegmentDisplay display;
	while (true) {
		for (int i = 0; i <= 9; i++) {
			display.displayDigit(i); // Display the current digit
			display.delay(1000); // Delay to allow the display to be visible
			display.clearDisplay(i); // Clear the digit
		}
	}
	return 0;
}

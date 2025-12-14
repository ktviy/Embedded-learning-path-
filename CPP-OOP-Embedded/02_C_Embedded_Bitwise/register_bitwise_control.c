#include <iostream>

unsigned char control_register = 0b00000000;

// Define bit masks for specific pins
// << operator is a left bitwise shift.
// bit 0 (or decimal 1) is the original value 00000001. 
// To declare another bit, we shift the 1 to the left by the number of bits we want to move.
#define led_pin (1 << 0) // Bit 0
#define mode_pin (1 << 3) // Bit 3 
#define error_pin (1 << 6) // Bit 6

void print_register_state(const char* action){
    printf("%-25s: 0x%02X (0b", action, control_register);
    for (int i = 7; i >= 0; i--){
        printf("%d", (control_register >> i) & 1); // Check and print each bit 
    } 
    printf(")\n");
}

int main(){
    print_register_state("Initial state");

    // Set LED pin high
    control_register |= led_pin;
    print_register_state("Set LED pin high");

    // Set Mode pin high
    control_register |= mode_pin;
    print_register_state("Set Mode pin high");

    // Clear LED pin
    control_register &= ~led_pin;
    print_register_state("Clear LED pin");

    // Toggle Error pin
    control_register ^= error_pin;
    print_register_state("Toggle Error pin");

    if (control_register & mode_pin){
        std::cout << "Mode pin is HIGH" << std::endl;
    } else {
        std::cout << "Mode pin is LOW" << std::endl;
    }

    return 0;

}

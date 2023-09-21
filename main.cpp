/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "Hotboards_keypad.h"

UnbufferedSerial pc(USBTX, USBRX, 9600);


char teclado4X4[ 4 ][ 4 ] = {
    { '1' , '2' , '3' , 'A' },
    { '4' , '5' , '6' , 'B' },
    { '7' , '8' , '9' , 'C' },
    { '*' , '0' , '#' , 'D' }
};
char teclado4X3[ 4 ][ 3 ] = {
    { '1' , '2' , '3' },
    { '4' , '5' , '6' },
    { '7' , '8' , '9' },
    { '*' , '0' , '#' }
};

DigitalInOut rowPins[ 4 ] = { D2 , D3 , D4 , D5 };
DigitalInOut colPins[ 4 ] = { D6 , D7 , D8 , D9 };

// Teclado 4X4
Keypad kpd4X4( makeKeymap( teclado4X4 ) , rowPins , colPins , 4 , 4 );

// Teclado 4X3
Keypad kpd4X3( makeKeymap( teclado4X3 ) , rowPins , colPins , 4 , 3 );


int main() {
    printf( "Press any key: \n" );
    
    while(true) {
        char key = kpd4X4.getKey( );
        
        if(key) printf("%c", key);
    }
}

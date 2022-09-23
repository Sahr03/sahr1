//********************************************************************
//
// simplesim.cpp
// CSCI 241 Assignment 4
//
// Created by your-name (z1930087)
//
//********************************************************************

#include <iostream>
#include <iomanip>
#include "simplesim.h"
#include "sml.h"

using std::cin;
using std::cout;
using std::endl;
using std::internal;
using std::left;
using std::noshowpos;
using std::right;
using std::setfill;
using std::setw;
using std::showpos;

/**
 * Initializes the Simplesim's memory to default values.
 */
simplesim::simplesim()
{
    
    accumulator = 0;
    instruction_counter = 0;
    instruction_register = 0;
    operation_code = 0;
    operand = 0;
    int i;

   for( i = 0; i < 100; i++)
        memory[i] = DEFAULT;

}

/**
 * Loads an SML program into the Simplesim's memory.
 *
 * @return Returns true if a valid program is successfully loaded into 
 *         memory; otherwise, false.
 */
bool simplesim::load_program()
{
    int count = 0;
    int instruction = 0;

    while (cin >> instruction && instruction != -99999)
    {
        // Check for invalid word.
        if(instruction < -9999 || instruction > 9999)
        {
            cout << "*** ABEND: pgm load: invalid word ***" << endl;
        }
        // Check for too large program.
        if(instruction < -9999 || instruction > 9999)
        {
            cout << "*** ABEND: pgm load: pgm too large ***" << endl;
        }
        // Add instruction to memory.
        memory[count] = instruction; 
        // Increment instruction count.
        count++;
	}

    return true;
}

/**
 * Executes an SML program loaded into the Simplesim's memory.
 */
void simplesim::execute_program()
{
    bool done = false;

    while (!done)
    {
        // Check for addressability error.
        

        // Fetch instruction.
        instruction_register = memory[instruction_counter];
		operation_code = instruction_register / 100;
		operand = instruction_register % 100;
		
        // Execute instruction.
		switch (operation_code)
		{
            
        case READ:

            break;

        case WRITE:

            break;

        case STORE:

            break;

        case LOAD:
        
            break;

        case ADD:

            break;

        case SUBTRACT:
            break;

        case MULTIPLY:
            break; 
        
        case DIVIDE:
            break;

        case BRANCH:
            break;

        case BRANCHZERO:
            break;

        case BRANCHNEG:
            break;

        case HALT: 
            done = true;
            break;
        
        default:
            cout << "*** ABEND: invalid opcode ***" << endl;
            return;
        }
    
		// Increment instruction counter if needed.
    }
    
    // Print successful termination message.
	cout << "*** Simplesim execution terminated ***" << endl;

}

/**
 * Prints the contents of the Simplesim's registers and memory.
 */
void simplesim::dump() const
{
    int i;

    cout << "REGISTERS: " << endl; 
    cout << "Accumulator: " << showpos << setw(16) << accumulator << endl;
    cout << "instruction_counter: " << noshowpos << setw(5) << instruction_counter << endl;
    cout << "instruction_register: " << showpos << setw(7) << instruction_register << endl;
    cout << "operational_code: " << noshowpos << setw(8) << operation_code << endl;
    cout << "operand: " << noshowpos << setw(17) << operand << endl; 
   

    for (i = 0; i < 100; i++)
        cout << memory[i] << endl;


    
}

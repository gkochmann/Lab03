/* 
 * File:   main.cpp
 * Author: Grant Kochmann and Maxwell Evans
 *
 * Created on January 27, 2018, 2:05 PM
 */

#include <cstdlib>
#include "PageFrameAllocator.h"

/*
 * 
 */
int main(int argc, char** argv) {
    // Check for argument
    if (argc != 2) {
        cerr << "Argument not specified." << endl;
        exit(1);
    }
    
    fstream inFile;
    string fileName = argv[1];
    inFile.open(fileName);
    if (inFile.fail()) { // Exit program if it can't open file
        cerr << "ERROR: Cannot open text file: " << fileName << endl;
        exit(2);
    }
    
    int numPageFrames;
    inFile >> std::hex >> numPageFrames;
    PageFrameAllocator *pageFrameAl = new PageFrameAllocator(numPageFrames);
    
    int tempNum, count;
    std::vector<uint32_t> allocated;
    while (inFile >> tempNum) {
        if (tempNum == 0) {
            inFile >> count;
            pageFrameAl->Deallocate(count, allocated);
        }
        else if (tempNum == 1) {
            inFile >> count;
            pageFrameAl->Allocate(count, allocated);
        }
        else if (tempNum == 2) {
            // Print contents of the free list
        }
        else {
            // Default
            cout << "Impossible input." << endl;
        }
    }
    
    return 0;
}


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
    
    ofstream outFile("outputtest.txt");
    int numPageFrames;
    inFile >> std::hex >> numPageFrames;
    outFile << std::hex << ">" << numPageFrames << endl;
    PageFrameAllocator *pageFrameAl = new PageFrameAllocator(numPageFrames);
    
    int tempNum, count;
    std::vector<uint32_t> allocated;
    if (outFile.is_open()) {
        while (inFile >> tempNum) {
            outFile << std::hex << ">" << tempNum << " ";
            if (tempNum == 0) {
                inFile >> count;
                outFile << count << endl;
                bool check = pageFrameAl->Deallocate(count, allocated);
                if (check)
                    outFile << " T " << pageFrameAl->getPageFramesFree() << endl;
                else
                    outFile << " F " << pageFrameAl->getPageFramesFree() << endl;
            }
            else if (tempNum == 1) {
                inFile >> count;
                outFile << count << endl;
                bool check = pageFrameAl->Allocate(count, allocated);
                if (check)
                    outFile << " T " << pageFrameAl->getPageFramesFree() << endl;
                else
                    outFile << " F " << pageFrameAl->getPageFramesFree() << endl;
            }
            else if (tempNum == 2) {
                outFile << endl;
                for (int i = 0; i < pageFrameAl->getPageFramesFree(); i++) {
                    outFile << " " << i;
                }
                outFile << endl;
            }
            else {
                // Default
                cout << "Impossible input." << endl;
            }
        }
    } else {
        cout << "outFile not open." << endl;
    }
    outFile.close();
    
    return 0;
}


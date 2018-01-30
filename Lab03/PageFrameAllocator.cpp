/* 
 * File:   PageFrameAllocator.cpp
 * Authors: Grant Kochmann and Maxwell Evans
 * 
 * Created on January 27, 2018, 2:15 PM
 */

#include <vector>
#include "PageFrameAllocator.h"

PageFrameAllocator::PageFrameAllocator(int numPageFrames) {
    int totalSize = numPageFrames * 0x1000;
    memory.resize(totalSize, 0); //Resizes memory
    
    freeListHead = 0xFFFFFFFF; // The page frame number of the first page frame in the free list (0xFFFFFFFF if list empty)
    uint32_t index, v32;
    for (int i = 0; i < numPageFrames; i++) { // Build free list
        freeListHead = 0;
        index = i*0x1000;
        v32 = i+1;
        if (i == numPageFrames-1) {
            v32 = 0xFFFFFFFF; // Last element of the list so 0xFFFFFFFF
        }
        memcpy(&memory[index], &v32, sizeof(uint32_t));
    }
    
    pageFramesFree = numPageFrames;  
    pageFramesTotal = numPageFrames;
}

bool PageFrameAllocator::Allocate(uint32_t count, std::vector<uint32_t> &page_frames) {
    
}

bool PageFrameAllocator::Deallocate(uint32_t count, std::vector<uint32_t> &page_frames) {
    
}

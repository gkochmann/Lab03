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
    PageFrameAllocator::memory.resize(totalSize); //Resizes memory
    
    PageFrameAllocator::freeListHead = 0xFFFFFFFF //Building free list
    PageFrameAllocator::pageFramesFree = totalSize;  
    PageFrameAllocator::pageFramesTotal = totalSize;
}

PageFrameAllocator::PageFrameAllocator(const PageFrameAllocator& orig) {
}

PageFrameAllocator::~PageFrameAllocator() {
    
}


/* 
 * File:   PageFrameAllocator.h
 * Authors: Grant Kochmann and Maxwell Evans
 *
 * Created on January 27, 2018, 2:15 PM
 */

#ifndef PAGEFRAMEALLOCATOR_H
#define PAGEFRAMEALLOCATOR_H

class PageFrameAllocator {
public:
    PageFrameAllocator(int numPageFrames);
    
    PageFrameAllocator(const PageFrameAllocator& orig) = delete; // Class does not allow copy/move constructors/assignments
    PageFrameAllocator(PageFrameAllocator&& other) = delete;
    PageFrameAllocator& operator=(const PageFrameAllocator& orig) = delete;
    PageFrameAllocator& operator=(PageFrameAllocator&& orig) = delete;
private:
    std::vector<uint8_t> memory; //Byte array that contains page frames to be managed
    uint32_t page_frames_total; //A count of the total number of page frames in memory (memory size divided by 0x1000)
    uint32_t page_frames_free; //The current number of free page frames
    uint32_t free_list_head; //The page frame number of the first page frame in the free list (0xFFFFFFFF if list empty)

};

#endif /* PAGEFRAMEALLOCATOR_H */


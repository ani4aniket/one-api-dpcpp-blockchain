//==============================================================
// Copyright © 2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
// =============================================================
#include<CL/sycl.hpp>
#include<iostream>

#include "Blockchain.h"

using namespace std;
using namespace sycl;



int main()
{
     auto start_time = std::chrono::high_resolution_clock::now();
     
    //select device to perform operations with  we selected cpu_selector
    
     queue q(cpu_selector{});
    
    
//   queue q(gpu_selector{});
 
    
    std::cout << "Device: " << q.get_device().get_info<info::device::name>() << std::endl;
    
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    
        Blockchain bChain = Blockchain(q);

        std::cout << "Mining block 1..." << std::endl;
        bChain.AddBlock(q, Block(q, 1, "Block 1 Data"));

        std::cout << "Mining block 2..." << std::endl;
        bChain.AddBlock(q, Block(q, 2, "Block 2 Data"));

        std::cout << "Mining block 3..." << std::endl;
        bChain.AddBlock(q, Block(q, 3, "Block 3 Data"));

    return 0;
}

cmake_minimum_required(VERSION 3.15)
project(labprog)

set(CMAKE_CXX_STANDARD 14)

add_executable(labprog main.cpp
        BankAccount.cpp BankAccount.h
        ATM.cpp ATM.h
        Credit.cpp Credit.h
        BankTransfer.cpp BankTransfer.h)
#pragma once
#ifndef UART_HPP
#define UART_HPP

#include <random>
#include <algorithm>
#include <ctime>
#include <vector>
#include "simulation/typedefs.hpp"



namespace uc {

class uart {
    private: 
        uc::buffer_size_t _buffer_size;
        uc::baud_rate_t _baud_rate;
        buffer_t _rx_buffer;
        buffer_t _tx_buffer;
        void *_receive_callback(uint8_t*);
        void *_transmit_complete_callback(uc::buffer_size_t);

        void sim_update(timestep_t dt) { 
            // This is what will take care of setting the actual pin-state
        }

    public:
        uart(uc::buffer_size_t rx_buffer_size, uc::buffer_size_t tx_buffer_size, uc::baud_rate_t baud_rate) : 
            _baud_rate{baud_rate},
            _rx_buffer{rx_buffer_size, 0},
            _tx_buffer{tx_buffer_size, 0},
            _receive_callback{nullptr},
            _transmit_complete_callback{nullptr}
        {
            // Initialize the uart with an empty receive buffer, then fill it with random numbers so the user has to clear the buffer (just like in real life!)
            std::srand(unsigned(std::time(nullptr)));
            std::generate(_rx_buffer.begin(), _tx_buffer.end(), std::rand);
        }


        void clear() {
            // Clears the uart buffer
            std::fill(_rx_buffer.begin(), _rx_buffer.end(), 0);
        }

        uc::buffer_size_t send(void *buffer, uc::buffer_size_t bytes) {
            // Send with a void pointer buffer (interpret as raw bytes)
            std::copy(static_cast<uint8_t*>(buffer), std::min(bytes, _tx_buffer.size()), _tx_buffer.begin());
        }

        void attach_receive(void(byte_t*) *callback) {
            _receive_callback = callback;
        }

        void detach_receive() {
            _receive_callback = nullptr;
        }

        void attach_transmit_complete(void(uc::buffer_size_t) *callback) {
            _transmit_complete_callback = callback;
        }

        void detach_transmit_complete() {
            _transmit_complete_callback = nullptr;
        }

};

}

#endif
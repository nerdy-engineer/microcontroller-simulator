#pragma once
#ifndef UART_HPP
#define UART_HPP

#include <random>
#include <algorithm>
#include <ctime>
#include <vector>
#include <functional>
#include "simulation/typedefs.hpp"
#include "simulation/components/peripheral.hpp"



namespace uc {

class uart : public uc::peripheral{
    private: 
        uc::buffer_size_t buffer_size_;
        uc::baud_rate_t baud_rate_;
        buffer_t rx_buffer_;
        buffer_t tx_buffer_;
        std::function<void(uint8_t*)> receive_callback_;
        std::function<void(uc::buffer_size_t)> transmit_complete_callback_;

        void sim_update(timestep_t dt) override { 
            // This is what will take care of setting the actual pin-state
        }

    public:
        uart(const std::string& name, uc::pin& tx_pin, uc::pin& rx_pin, uc::buffer_size_t rx_buffer_size, uc::buffer_size_t tx_buffer_size, uc::baud_rate_t baud_rate) : 
            uc::peripheral{name},
            baud_rate_{baud_rate},
            receive_callback_{nullptr},
            transmit_complete_callback_{nullptr}
        {
            add_pin("tx", tx_pin);
            add_pin("rx", rx_pin);

            rx_buffer_ = buffer_t(rx_buffer_size, 0);
            tx_buffer_ = buffer_t(tx_buffer_size, 0);
            
            // Initialize the uart with an empty receive buffer, then fill it with random numbers so the user has to clear the buffer (just like in real life!)
            std::srand(unsigned(std::time(nullptr)));
            std::generate(rx_buffer_.begin(), tx_buffer_.end(), std::rand);
        }


        void clear() {
            // Clears the uart buffer
            std::fill(rx_buffer_.begin(), rx_buffer_.end(), 0);
        }

        uc::buffer_size_t send(uint8_t *buffer, uc::buffer_size_t bytes) {
            // Send with a void pointer buffer (interpret as raw bytes)
            std::copy(buffer, buffer + std::min(bytes, tx_buffer_.size()), tx_buffer_.begin());
        }

        void attach_receive(std::function<void(uint8_t*)> callback) {
            receive_callback_ = callback;
        }

        void detach_receive() {
            receive_callback_ = nullptr;
        }

        void attach_transmit_complete(std::function<void(uc::buffer_size_t)> callback) {
            transmit_complete_callback_ = callback;
        }

        void detach_transmit_complete() {
            transmit_complete_callback_ = nullptr;
        }

};




}

#endif
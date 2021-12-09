#include "simulation/simworld.hpp"



using namespace uc;


class example_task : public task {
    private:
    pin& A1;

    public:
    example_task(const std::string& name, uc::microcontroller* micro) :
    task(name, micro),
    A1{micro->pin("A1")}
    {

    }

    void execute() override {
        while (run_signal()) {
            digitalWrite(A1, true);
            sleep(500);
            digitalWrite(A1, false);
            sleep(500);
        }
    }
};




int main() {

    // configure microcontroller
    auto stm32 = microcontroller();
    stm32.add_pin("PA1");

    example_task main_task("main", &stm32);
    stm32.add_task(main_task);


    std::vector<microcontroller&> microcontrollers;
    microcontrollers.push_back(stm32);
    auto sim = simulator(microcontrollers, pulse_t(1e-9));


}

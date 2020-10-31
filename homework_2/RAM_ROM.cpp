#include "RAM_ROM.hpp"

int main(int argc, char* argv[])
{
    J::RAM _ram_one(256, J::DDR1, 3);
    J::RAM _ram_two(128, J::DDR2, 3);
    _ram_two.set_same_settings(_ram_one);
    std::cout << _ram_two.get_main_frequency() << std::endl;

    J::CDROM _cdrom_one(4, J::SATA, "normal");
    J::CDROM _cdrom_two(2, J::SATA, "normal");
    if(_cdrom_one.is_same_settings(_cdrom_two))
    {
        std::cout << "Same settings CDROMs" << std::endl;
    }
    else
    {
        std::cout << "Not the same" << std::endl;
    }
    

    return 0;
}
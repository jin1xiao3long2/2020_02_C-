#include <iostream>
#include <string>

namespace J{

    enum RAM_type{DDR1, DDR2, SDRAM, FLASHRAM};
    enum CDROM_type{SATA, USB, IDE};

    class RAM final{

    using Type = RAM_type;

    private:
        
        int _capacity = 8;   //Mb
        Type _type = DDR1;    
        int _main_frequency = 3; //gHz
        
    public:

        RAM() = delete;
        RAM(int cap, enum RAM_type t, int m_f): _capacity(cap), _type(t), _main_frequency(m_f){};
        ~RAM() = default;
        RAM(const RAM&) = delete;
        RAM operator=(const RAM&) = delete;

    public:
        bool is_same_settings(const RAM &ram) const
        {
            if(this == &ram)
                return true;
            if(this->_capacity != ram._capacity)
                return false;
            if(this->_main_frequency != ram._main_frequency)
                return false;
            if(this->_type != ram._type)
                return false;
            return true;
        }

        void set_same_settings(const RAM &ram)
        {
            this->_capacity = ram._capacity;
            this->_main_frequency = ram._main_frequency;
            this->_type = ram._type;
        }
        int get_capacity() const
        {
            return this->_capacity;
        }
        enum RAM_type get_type() const
        {
            return this->_type;
        }
        int get_main_frequency() const
        {
            return this->_main_frequency;
        }
    };

    class CDROM final{
    using Type = CDROM_type;
    private:

        int _capacity = 8; //MB
        Type _type = SATA;
        std::string _setting_way;

    public:
        CDROM() = delete;
        CDROM(int cap, enum CDROM_type c_t, std::string s_w): _capacity(cap), _type(c_t), _setting_way(s_w){};
        CDROM(const CDROM &) = delete;
        ~CDROM() = default;
        CDROM operator=(const CDROM &) = delete;

    public:
        bool is_same_settings(const CDROM &cd) const
        {
            if(this == &cd)
                return true;
            if(this->_capacity != cd._capacity)
                return false;
            if(this->_setting_way != cd._setting_way)
                return false;
            if(this->_type != cd._type)
                return false;
            return true;
        } 
        void set_same_settings(const CDROM &cd)
        {
            this->_capacity = cd._capacity;
            this->_setting_way = cd._setting_way;
            this->_type = cd._type;
        }
        int get_capacity() const
        {
            return this->_capacity;
        }
        enum CDROM_type get_type() const
        {
            return this->_type;
        }
        std::string get_setting_way() const
        {
            return this->_setting_way;
        }
    };
}
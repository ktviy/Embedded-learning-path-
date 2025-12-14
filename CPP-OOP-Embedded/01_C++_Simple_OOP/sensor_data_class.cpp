#include <iostream>
#include <string>

class Sensor_data{
    private: 
        std::string sensor_id;
        float Reading;
        int* data_buffer = nullptr;

    public: 

        // Create a constructor to initialize members and allocate memory
        Sensor_data(const std::string& id, float value, int buffer_size){
            sensor_id = id;
            Reading = value; 

            {
                data_buffer = new int[buffer_size];
                std::cout << "Constructor object " << sensor_id << "created. Allocated "
                          << buffer_size * sizeof(int) << " bytes on Healp" << std::endl;
                }
            }

            // Create destructor to free allocated memory
            ~Sensor_data(){
                if(data_buffer != nullptr){
                    delete[] data_buffer;
                    std::cout << "Destructor object " << sensor_id << " destroyed, memory freed." << std::endl;
                }
            }
            
            // Getter: allow read access to private member Reading
            float getReading() const {
                return Reading;
            }

            // Setter: allow controlled write access to private member Reading
            void setReading(float new_value){
                if (new_value >= 0.0){
                    Reading = new_value;
                }
            }
};

int main(){

    Sensor_data sensor1("Sensor A", 10.5, 10);
    std::cout << "Initial reading: " << sensor1.getReading() << std::endl;

    sensor1.setReading(11.0);
    std::cout << "New reading: " << sensor1.getReading() << std::endl;

    std::cout << "End of program. Destructors called automatically" << std::endl;

    return 0;

}

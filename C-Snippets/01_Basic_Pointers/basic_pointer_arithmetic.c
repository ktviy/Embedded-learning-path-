#include <stdio.h>

// pointer - A variable that stores the memory address of another variable
// Benefit: save memory by passing the address of a large data structure instead of copying the entire structure

float sensor_data[] = {1, 2, 3, 4, 5}; // Fixed sensor data 

float *data = &sensor_data[0];  // pointer to the first element of the array

void process_sensor_data(float* data, int size);

int main(){
    process_sensor_data(data, sizeof(sensor_data)/sizeof(sensor_data[0]));
    return 0;
}

void process_sensor_data(float *data, int size){
    printf("Processing sensor data\n");
    float sum = 0.0f;

    for (int i = 0; i < size; i++){
        sum += *(data + i); // dereferencing pointer to access array elements
        printf("Address of data: %p, Value: %f\n", (data + i), *(data + i));
    }

    printf("Total Sum: %.f\n", sum);
}

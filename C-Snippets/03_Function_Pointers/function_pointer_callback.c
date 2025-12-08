#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name_sensor[20];
    int id_sensor;
    float value_sensor;
} Sensor_record; 

// Declare a function pointer type  
typedef void (*input_callback)(Sensor_record *sensor, int index);

// Define a function that will serve as a callback
void input_data_callback(Sensor_record *sensor, int index);

// Define a function that accepts the callback
void process_input(Sensor_record *sensor, int count, input_callback callback);

void sensor_info(Sensor_record *sensor, int count);

int main(){
    int count =0; 
    printf("How many sensors do you want to record? ");
    scanf("%d", &count);


    Sensor_record lists[count];
    Sensor_record *sensor_data = lists;

    process_input(sensor_data, count, input_data_callback);

    sensor_info(sensor_data, count);

    return 0; 
}

void input_data_callback(Sensor_record *sensor, int index){
            printf("Enter the information of Sensor %d\n", index + 1);

            getchar(); // clear the newline from scanf of taking count 

            printf("Name of Sensor: ");
            fgets(sensor->name_sensor, sizeof(sensor->name_sensor), stdin);
            sensor->name_sensor[strlen(sensor->name_sensor) - 1] = '\0';

            printf("ID of Sensor: ");
            scanf("%d", &sensor->id_sensor);

            printf("Value of Sensor: ");
            scanf("%f", &sensor->value_sensor);  
}

void process_input(Sensor_record *sensor, int count, input_callback callback){
    for (int i = 0; i < count; i++) {
        callback(&sensor[i], i); 
    }
}

void sensor_info(Sensor_record *sensor, int count){
    printf("Sensor Information\n");

    for (int i = 0; i < count; i++){
        printf("Sensor %d\n", i + 1);
        printf("Name of Sensor: %s\n", sensor[i].name_sensor); // Using array notation
        printf("ID of Sensor: %d\n", (sensor + i)->id_sensor); // Using pointer arithmetic 
        printf("Value of Sensor: %.2f\n", (*(sensor+i)).value_sensor); // Dereferencing pointer

        printf("\n");
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name_sensor[20];
    int id_sensor;
    float value_sensor;
} Sensor_record; 

// Function to create a dynamic buffer for Sensor_record

Sensor_record* create_dynamic_buffer(int count){
    Sensor_record *buffer = (Sensor_record*)malloc(count * sizeof(Sensor_record));
    if (buffer == NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }
    return buffer;
}

void sensor_info(Sensor_record *sensor, int count);

int main(){

    int count = 2; 

    Sensor_record *data_buffer = create_dynamic_buffer(count);

    // Free the dynamic memory allocated for Sensor_record
    if (data_buffer != NULL){
        free(data_buffer);
        data_buffer = NULL;

        printf("Dynamic memory for Sensor_record has been freed.\n");
    }

    Sensor_record lists[count];
    Sensor_record *sensor_data = &lists[0];

    for (int i = 0; i < count; i++){
        printf("Enter the information of Sensor %d\n", i + 1);

        printf("Name of Sensor: ");
        fgets(lists[i].name_sensor, sizeof(lists[i].name_sensor), stdin);
        lists[i].name_sensor[strlen(lists[i].name_sensor) - 1] = '\0';

        printf("ID of Sensor: ");
        scanf("%d", &lists[i].id_sensor);

        printf("Value of Sensor: ");
        scanf("%f", &lists[i].value_sensor);
    }

    sensor_info(sensor_data, count);

    return 0; 
}

void sensor_info(Sensor_record *sensor, int count){
    printf("Sensor Information\n");

    for (int i = 0; i < count; i++){
        printf("Sensor %d\n", i + 1);
        printf("Name of Sensor: %s\n", sensor[i].name_sensor); // Using array notation
        printf("ID of Sensor: %d\n", (sensor + i)->id_sensor); // Using pointer arithmetic 
        printf("Value of Sensor: %.2f\n", (*sensor).value_sensor); // Dereferencing pointer

        printf("\n");
    }
}


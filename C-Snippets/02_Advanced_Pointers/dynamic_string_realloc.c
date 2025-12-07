#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name_sensor[20];
    float value_sensor;
    int id_sensor;
} Sensor_record; 

void sensor_info(Sensor_record *sensor, int count);

int main(){

    int count = 2; 

    // Dynamic memory allocation for Sensor_record

    Sensor_record *data_buffer = (Sensor_record*)malloc(count * sizeof(Sensor_record));

    // Free the dynamic memory allocated for Sensor_record
    if (data_buffer == NULL){
        printf("Memory allocation failed.\n");
        return 1;
    } 


    for (int i = 0; i < count; i++){
        printf("Enter the information of Sensor %d\n", i + 1);

        printf("Name of Sensor: ");
        fgets(data_buffer[i].name_sensor, sizeof(data_buffer[i].name_sensor), stdin);
        data_buffer[i].name_sensor[strlen(data_buffer[i].name_sensor) - 1] = '\0';

        printf("ID of Sensor: ");
        scanf("%d", &data_buffer[i].id_sensor);

        printf("Value of Sensor: ");
        scanf("%f", &data_buffer[i].value_sensor);

        getchar();
    }

    int newCount = 0; 
    printf("Enter new count of sensors to display: ");
    scanf("%d", &newCount);

    // Reallocate memory for Sensor_record
    Sensor_record *temp_buffer = (Sensor_record*)realloc(data_buffer, newCount * sizeof(Sensor_record));
    if (temp_buffer == NULL){
        printf("Could not reallocate memory.\n");
    } 
    else {
        data_buffer = temp_buffer;
        temp_buffer = NULL;

        for (int i = count; i < newCount; i++){
            printf("Enter the information of sensor %d\n", i + 1);

            getchar();
            
            printf("Name of Sensor: ");
            fgets(data_buffer[i].name_sensor, sizeof(data_buffer[i].name_sensor), stdin);
            data_buffer[i].name_sensor[strlen(data_buffer[i].name_sensor) - 1] = '\0';

            printf("ID of Sensor: ");
            scanf("%d", &data_buffer[i].id_sensor);

            printf("Value of Sensor: ");
            scanf("%f", &data_buffer[i].value_sensor);

            getchar();
    }

        sensor_info(data_buffer, newCount);
    }

    free(data_buffer); // returning the allocated memory to the system
    data_buffer = NULL; // Avoid dangling pointer

    printf("Reallocate memory for Sensor_record has been freed.\n");

    return 0; 
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

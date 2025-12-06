#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name_sensor[20];
    int id_sensor;
    float value_sensor;
} Sensor_record; 


void sensor_info(Sensor_record *sensor, int count);

int main(){
    int count =0; 
    printf("How many sensors do you want to record? ");
    scanf("%d", &count);

    Sensor_record lists[count];
    Sensor_record *sensor_data = &lists[0];

    for (int i = 0; i < count; i++){
        printf("Enter the information of Sensor %d\n", i + 1);

        getchar(); // clear the newline from scanf of taking count 

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
        printf("Value of Sensor: %.2f\n", (*(sensor+i)).value_sensor); // Dereferencing pointer

        printf("\n");
    }
}

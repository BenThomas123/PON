#include <stdio.h>
#include "network.h"

void test_tcp_connection(void) {
    printf("Testing TCP Connection...\n");
    if (tcp_connect("127.0.0.1", 8080) == 0) {
        printf("TCP Connection Test Passed\n");
    } else {
        printf("TCP Connection Test Failed\n");
    }
}

void test_mqtt_publish(void) {
    printf("Testing MQTT Publish...\n");
    mqtt_connect("mqtt.example.com", 1883);
    if (mqtt_publish("test/topic", "Hello, World!") == 0) {
        printf("MQTT Publish Test Passed\n");
    } else {
        printf("MQTT Publish Test Failed\n");
    }
}

int main(void) {
    test_tcp_connection();
    test_mqtt_publish();
    return 0;
}

//
// Created by prem on 01/12/25.
//

//
// Created by prem on 23/11/25.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 50
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data) {
    if (rear == MAX -1) {
        // Queue overflow
        printf("Queue is full");
        return;
    }
    if (front == -1) {
        // Setting front to 0 if first element
        front = 0;
    }
    rear++;
    queue[rear] = data;
    printf("Successfully enqueued %d\n", data);
}

void dequeue() {
    if (front == -1 || front > rear) {
        // If front goes ahead of rear, there are no elements
        printf("Queue is empty");
        return;
    }

    int deleted_data = queue[front];
    front++;
    printf("Successfully deleted %d\n", deleted_data);

    if (front > rear) {
        // If front exceeds rear, no elements are left, sets front and rear to -1 (default state)
        front = -1;
        rear = -1;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty");
        return;
    }
    printf("Current queue: [ ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("]\n");
}

int main() {
    //printf("Hello World!");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
}
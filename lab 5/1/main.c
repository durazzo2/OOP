#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char name[100];
    float rating;
    char genre[40];
} Movie;

typedef struct {
    char name[50];
    Movie movies[30];
    int num_movies;
} StreamingService;

void print(StreamingService service) {
    printf("%s\n", service.name);
    for (int i = 0; i < service.num_movies; i++) {
        printf("%s %.1f\n", service.movies[i].name, service.movies[i].rating);
    }
}

void showBestStreamingService(StreamingService services[], int num_services, char genre[]) {
    int max_count = 0;
    char best_service[50];
    for (int i = 0; i < num_services; i++) {
        int count = 0;
        for (int j = 0; j < services[i].num_movies; j++) {
            if (strcmp(services[i].movies[j].genre, genre) == 0) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            strcpy(best_service, services[i].name);
        }

    }
    if(max_count==0){
        printf("No service has movies of the given genre.");
        return 0;
    }
    printf("Best streaming service is: %s\n", best_service);
}

int main() {
    int num_services;
    scanf("%d", &num_services);
    StreamingService services[num_services];

    for (int i = 0; i < num_services; i++) {
        scanf("%s", services[i].name);
        scanf("%d", &services[i].num_movies);
        for (int j = 0; j < services[i].num_movies; j++) {
            scanf("%s %f %s", services[i].movies[j].name, &services[i].movies[j].rating, services[i].movies[j].genre);
        }
    }

    for (int i = 0; i < num_services; i++) {
        print(services[i]);
    }

    char genre[40];
    scanf("%s", genre);
    showBestStreamingService(services, num_services, genre);

    return 0;
}
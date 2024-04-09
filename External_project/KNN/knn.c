#include <stdio.h>
#include <string.h>
#include <math.h>

struct area {
    char AreaID[50];
    int Latitude;
    int Longitude;
    int HasGold;
};

typedef struct area Area;

double euclidean_distance(int lat1, int lon1, int lat2, int lon2) {
    return sqrt(pow(lat1 - lat2, 2) + pow(lon1 - lon2, 2));
}

int main() {
    Area data[] = {
        {"1", 54, 97, 1},
        {"2", 99, 91, 0},
        {"3", 61, 53, 1},
        {"4", 43, 95, 0},
        {"5", 60, 10, 1},
        {"6", 40, 74, 0},
        {"7", 16, 92, 1},
        {"8", 8, 8, 0},
        {"9", 90, 37, 1},
        {"10", 13, 32, 0},
        {"11", 85, 75, 1},
        {"12", 98, 23, 0},
        {"13", 94, 74, 1},
        {"14", 54, 38, 0},
        {"15", 36, 42, 1}
    };
    int n = sizeof(data) / sizeof(Area);
    int k = 3;
    int target_lat = 52, target_lon = 25;

    double distances[n];
    for (int i = 0; i < n; i++) {
        distances[i] = euclidean_distance(data[i].Latitude, data[i].Longitude, target_lat, target_lon);
    }

    for (int i = 0; i < k; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (distances[j] < distances[min_idx]) {
                min_idx = j;
            }
        }
        double temp = distances[i];
        distances[i] = distances[min_idx];
        distances[min_idx] = temp;

        Area temp_area = data[i];
        data[i] = data[min_idx];
        data[min_idx] = temp_area;
    }

    int hasGoldCount = 0;
    printf("Nearest %d neighbors for (Latitude = %d, Longitude = %d):\n", k, target_lat, target_lon);
    for (int i = 0; i < k; i++) {
        printf("AreaID: %s, Latitude: %d, Longitude: %d, HasGold: %s\n", data[i].AreaID, data[i].Latitude, data[i].Longitude, data[i].HasGold ? "Yes" : "No");
        if (data[i].HasGold) {
            hasGoldCount++;
        }
    }

    printf("Predicted HasGold: %s\n", hasGoldCount > k / 2 ? "Yes" : "No");


    return 0;
}
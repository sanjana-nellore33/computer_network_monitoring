#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Connection Node
struct AdjNode {
    int dest;
    struct AdjNode* next;
};

// Device (Vertex)
struct Vertex {
    int id;
    char name[50];
    struct AdjNode* head;
};

// Graph
struct Graph {
    int numVertices;
    struct Vertex vertices[MAX];
};

// Create Graph
struct Graph* createGraph() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = 0;
    return graph;
}

// Find Device
int findVertex(struct Graph* graph, int id) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->vertices[i].id == id)
            return i;
    }
    return -1;
}

// ADD DEVICE
void addDevice(struct Graph* graph) {
    int id;
    char name[50];

    printf("Enter Device ID: ");
    scanf("%d", &id);

    if (findVertex(graph, id) != -1) {
        printf("Device already exists!\n");
        return;
    }

    printf("Enter Device Name: ");
    scanf("%s", name);

    int i = graph->numVertices;
    graph->vertices[i].id = id;
    strcpy(graph->vertices[i].name, name);
    graph->vertices[i].head = NULL;

    graph->numVertices++;
    printf("Device added!\n");
}

// ADD CONNECTION
void addConnection(struct Graph* graph) {
    int src, dest;

    printf("Enter Source ID: ");
    scanf("%d", &src);
    printf("Enter Destination ID: ");
    scanf("%d", &dest);

    int s = findVertex(graph, src);
    int d = findVertex(graph, dest);

    if (s == -1 || d == -1) {
        printf("Invalid IDs!\n");
        return;
    }

    struct AdjNode* newNode = (struct AdjNode*)malloc(sizeof(struct AdjNode));
    newNode->dest = dest;
    newNode->next = graph->vertices[s].head;
    graph->vertices[s].head = newNode;

    printf("Connection added!\n");
}

// DELETE CONNECTION
void deleteConnection(struct Graph* graph) {
    int src, dest;
    printf("Enter Source ID: ");
    scanf("%d", &src);
    printf("Enter Destination ID: ");
    scanf("%d", &dest);

    int s = findVertex(graph, src);
    if (s == -1) {
        printf("Invalid source!\n");
        return;
    }

    struct AdjNode* temp = graph->vertices[s].head;
    struct AdjNode* prev = NULL;

    while (temp) {
        if (temp->dest == dest) {
            if (prev == NULL)
                graph->vertices[s].head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Connection deleted!\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Connection not found!\n");
}

// DELETE DEVICE
void deleteDevice(struct Graph* graph) {
    int id;
    printf("Enter Device ID to delete: ");
    scanf("%d", &id);

    int index = findVertex(graph, id);
    if (index == -1) {
        printf("Device not found!\n");
        return;
    }

    // Free connections
    struct AdjNode* temp = graph->vertices[index].head;
    while (temp) {
        struct AdjNode* t = temp;
        temp = temp->next;
        free(t);
    }

    // Remove connections TO this device
    for (int i = 0; i < graph->numVertices; i++) {
        struct AdjNode* curr = graph->vertices[i].head;
        struct AdjNode* prev = NULL;

        while (curr) {
            if (curr->dest == id) {
                if (prev == NULL)
                    graph->vertices[i].head = curr->next;
                else
                    prev->next = curr->next;

                free(curr);
                break;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    // Shift vertices
    for (int i = index; i < graph->numVertices - 1; i++) {
        graph->vertices[i] = graph->vertices[i + 1];
    }

    graph->numVertices--;

    printf("Device deleted!\n");
}

// UPDATE DEVICE
void updateDevice(struct Graph* graph) {
    int id;
    printf("Enter Device ID: ");
    scanf("%d", &id);

    int i = findVertex(graph, id);
    if (i == -1) {
        printf("Not found!\n");
        return;
    }

    printf("Enter new name: ");
    scanf("%s", graph->vertices[i].name);

    printf("Updated successfully!\n");
}

// SEARCH DEVICE
void searchDevice(struct Graph* graph) {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    int i = findVertex(graph, id);
    if (i == -1) {
        printf("Not found!\n");
        return;
    }

    printf("Device: %s\nConnections: ", graph->vertices[i].name);

    struct AdjNode* temp = graph->vertices[i].head;
    while (temp) {
        printf("%d ", temp->dest);
        temp = temp->next;
    }
    printf("\n");
}

// DISPLAY NETWORK
void display(struct Graph* graph) {
    printf("\n--- Network ---\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d (%s) -> ", graph->vertices[i].id, graph->vertices[i].name);

        struct AdjNode* temp = graph->vertices[i].head;
        while (temp) {
            printf("%d ", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

// SAVE FILE
void saveToFile(struct Graph* graph) {
    FILE* fp = fopen("network.txt", "w");

    fprintf(fp, "%d\n", graph->numVertices);

    for (int i = 0; i < graph->numVertices; i++) {
        fprintf(fp, "%d %s\n", graph->vertices[i].id, graph->vertices[i].name);

        struct AdjNode* temp = graph->vertices[i].head;
        while (temp) {
            fprintf(fp, "%d ", temp->dest);
            temp = temp->next;
        }
        fprintf(fp, "-1\n");
    }

    fclose(fp);
}

// LOAD FILE
void loadFromFile(struct Graph* graph) {
    FILE* fp = fopen("network.txt", "r");
    if (!fp) return;

    int n;
    fscanf(fp, "%d", &n);

    for (int i = 0; i < n; i++) {
        int id;
        char name[50];

        fscanf(fp, "%d %s", &id, name);

        graph->vertices[i].id = id;
        strcpy(graph->vertices[i].name, name);
        graph->vertices[i].head = NULL;

        int dest;
        while (1) {
            fscanf(fp, "%d", &dest);
            if (dest == -1) break;

            struct AdjNode* newNode = (struct AdjNode*)malloc(sizeof(struct AdjNode));
            newNode->dest = dest;
            newNode->next = graph->vertices[i].head;
            graph->vertices[i].head = newNode;
        }
    }

    graph->numVertices = n;
    fclose(fp);
}

// MAIN MENU
int main() {
    struct Graph* graph = createGraph();
    loadFromFile(graph);

    int choice;

    while (1) {
        printf("\n--- Network Monitoring ---\n");
        printf("1.Add Device\n2.Add Connection\n3.Delete Device\n4.Delete Connection\n");
        printf("5.Update Device\n6.Search\n7.Display\n8.Save\n9.Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addDevice(graph); break;
            case 2: addConnection(graph); break;
            case 3: deleteDevice(graph); break;
            case 4: deleteConnection(graph); break;
            case 5: updateDevice(graph); break;
            case 6: searchDevice(graph); break;
            case 7: display(graph); break;
            case 8: saveToFile(graph); printf("Saved!\n"); break;
            case 9:
                saveToFile(graph);
                printf("Exiting...\n");
                exit(0);
            default: printf("Invalid!\n");
        }
    }
}
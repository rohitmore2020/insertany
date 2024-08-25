#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int dataValue;
    struct ListNode* nextNode;
};

struct ListNode* insertAfterNode(struct ListNode* headNode) {
    printf("Enter the data of the node after which you want to insert a new node: ");
    int targetValue;
    scanf("%d", &targetValue);

    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    printf("Enter the data of the new node that you want to insert: ");
    scanf("%d", &newNode->dataValue);
    newNode->nextNode = NULL;

    struct ListNode* currentNode = headNode;
    while(currentNode->dataValue != targetValue) {
        currentNode = currentNode->nextNode;
    }

    newNode->nextNode = currentNode->nextNode;
    currentNode->nextNode = newNode;

    return headNode;
}

int main() {
    int totalNodes;
    printf("Enter the number of nodes you want to insert in the linked list: ");
    scanf("%d", &totalNodes);

    struct ListNode* headNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    printf("Enter the data of the first node of the linked list: ");
    scanf("%d", &headNode->dataValue);
    headNode->nextNode = NULL;

    struct ListNode* currentNode = headNode;

    int nodeCount = 1;
    while (nodeCount < totalNodes) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        printf("Enter the data of the new node: ");
        scanf("%d", &newNode->dataValue);
        newNode->nextNode = NULL;
        currentNode->nextNode = newNode;
        currentNode = currentNode->nextNode;
        nodeCount++;
    }

    printf("Here is our linked list:\n");

    currentNode = headNode;
    while (currentNode != NULL) {
        printf("%d -> ", currentNode->dataValue);
        currentNode = currentNode->nextNode;
    }
    printf("NULL\n");

    headNode = insertAfterNode(headNode);

    printf("New linked list after the insertion:\n");

    currentNode = headNode;
    while (currentNode != NULL) {
        printf("%d -> ", currentNode->dataValue);
        currentNode = currentNode->nextNode;
    }
    printf("NULL\n");

    return 0;
}

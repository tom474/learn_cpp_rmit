#include <iostream>

using std::cout;

// Class Declaration
class Node {
    private:
        int value;
        Node *next;
        Node *prev;
    public:
        Node(int valueVal = 0, Node *nextVal = nullptr, Node *prevVal = nullptr)
        : value(valueVal), next(nextVal), prev(prevVal) {}

        // Function to link to the next node
        void linkNextNode(Node *nextNode) {
            next = nextNode;
            if (nextNode != nullptr) {
                nextNode->prev = this;  // Link backward from nextNode
            }
        }

        // Function to link to the previous node
        void linkPrevNode(Node *prevNode) {
            prev = prevNode;
            if (prevNode != nullptr) {
                prevNode->next = this;  // Link forward from next node
            }
        }

        friend void showForwardLinks(Node *head);
        friend void showBackwardLink(Node *tail);
        friend void insertNode(Node *&headNode, Node *&tailNode, Node *priorNode, Node *newNode);
        friend void deleteNode(Node *&head, Node *&tail, Node *delNote);
        friend void swapNodes(Node *&headNode, Node *&tailNode, Node *nodeA, Node *nodeB);
        friend void sortNodeAscending(Node *&headNode, Node *&tailNode);
};

// Function to show links
void showForwardLinks(Node *head) {
    cout << "Forward links: ";
    Node *temp = head;  // Temp is the current node
    while (temp != nullptr) {
        cout << temp->value << " -> ";  // Value of current node
        temp = temp->next;  // Go to the next node
    }
    cout << "\n";
}

void showBackwardLink(Node *tail) {
    cout << "Backward links: ";
    Node *temp = tail;  // Temp is the current node
    while (temp != nullptr) {
        cout << temp->value << " -> ";  // Value of current node
        temp = temp->prev;  // Go to the prev node
    }
    cout << "\n";
}

void showLinks(Node *head, Node *tail) {
    showForwardLinks(head);
    showBackwardLink(tail);
}

// Function to insert node
// Note: *& is pass-by-reference for the pointer variable
// (same as pass-by-reference for a normal data type)
void insertNode(Node *&headNode, Node *&tailNode, Node *priorNode, Node *newNode) {
    if (priorNode == nullptr) { // Insert at the beginning
        // Connect newNode to the current head
        newNode->linkNextNode(headNode);

        // The newNode became the new head
        headNode = newNode;
    } else if (priorNode == tailNode) { // Insert at the end
        // Connect tailNode to the newNode
        tailNode->linkNextNode(newNode);

        // The newNode become the new tail
        tailNode = newNode;
    } else {    // Insert at the middle
        // Connect newNode to the node after priorNode
        newNode->linkNextNode(priorNode->next);

        // Connect priorNode to the newNode
        priorNode->linkNextNode(newNode);
    }
}

// Function to delete node
void deleteNode(Node *&head, Node *&tail, Node *delNote) {
    if (delNote == head) {
        head = delNote->next;
    } else if (delNote == tail) {
        tail = delNote->prev;
    }
    delNote->next->linkPrevNode(delNote->prev);
    delNote->prev->linkNextNode(delNote->next);
}

// Function to swap nodes
void swapNodes(Node *&headNode, Node *&tailNode, Node *nodeA, Node *nodeB) {
    // Store all value of nodeB first (since its value will be changed)
    Node temp = *nodeB;

    // A stands before B --> after swapping, B will stand before A
    if (nodeB->prev == nodeA) {
        nodeB->linkPrevNode(nodeA->prev);   // Second way: (nodeA->prev)->linkNextNode(nodeB);
        nodeB->linkNextNode(nodeA);
        nodeA->linkNextNode(temp.next);

    // B stands before A --> after swapping, A will stand before B
    } else if(nodeB->next == nodeA) {
        nodeB->linkNextNode(nodeA->next);
        nodeB->linkPrevNode(nodeA);
        nodeA->linkPrevNode(temp.next);

    // Normal case
    } else {
        //Connect B with next node of A
        nodeB->linkNextNode(nodeA->next);
        //Connect B with previous node of A
        nodeB->linkPrevNode(nodeA->prev);

        //Connect A with next node of B
        nodeA->linkNextNode(temp.next);
        //Connect A with previous node of B
        nodeA->linkPrevNode(temp.prev);
    }

    // Update the head and the tail if A or B is head/tail
    headNode = (headNode == nodeA) ? nodeB : (headNode == nodeB) ? nodeA : headNode;
    tailNode = (tailNode == nodeA) ? nodeB : (tailNode == nodeB) ? nodeA : tailNode;
}

// Function to sort using bubble sort (ascending: left < right)
void sortNodeAscending(Node *&headNode, Node *&tailNode) {
    while (true) {
        int swap = 0;   // Did not swap yet

        // Loop to go from the left (starting from head)
        for (Node *node = headNode; node != nullptr && node != tailNode; ) {
            // Compare current node with the next node and swap if not in correct order
            if (node->value > node->next->value){
                swapNodes(headNode, tailNode, node, node->next);
                swap = 1;   // Already swapped at least once
            } else {
                node = node->next;  // Go to next node
            }
        }

        if (swap == 0) {    // No swapping above (the list is already sorted)
            break;
        }
    }
}

int main() {
    Node node1(8), node2(5), node3(3), node4(6);

    // Connect nodes
    Node *head = &node1;    // Head is a pointer variable
    node1.linkNextNode(&node2);
    node2.linkNextNode(&node3);
    node3.linkNextNode(&node4);  
    Node *tail = &node4;    //Tail is a pointer variable

    // Show connections
    cout << "Original linked list: \n";
    showLinks(head, tail);

    // Test insert node in the middle
    cout << "\nInsert 200 after 3: \n";
    Node newNode1(200);
    insertNode(head, tail, &node3, &newNode1);
    showLinks(head, tail);

    // Test replace the head
    cout << "\nInsert 100 at the head: \n";
    Node newNode2(100);
    insertNode(head, tail, nullptr, &newNode2);
    showLinks(head, tail);

    // Swap nodes
    cout << "\nTest Swapping 8 and 3: \n";
    swapNodes(head, tail, &node1, &node3);
    showLinks(head, tail);

    // Sorting with Bubble Sort
    cout << "\nTest Sorting: \n";
    sortNodeAscending(head, tail);
    showLinks(head, tail);

    // Test delete
    cout << "\nDelete 5: \n";
    deleteNode(head, tail, &node2);
    showLinks(head, tail);

    return 0;
}
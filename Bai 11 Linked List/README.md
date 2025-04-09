# 1. Linked List
Linkded list là một cấu trúc dữ liệu trong lập trình máy tính, được sử dụng để tổ chức và lưu trữ dữ liệu. Một linked list bao gồm một các chuỗi các nodes, mỗi nút chứa một giá trị dữ liệu và một con trỏ  pointer trỏ đến nút tiếp tiếp theo trong chuỗi. 
- ```Data``` : là giá trị dữ liệu được lưu trữ trong các nút.
- ```Con trỏ Pointer```: Đây là tham chiếu đến nút tiếp theo trong danh sách.
![Image](Linked-list-nodes.png)

```c
typedef struct Node()
{
    int data;   // giá trị của node
    struct Node* next;  // con trỏ trỏ đến node tiếp theo của mảng
}
```
Một linked list cung cấp một cách linh hoạt để thêm, xóa,và chèn các phẩn tử mà không cần phải di chuyển toàn bộ dãy số như mảng. Tuy nhiên, nó cũng có một số nhược điểm như việc cần thêm một con trỏ cho mỗi nút, tăng độ phức tập của bộ nhớ và có thẻ dẫn đến hiệu suất kém hơn trong một số trường hợp so với mảng. 
### 1.0.1. Thao tác trên danh sách liên kết

**Khởi tạo một node mới**
```c
// Hàm khởi tạo một node mới
 Node *createNode(int value)
{
    node *new_node = (Node*)malloc(sizeof(Node));
    new_node-> value = value;
    new_node-> next =NULL;

    return new_node;
}
```
**Thêm một node vào phần tử cuối cùng**
```c
typedef struct Node {
    int data; // Dữ liệu của nút
    struct Node* next; // Con trỏ trỏ đến nút tiếp theo
} Node;
// Hàm tạo một nút mới với dữ liệu được cung cấp
Node *createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Cấp phát bộ nhớ cho nút mới
    if (newNode == NULL) { // Kiểm tra nếu cấp phát bộ nhớ thất bại
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data; // Gán dữ liệu cho nút
    newNode->next = NULL; // Gán con trỏ next của nút là NULL
    return newNode; // Trả về con trỏ đến nút mới
}

// Hàm thêm một nút vào cuối danh sách liên kết
void push_back(Node **array, int data) {
    Node* newNode = createNode(data); // Tạo một nút mới với dữ liệu được cung cấp
    
    if(*array == NULL) { // Nếu danh sách liên kết rỗng
        *array = newNode; // Gán nút mới làm nút đầu tiên
        return;
    }
    Node *current = *array; // Bắt đầu từ nút đầu tiên
    while (current->next != NULL) { // Duyệt đến nút cuối cùng
        current = current->next;
    }
    current->next = newNode; // Gán nút mới vào cuối danh sách
}
```
**Thêm một node vào phần tử đầu tiên**
```c
Node *createNode(int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode ->data = data;
    newNode ->next = NULL;
    return newNode;
}
void push_front(Node **array, int data)
{
    Node *newNode = createNode(data);

    if(*array == NULL)
    {
        *array = newNode;
        return;
    }
    newNode ->next = *array; // Gán con trỏ next của nút mới là nút đầu tiên
    *array = newNode; // Gán nút mới làm nút đầu tiên
}
```

**Thêm một node vào vị trí bất kỳ**
```c
Node *createNote(int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode ->data = data;
    newNode ->next = NULL;
    return newNode;
}
void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = createNote(data);
    if (newNode == NULL) {
        return;
    }

    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
```
**Xóa node ở vị trí cuối cùng**
```c
typedef struct Node {
    int data; 
    struct Node* next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode ->data = data;
    newNode ->next = NULL;
    return newNode;
}
void push_back(Node **array, int data) {
    Node* newNode = createNode(data); // Tạo một nút mới với dữ liệu được cung cấp
    
    if(*array == NULL) { // Nếu danh sách liên kết rỗng
        *array = newNode; // Gán nút mới làm nút đầu tiên
        return;
    }
    Node *current = *array; // Bắt đầu từ nút đầu tiên
    while (current->next != NULL) { // Duyệt đến nút cuối cùng
        current = current->next;
    }
    current->next = newNode; // Gán nút mới vào cuối danh sách
}

void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data); // In dữ liệu của từng nút
        current = current->next;
    }
    printf("\n");
}
void pop_back(Node **array )
{
    if (*array == NULL) // Nếu danh sách rỗng
    {
        printf("Danh sach rong\n");
        return;
    }
    Node *current = *array;

    while (current->next->next != NULL)
    {
        current=current->next; // Duyệt đến nút cuối cùng
    }
    free(current->next); // Giải phóng bộ nhớ của nút cuối cùng
    current->next = NULL; // Gán con trỏ next của nút trước đó là NULL
}
```
**Xóa node ở vị trí cuối cùng**
```c

typedef struct Node {
    int data; 
    struct Node* next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode ->data = data;
    newNode ->next = NULL;
    return newNode;
}
void push_back(Node **array, int data) {
    Node* newNode = createNode(data); // Tạo một nút mới với dữ liệu được cung cấp
    
    if(*array == NULL) { // Nếu danh sách liên kết rỗng
        *array = newNode; // Gán nút mới làm nút đầu tiên
        return;
    }
    Node *current = *array; // Bắt đầu từ nút đầu tiên
    while (current->next != NULL) { // Duyệt đến nút cuối cùng
        current = current->next;
    }
    current->next = newNode; // Gán nút mới vào cuối danh sách
}

void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data); // In dữ liệu của từng nút
        current = current->next;
    }
    printf("\n");
}
void pop_back(Node **array )
{
    if (*array == NULL) // Nếu danh sách rỗng
    {
        printf("Danh sach rong\n");
        return;
    }
    Node *current = *array;

    while (current->next->next != NULL)
    {
        current=current->next; // Duyệt đến nút cuối cùng
    }
    free(current->next); // Giải phóng bộ nhớ của nút cuối cùng
    current->next = NULL; // Gán con trỏ next của nút trước đó là NULL
}
```
**Xóa một node tại vị trí cuối cùng**
```c
void pop_front(Node **array )
{
    if (*array == NULL) // Nếu danh sách rỗng
    {
        printf("Danh sach rong\n");
        return;
    }
    Node *temp = *array; // Lưu trữ nút đầu tiên
    *array = (*array)->next; // Gán nút tiếp theo làm nút đầu tiên
    free(temp); // Giải phóng bộ nhớ của nút đầu tiên
}
```
**Lấy kích thước của list**
```c
int size(Node* array) {
    int count = 0;
    Node* temp = array;

    // Duyệt qua danh sách và đếm số lượng node
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
    }
```
**Kiểm tra list có rỗng hay không**
```c
// Hàm kiểm tra xem danh sách có rỗng hay không
bool empty(node* array) {
    return (array == NULL);
}
```
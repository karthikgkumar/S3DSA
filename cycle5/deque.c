

#include <stdio.h>
typedef struct Node {

        int data;
        struct Node *left;
        struct Node *right;
}*head,*tail,*newnode;

head =NULL;
tail = NULL;
int count = 0;

void insertfront(int data) {
        newnode=(struct node *)malloc(1*sizeof(struct Node));
        if (head == null) {
            head = tail = newNode;
        } else {
            head.left = newNode;
            newNode.right = head;
            head = newNode;
        }
        count++;
    }

    public void insertend(int data) {
        Node newnode = new Node(data);
        if (head == null) {
            head = tail = newnode;
        } else {
            tail.right = newnode;
            newnode.left = tail;
            tail = newnode;
        }
        count++;
    }

    public void insertany(int pos, int item) {
        System.out.println(count);
        int i = 1;
        Node node = new Node(item);
        Node temp = head;

        if (pos > count + 1 && pos < 0) {
            System.out.println("invalid position");
        } else if (pos == 1) {
            insertfront(item);
        } else if (pos == count + 1) {
            insertend(item);

        }

        else {
            while (i < pos - 1) {
                temp = temp.right;
                i++;
            }
            node.left = temp;
            node.right = temp.right;
            temp.right = node;
            node.right.left = node;
            count++;
        }

    }

    public void delete() {
        if (head == null)
            System.out.println("List is Empty");
        else {
            int x = head.data;
            head = head.right;
            head.left = null;
            System.out.println("Element " + x + " got deleted");
            count--;
        }
    }

    public void display() {
        if (head == null)
            System.out.println("List is Empty");
        else {
            Node ptr = head;
            while (ptr != null) {
                System.out.print(ptr.data + "\t");
                ptr = ptr.right;
            }
            System.out.println();
        }
    }
}

class Test {
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        Scanner sc = new Scanner(System.in);
        String choice = "";
        while (!choice.equals("6")) {
            System.out.print(
                    "1. Insert at Front \n2.Insert at end\n3.Insert at any position\n4. Delete From Front \n5. Display \n6.Exit\n");

            System.out.println("Enter the choice:");
            choice = sc.nextLine();
            switch (choice) {
                case "1":
                    System.out.print("Enter the number to insert at front:");
                    int data = sc.nextInt();
                    sc.nextLine();
                    list.insertfront(data);

                    System.out.println("Data inserted Successfully");

                    break;
                case "2":
                    System.out.print("Enter the number to insert at end:");
                    data = sc.nextInt();
                    sc.nextLine();
                    list.insertend(data);
                    System.out.println("Data inserted Successfully");
                    break;
                case "3":
                    System.out.print("Enter the position:");
                    data = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Enter the number to be inserted:");
                    int item = sc.nextInt();
                    sc.nextLine();
                    list.insertany(data, item);
                    System.out.println("Data inserted Successfully");

                    break;

                case "4":
                    list.delete();
                    break;
                case "5":
                    list.display();
                    break;
                case "6":
                    break;
                default:
                    System.out.println("Invalid Choice");
            }
        }
    }
}
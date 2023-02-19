// OOPLab5T.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>

// Ваші файли загловки 
//
#include <string>
#include <queue>
#include "Lab5Exmaple.h"
using namespace std;
int main()
{
    std::cout << " Lab #5  !\n";
    //1 ex
    class Pair {
public:
    int first, second;
    Pair(int a, int b) {
        first = a;
        second = b;
    }

    void setFirst(int a) {
        first = a;
    }

    void setSecond(int b) {
        second = b;
    }

    bool operator>(const Pair& other) const {
        if (first > other.first)
            return true;
        else if (first == other.first && second > other.second)
            return true;
        else
            return false;
    }
};

class Fraction : public Pair {
public:
    Fraction(int a, int b) : Pair(a, b) {}

    bool operator==(const Fraction& other) const {
        return (first == other.first && second == other.second);
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator>(const Fraction& other) const {
        return Pair::operator>(other);
    }

    bool operator<(const Fraction& other) const {
        return !(*this > other) && (*this != other);
    }

    bool operator>=(const Fraction& other) const {
        return (*this > other)  (*this == other);
    }

    bool operator<=(const Fraction& other) const {
        return (*this < other)  (*this == other);
    }
};

int main() {
    Fraction a(3, 4);
    Fraction b(1, 2);
    Fraction c(3, 4);

    cout << "a > b: " << (a > b) << endl;
    cout << "a == c: " << (a == c) << endl;
    cout << "b < c: " << (b < c) << endl;
    cout << "a >= c: " << (a >= c) << endl;
    cout << "b <= c: " << (b <= c) << endl;

    return 0;
} 
    //Ex 2
    class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }

    ~Node() {
        delete left;
        delete right;
    }
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() {
        root = nullptr;
    }

    ~BinaryTree() {
        delete root;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (root == nullptr) {
            root = newNode;
        }
        else {
            Node* current = root;
            while (true) {
                if (val < current->data) {
                    if (current->left == nullptr) {
                        current->left = newNode;
                        break;
                    }
                    current = current->left;
                }
                else {
                    if (current->right == nullptr) {
                        current->right = newNode;
                        break;
                    }
                    current = current->right;
                }
            }
        }
    }

    void breadthFirstTraversal() {
        if (root == nullptr) {
            return;
        }

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }
};

int main() {
    BinaryTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Breadth-First Traversal: ";
    tree.breadthFirstTraversal();
    cout << endl;

    return 0;
}
//Ex 3
    class Point {
protected:
    double x;
    double y;

public:
    Point(double xVal = 0.0, double yVal = 0.0) {
        x = xVal;
        y = yVal;
    }

    Point(const Point& other) {
        x = other.x;
        y = other.y;
    }

    Point& operator=(const Point& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    virtual ~Point() {}

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    virtual void print(ostream& out) const {
        out << "(" << x << ", " << y << ")";
    }

    virtual void read(istream& in) {
        in >> x >> y;
    }
};

class ColorPoint : public Point {
private:
    string color;

public:
    ColorPoint(double xVal = 0.0, double yVal = 0.0, const string& colorVal = "black") : Point(xVal, yVal) {
        color = colorVal;
    }

    ColorPoint(const ColorPoint& other) : Point(other) {
        color = other.color;
    }

    ColorPoint& operator=(const ColorPoint& other) {
        if (this != &other) {
            Point::operator=(other);
            color = other.color;
        }
        return *this;
    }

    virtual ~ColorPoint() {}

    const string& getColor() const {
        return color;
    }

    virtual void print(ostream& out) const {
        out << "(" << x << ", " << y << ") " << color;
    }

    virtual void read(istream& in) {
        Point::read(in);
        in >> color;
    }
};

ostream& operator<<(ostream& out, const Point& point) {
    point.print(out);
    return out;
}

istream& operator>>(istream& in, Point& point) {
    point.read(in);
    return in;
}

int main() {
    Point p(1.0, 2.0);
    cout << "Point p: " << p << endl;

    ColorPoint cp(3.0, 4.0, "red");
    cout << "ColorPoint cp: " << cp << endl;

    Point* p2 = new ColorPoint(5.0, 6.0, "green");
    cout << "Point* p2: " << *p2 << endl;
    delete p2;

    return 0;
}
    int chain = 1;
    if (chain == 1) chain = mainExample1();
    if (chain == 2) chain = mainExample2();
    if (chain == 3) chain = mainExample3();
    if (chain == 4) chain = mainExample4();
    if (chain == 5) chain = mainExample5();

}

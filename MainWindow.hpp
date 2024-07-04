#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "Tree.hpp" // Include your generic Tree and Node definitions
#include <QMainWindow>
#include <QPainter>
#include <QString>
#include "Node.hpp"

using namespace ariel;

// Template declaration for MainWindow
template <typename T, size_t k = 2>
class MainWindow : public QMainWindow {
public:
    MainWindow(QWidget* parent = nullptr, Tree<T, k>* tree = new Tree<T, k>());
    ~MainWindow();
    int paddingX;

protected:
    void paintEvent(QPaintEvent* event);

private:
    Tree<T, k> tree;
    int elipsXSize;
    int elipsYSize;
    QPoint calculateNodePosition(Node<T,k>* node, int depth, int index, int siblingCount);
    QString toQString(const T& value);
    void drawNode(QPainter& painter, Node<T,k>* node, QPoint center, int elipsXSize, int elipsYSize);
    int getMaxLevel(Node<T,k>* node);
    void drawTree(QPainter& painter, Node<T,k>* node, int depth, int index, int siblingCount);
};

#endif // MAINWINDOW_HPP

#include "MainWindow.hpp"
#include <sstream>
#include <QApplication>
#include <QPainter>
#include <QPaintEvent>
#include "Complex.hpp"

// Implementation of MainWindow
template <typename T, size_t k>
MainWindow<T, k>::MainWindow(QWidget* parent, ariel::Tree<T, k>* tree)
    : QMainWindow(parent), tree(*tree) {
    paddingX = 50; // Set a default padding
    int maxDataLength = tree->findMaxDataLength();
    elipsXSize = maxDataLength * 10;
    elipsYSize = 20; // Height of ellipse
}

template <typename T, size_t k>
MainWindow<T, k>::~MainWindow() {
}

template <typename T, size_t k>
void MainWindow<T, k>::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    if (tree.get_root() != nullptr) {
        drawTree(painter, tree.get_root(), 0, 0, 1);
    }
}

template <typename T, size_t k>
QString MainWindow<T, k>::toQString(const T& value) {
    std::ostringstream oss;
    oss << value;
    return QString::fromStdString(oss.str());
}

template <typename T, size_t k>
void MainWindow<T, k>::drawNode(QPainter& painter, Node<T,k>* node, QPoint center, int elipsXSize, int elipsYSize) {
    painter.drawEllipse(center.x() - elipsXSize/2, center.y() - elipsYSize/2, elipsXSize, elipsYSize);
    painter.drawText(center.x() - elipsXSize/2, center.y() - elipsYSize/2, elipsXSize, elipsYSize, Qt::AlignCenter, toQString(node->getValue()));
}

template <typename T, size_t k>
QPoint MainWindow<T, k>::calculateNodePosition(Node<T,k>* node, int depth, int index, int siblingCount) {
    int totalWidth = siblingCount * (elipsXSize + paddingX);
    int x = (width() - totalWidth) / 2 + index * (elipsXSize + paddingX);
    int y = 50 + depth * (elipsYSize + 50); // Adjust 50 for the vertical distance between levels, lower the root slightly
    return QPoint(x, y);
}

template <typename T, size_t k>
int MainWindow<T, k>::getMaxLevel(Node<T,k>* node) {
    if (node == nullptr) {
        return 0;
    }
    int maxLevel = 0;
    for (auto child : node->children) {
        maxLevel = std::max(maxLevel, getMaxLevel(child));
    }
    return maxLevel + 1;
}

template <typename T, size_t k>
void MainWindow<T, k>::drawTree(QPainter& painter, Node<T,k>* node, int depth, int index, int siblingCount) {
    if (node == nullptr) {
        return;
    }
    QPoint center = calculateNodePosition(node, depth, index, siblingCount);
    drawNode(painter, node, center, elipsXSize, elipsYSize);

    int childCount = node->getNumOfChildren();
    for (size_t i = 0; i < childCount; ++i) {
        Node<T,k>* child = node->children[i];
        if (child != nullptr) {
            QPoint childCenter = calculateNodePosition(child, depth + 1, index * k + i, childCount);
            painter.drawLine(center.x(),center.y() + (elipsYSize/2),  childCenter.x(),childCenter.y() - (elipsYSize/2));
            drawTree(painter, child, depth + 1, index * k + i, childCount);
        }
    }
}

// Explicit instantiation for a specific type and k value if needed
template class MainWindow<int, 2>;
template class MainWindow<int, 3>;
template class MainWindow<string, 3>;
template class MainWindow<Complex, 3>;

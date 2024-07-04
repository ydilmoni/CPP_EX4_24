#include "TreeVisualizerWindow.hpp"
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>

namespace ariel {

template <typename T, size_t k>
TreeVisualizerWindow::TreeVisualizerWindow(const Tree<T, k>& tree, QWidget *parent)
    : QMainWindow(parent)
{
    view = new QGraphicsView(this);
    scene = new QGraphicsScene(this);
    view->setScene(scene);

    setCentralWidget(view);
    setWindowTitle("Tree Visualizer");
    resize(800, 600);

    const Node<T, k>* root = tree.get_root();
    if (root) {
        drawTree(root, 0, 0, 300);
    }

    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}

template <typename T, size_t k>
void TreeVisualizerWindow::drawTree(const Node<T, k>* node, qreal x, qreal y, qreal xOffset)
{
    if (!node) return;

    // Draw node
    QGraphicsEllipseItem *ellipse = scene->addEllipse(x - 20, y - 20, 40, 40);
    QGraphicsTextItem *text = scene->addText(QString::number(node->getValue()));
    text->setPos(x - 10, y - 10);

    // Draw children
    qreal childXOffset = xOffset / 2;
    for (size_t i = 0; i < node->getNumOfChildren(); ++i) {
        if (node->children[i]) {
            qreal childX = x - xOffset + i * 2 * childXOffset;
            qreal childY = y + 100;

            // Draw line to child
            scene->addLine(x, y + 20, childX, childY - 20);

            // Recursively draw child subtree
            drawTree(node->children[i], childX, childY, childXOffset);
        }
    }
}

// Explicit instantiation for the types you'll use
template class TreeVisualizerWindow<int, 2>;
template class TreeVisualizerWindow<int, 3>;
// Add more instantiations as needed

} // namespace ariel

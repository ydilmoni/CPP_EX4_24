#include "MainWindowBase.hpp"
#include "MainWindowBase.hpp"

MainWindowBase::MainWindowBase(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindowBase) {
    ui->setupUi(this);
}

MainWindowBase::~MainWindowBase() {
    delete ui;
}

void MainWindowBase::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    // Example drawNode call, adjust x, y, dx, dy as needed
    drawNode(painter, 50, 50, 20, 20);
}

void MainWindowBase::drawNode(QPainter& painter, int x, int y, int dx, int dy) {
    // Base implementation does nothing
}

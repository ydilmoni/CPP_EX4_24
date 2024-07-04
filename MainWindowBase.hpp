#ifndef MAINWINDOWBASE_H
#define MAINWINDOWBASE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowBase; }
QT_END_NAMESPACE

class MainWindowBase : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindowBase(QWidget* parent = nullptr);
    ~MainWindowBase();

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    Ui::MainWindowBase* ui;

    // Virtual function to be overridden in the derived template class
    virtual void drawNode(QPainter& painter, int x, int y, int dx, int dy);
};

#endif // MAINWINDOWBASE_H

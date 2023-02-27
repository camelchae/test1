#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void InitializeUI();
    void InitializeConnect();

private slots:
    void SlotTagFileSaved(QString strTagFilename);


private:
    Ui::MainWindow *ui;
    QWidget *m_pViewerWidget;
};
#endif // MAINWINDOW_H

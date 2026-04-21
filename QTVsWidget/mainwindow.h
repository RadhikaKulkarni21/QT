#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QDial>
#include <QSlider>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    QWidget *centralWidget;
    QHBoxLayout *hbox;
    QGroupBox *buttonGroup;
    QPushButton *pushButton;
    QRadioButton *radioButton;
    QCheckBox *checkBox;
    QVBoxLayout *vboxButtonGroup;
    QGroupBox *textInputGroup;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QVBoxLayout *vboxTextInputGroup;
    QGroupBox *otherInputGroup;
    QComboBox *comboBox;
    QDial *dial;
    QSlider *slider;
    QVBoxLayout *vboxOtherInputGroup;
};
#endif // MAINWINDOW_H

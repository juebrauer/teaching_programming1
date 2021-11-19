#ifndef HAUPTFENSTER_H
#define HAUPTFENSTER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class HauptFenster; }
QT_END_NAMESPACE

class HauptFenster : public QMainWindow
{
    Q_OBJECT

public:
    HauptFenster(QWidget *parent = nullptr);
    ~HauptFenster();

private:
    Ui::HauptFenster *ui;
};
#endif // HAUPTFENSTER_H

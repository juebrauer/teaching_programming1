#ifndef MY_GUI_H
#define MY_GUI_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class my_gui : public QWidget
{
 Q_OBJECT

    public:
        explicit my_gui(QWidget *parent = 0);

    private:
        QPushButton* m_button1;
        QPushButton* m_button2;
        QLabel* m_label;

        int m_counter;

    signals:

    public slots:
        void slotButtonClicked(bool checked);

};

#endif // MY_GUI_H
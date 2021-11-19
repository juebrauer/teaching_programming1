#include "my_gui.h"

#include <QFont>

my_gui::my_gui(QWidget *parent) : QWidget(parent)
{
    m_counter = 0;

    setFixedSize(600, 600);
        
    m_button1 = new QPushButton("Button 1", this);
    m_button1->setGeometry(10, 10, 150, 30);

    m_button2 = new QPushButton("Button 2", this);
    m_button2->setGeometry(10, 60, 150, 30);

    m_label = new QLabel(this);
    m_label->setGeometry(10, 110, 500,300);
    m_label->setText("Initial Text");
    
    m_label->setStyleSheet( "QLabel { background-color : black; color : white; }" );
    QFont newfont("Ubuntu", 20, QFont::Bold);
    m_label->setFont(newfont);

    connect(m_button1, SIGNAL (clicked(bool)), this, SLOT (slotButtonClicked(bool)));
    connect(m_button2, SIGNAL (clicked(bool)), this, SLOT (slotButtonClicked(bool)));
}


void my_gui::slotButtonClicked(bool checked)
{
    m_counter++;
    QString txt = "Nr of times buttons clicked: " +
                  QString::number(m_counter);
    m_label->setText( txt );    
}
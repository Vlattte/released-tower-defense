#ifndef CHAT_H
#define CHAT_H

#include <QGraphicsTextItem>

class Chat :public QGraphicsTextItem
{
public:
    Chat(QGraphicsItem * parent = nullptr);
    void addText(QString string);

	QString[4] chat_strings;
};

#endif // CHAT_H

/*
    Copyright (c) 2013, Lukas Holecek <hluk@email.cz>

    This file is part of CopyQ.

    CopyQ is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    CopyQ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with CopyQ.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef TABTREE_H
#define TABTREE_H

#include <QTreeWidget>

class TabTree : public QTreeWidget
{
    Q_OBJECT
public:
    explicit TabTree(QWidget *parent = NULL);

    /** Create tab in @a path with given @a index. */
    void insertTab(const QString &path, int index);

    /** Remove tab with given @a index. */
    void removeTab(int index);

    /** Return item with given @a index or NULL if it doesn't exist. */
    QTreeWidgetItem *findTreeItem(int index) const;

    /** Get tab index for @a item (-1 if it's a group). */
    int getTabIndex(QTreeWidgetItem *item) const;

    /** Return current tab index or -1 if no item or group is current. */
    int getCurrentTabIndex() const;

signals:
    void currentTabChanged(int index);

public slots:
    void setCurrentTabIndex(int index);
    void nextTreeItem();
    void previousTreeItem();

private slots:
    void onCurrentItemChanged(QTreeWidgetItem *current);
};

#endif // TABTREE_H

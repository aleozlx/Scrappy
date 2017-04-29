/*
 * Script list
 * Copyright (C) 2017  Alex Yang aleozlx@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include "listwidget.h"
#include <QVBoxLayout>
#include <QInputDialog>

// http://zetcode.com/gui/qt5/widgets2/

ListWidget::ListWidget(QWidget *parent)
    : QWidget(parent) {

  QVBoxLayout *vbox = new QVBoxLayout();
  vbox->setSpacing(10);

  QHBoxLayout *hbox = new QHBoxLayout(this);

  lw = new QListWidget(this);
  lw->addItem("The Omen"); 
  lw->addItem("The Exorcist");
  lw->addItem("Notes on a scandal");
  lw->addItem("Fargo");
  lw->addItem("Capote");

  add = new QPushButton("Add", this);
  rename = new QPushButton("Rename", this);
  remove = new QPushButton("Remove", this);
  removeAll = new QPushButton("Remove All", this);

  vbox->setSpacing(3);
  vbox->addStretch(1);
  vbox->addWidget(add);
  vbox->addWidget(rename);
  vbox->addWidget(remove);
  vbox->addWidget(removeAll);
  vbox->addStretch(1);

  hbox->addWidget(lw);
  hbox->addSpacing(15);
  hbox->addLayout(vbox);
  
  connect(add, &QPushButton::clicked, this, &ListWidget::addItem);
  connect(rename, &QPushButton::clicked, this, &ListWidget::renameItem);
  connect(remove, &QPushButton::clicked, this, &ListWidget::removeItem);
  connect(removeAll, &QPushButton::clicked, this, &ListWidget::clearItems);
  
  setLayout(hbox);
}

void ListWidget::addItem() {
    
  QString c_text = QInputDialog::getText(this, "Item", "Enter new item");
  QString s_text = c_text.simplified();
  
  if (!s_text.isEmpty()) {
      
    lw->addItem(s_text);
    int r = lw->count() - 1;
    lw->setCurrentRow(r);
  }
}

void ListWidget::renameItem() {
    
  QListWidgetItem *curitem = lw->currentItem();
  
  int r = lw->row(curitem);
  QString c_text = curitem->text();
  QString r_text = QInputDialog::getText(this, "Item", 
      "Enter new item", QLineEdit::Normal, c_text);
  
  QString s_text = r_text.simplified();
  
  if (!s_text.isEmpty()) {
      
    QListWidgetItem *item = lw->takeItem(r);
    delete item;
    lw->insertItem(r, s_text);
    lw->setCurrentRow(r);
  }
}

void ListWidget::removeItem() {
    
  int r = lw->currentRow();

  if (r != -1) {
      
    QListWidgetItem *item = lw->takeItem(r);
    delete item;
  }
}

void ListWidget::clearItems(){
    
  if (lw->count() != 0) {
    lw->clear();
  }
}

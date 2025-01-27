/******************************************************************************
 * The MIT License (MIT)
 *
 * Copyright (c) 2019-2024 Baldur Karlsson
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

#pragma once

#include "Widgets/Extended/RDTableWidget.h"

class QToolButton;

enum class ItemButton
{
  None,
  BrowseFolder,
  BrowseFile,
  Delete,
};

class OrderedListEditor : public RDTableWidget
{
  Q_OBJECT

public:
  explicit OrderedListEditor(const QString &itemName, ItemButton button, QWidget *parent = 0);
  ~OrderedListEditor();

  void setItems(const QStringList &strings);
  QStringList getItems();

  bool allowAddition() { return m_allowAddition; }
  void setAllowAddition(bool allow) { m_allowAddition = allow; }

private slots:
  // manual slots
  void cellChanged(int row, int column);
  void buttonActivate();

private:
  void keyPressEvent(QKeyEvent *e) override;

  ItemButton m_ButtonMode;

  bool m_allowAddition = true;

  void addNewItemRow();
  QToolButton *makeButton();
};

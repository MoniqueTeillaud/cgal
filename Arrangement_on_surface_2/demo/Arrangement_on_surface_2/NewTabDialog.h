// Copyright (c) 2012  Tel-Aviv University (Israel).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org).
//
// $URL$
// $Id$
// SPDX-License-Identifier: GPL-3.0-or-later OR LicenseRef-Commercial
//
// Author(s)     : Alex Tsui <alextsui05@gmail.com>

#ifndef NEW_TAB_DIALOG_H
#define NEW_TAB_DIALOG_H

#include <QDialog>

class QButtonGroup;
namespace Ui
{
  class NewTabDialog;
}

class NewTabDialog : public QDialog
{
public:
  NewTabDialog( QWidget* parent = 0, Qt::WindowFlags f = 0 );	
  int checkedId( ) const;					//!< returns ID of the the radio button

protected:	
  Ui::NewTabDialog* ui;						/*!< reference to the ui_NewTabDialog for displaying the dialogue */
  QButtonGroup* buttonGroup;				/*!< radio button group */
};
#endif // NEW_TAB_DIALOG_H

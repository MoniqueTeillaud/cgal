// Copyright (c) 2008  INRIA Sophia-Antipolis (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; version 2.1 of the License.
// See the file LICENSE.LGPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
//
// Author(s)     : Sylvain Pion

#ifndef CGAL_DIMENSION_TAG_H
#define CGAL_DIMENSION_TAG_H

#include <CGAL/basic.h>

CGAL_BEGIN_NAMESPACE

// This class helps dispatching functions based on the geometric dimension.

template < int dim >
struct Dimension_tag
{
  static const int value = dim;
};

CGAL_END_NAMESPACE

#endif // CGAL_DIMENSION_TAG_H

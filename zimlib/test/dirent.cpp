/*
 * Copyright (C) 2009 Tommi Maekitalo
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * is provided AS IS, WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, and
 * NON-INFRINGEMENT.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 *
 */

#include <zim/dirent.h>
#include <iostream>
#include <sstream>

#include <cxxtools/unit/testsuite.h>
#include <cxxtools/unit/registertest.h>

class DirentTest : public cxxtools::unit::TestSuite
{
  public:
    DirentTest()
      : cxxtools::unit::TestSuite("zim::DirentTest")
    {
      registerMethod("ReadWriteArticleDirent", *this, &DirentTest::ReadWriteArticleDirent);
      registerMethod("ReadWriteArticleDirentU", *this, &DirentTest::ReadWriteArticleDirentU);
      registerMethod("ReadWriteArticleDirentP", *this, &DirentTest::ReadWriteArticleDirentP);
      registerMethod("ReadWriteRedirectDirent", *this, &DirentTest::ReadWriteRedirectDirent);
      registerMethod("ArticleDirentSize", *this, &DirentTest::ArticleDirentSize);
      registerMethod("RedirectDirentSize", *this, &DirentTest::RedirectDirentSize);
    }

    void ReadWriteArticleDirent()
    {
      zim::Dirent dirent;
      dirent.setTitle('A', zim::QUnicodeString("Foo"));
      dirent.setArticle(zim::zimMimeImagePng, 45, 1234);

      CXXTOOLS_UNIT_ASSERT(!dirent.isRedirect());
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getNamespace(), 'A');
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getTitle().getValue(), "Foo");
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getParameter(), "");
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getClusterNumber(), 45);
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getBlobNumber(), 1234);
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getExtraLen(), 3);

      std::stringstream s;
      s << dirent;

      zim::Dirent dirent2;
      s >> dirent2;

      CXXTOOLS_UNIT_ASSERT(!s.fail());

      CXXTOOLS_UNIT_ASSERT_EQUALS(s.tellg(), s.tellp());

      CXXTOOLS_UNIT_ASSERT(!dirent2.isRedirect());
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent2.getNamespace(), 'A');
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent2.getTitle().getValue(), "Foo");
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent2.getParameter(), "");
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent2.getClusterNumber(), 45);
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent2.getBlobNumber(), 1234);
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent2.getExtraLen(), 3);

    }

    void ReadWriteArticleDirentU()
    {
      zim::Dirent dirent;
      dirent.setTitle('A', zim::QUnicodeString("L\xc3\xbcliang"));
      dirent.setArticle(zim::zimMimeImagePng, 45, 1234);

      CXXTOOLS_UNIT_ASSERT(!dirent.isRedirect());
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getNamespace(), 'A');
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getTitle().getValue(), "L\xc3\xbcliang");
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getParameter(), "");
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getClusterNumber(), 45);
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getBlobNumber(), 1234);
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getExtraLen(), 8);

      std::stringstream s;
      s << dirent;

      zim::Dirent dirent2;
      s >> dirent2;

      CXXTOOLS_UNIT_ASSERT(!s.fail());

      CXXTOOLS_UNIT_ASSERT_EQUALS(s.tellg(), s.tellp());

      CXXTOOLS_UNIT_ASSERT(!dirent2.isRedirect());
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent2.getNamespace(), 'A');
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent2.getTitle().getValue(), "L\xc3\xbcliang");
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent2.getParameter(), "");
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent2.getClusterNumber(), 45);
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent2.getBlobNumber(), 1234);
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent2.getExtraLen(), 8);

    }

    void ReadWriteArticleDirentP()
    {
      zim::Dirent dirent;
      dirent.setTitle('A', zim::QUnicodeString("Foo"));
      dirent.setParameter("bar");
      dirent.setArticle(zim::zimMimeImagePng, 45, 1234);

      CXXTOOLS_UNIT_ASSERT(!dirent.isRedirect());
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getNamespace(), 'A');
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getTitle().getValue(), "Foo");
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getParameter(), "bar");
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getClusterNumber(), 45);
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getBlobNumber(), 1234);
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getExtraLen(), 7);

      std::stringstream s;
      s << dirent;

      zim::Dirent dirent2;
      s >> dirent2;

      CXXTOOLS_UNIT_ASSERT(!s.fail());

      CXXTOOLS_UNIT_ASSERT_EQUALS(s.tellg(), s.tellp());

      CXXTOOLS_UNIT_ASSERT(!dirent2.isRedirect());
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent2.getNamespace(), 'A');
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent2.getTitle().getValue(), "Foo");
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent2.getParameter(), "bar");
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent2.getClusterNumber(), 45);
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent2.getBlobNumber(), 1234);
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent2.getExtraLen(), 7);

    }

    void ReadWriteRedirectDirent()
    {
      zim::Dirent dirent;
      dirent.setTitle('A', zim::QUnicodeString("Bar"));
      dirent.setParameter("baz");
      dirent.setRedirect(321);

      CXXTOOLS_UNIT_ASSERT(dirent.isRedirect());
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getNamespace(), 'A');
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getTitle().getValue(), "Bar");
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getParameter(), "baz");
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getRedirectIndex(), 321);

      std::stringstream s;
      s << dirent;
      zim::Dirent dirent2;
      s >> dirent2;

      CXXTOOLS_UNIT_ASSERT_EQUALS(s.tellg(), s.tellp());

      CXXTOOLS_UNIT_ASSERT(dirent2.isRedirect());
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent2.getNamespace(), 'A');
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent2.getTitle().getValue(), "Bar");
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent2.getParameter(), "baz");
      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent2.getRedirectIndex(), 321);
    }

    void ArticleDirentSize()
    {
      zim::Dirent dirent;
      dirent.setTitle('A', zim::QUnicodeString("Bar"));
      dirent.setParameter("baz");
      dirent.setArticle(zim::zimMimeImagePng, 45, 1234);

      std::ostringstream d;
      d << dirent;

      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getDirentSize(), d.str().size());
    }

    void RedirectDirentSize()
    {
      zim::Dirent dirent;
      dirent.setTitle('A', zim::QUnicodeString("Bar"));
      dirent.setParameter("baz");
      dirent.setRedirect(321);

      std::ostringstream d;
      d << dirent;

      CXXTOOLS_UNIT_ASSERT_EQUALS(dirent.getDirentSize(), d.str().size());
    }

};

cxxtools::unit::RegisterTest<DirentTest> register_DirentTest;
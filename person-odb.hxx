// -*- C++ -*-
//
// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef PERSON_ODB_HXX
#define PERSON_ODB_HXX

#include <odb/version.hxx>

#if ODB_VERSION != 20500UL
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "Models/person.hxx"

#include <memory>
#include <cstddef>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/no-op-cache-traits.hxx>

#include <odb/details/unused.hxx>

namespace odb
{
  // Person
  //
  template <>
  struct class_traits< ::Person >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::Person >
  {
    public:
    typedef ::Person object_type;
    typedef ::Person* pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef int id_type;

    static const bool auto_id = true;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    no_op_pointer_cache_traits<pointer_type>
    pointer_cache_traits;

    typedef
    no_op_reference_cache_traits<object_type>
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };
}

#include <odb/details/buffer.hxx>

#include <odb/mysql/version.hxx>
#include <odb/mysql/forward.hxx>
#include <odb/mysql/binding.hxx>
#include <odb/mysql/mysql-types.hxx>

namespace odb
{
  // Person
  //
  template <>
  class access::object_traits_impl< ::Person, id_mysql >:
    public access::object_traits< ::Person >
  {
    public:
    struct id_image_type
    {
      int id_value;
      my_bool id_null;

      std::size_t version;
    };

    struct image_type
    {
      // id_
      //
      int id_value;
      my_bool id_null;

      // name_
      //
      details::buffer name_value;
      unsigned long name_size;
      my_bool name_null;

      // age_
      //
      int age_value;
      my_bool age_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    using object_traits<object_type>::id;

    static id_type
    id (const id_image_type&);

    static bool
    grow (image_type&,
          my_bool*);

    static void
    bind (MYSQL_BIND*,
          image_type&,
          mysql::statement_kind);

    static void
    bind (MYSQL_BIND*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          mysql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef mysql::object_statements<object_type> statements_type;

    static const std::size_t column_count = 3UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];

    static void
    persist (database&, object_type&);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&);

    static bool
    reload (database&, object_type&);

    static void
    update (database&, const object_type&);

    static void
    erase (database&, const id_type&);

    static void
    erase (database&, const object_type&);

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);
  };

  template <>
  class access::object_traits_impl< ::Person, id_common >:
    public access::object_traits_impl< ::Person, id_mysql >
  {
  };
}

#include "person-odb.ixx"

#include <odb/post.hxx>

#endif // PERSON_ODB_HXX

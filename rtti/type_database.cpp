#include "type_database.h"
#include "runtime.h"

using namespace Dimitory;

TypeID TypeDatabase::registerType( const String& name )
{
    // its defined already, return invalid
    if ( ids.find( name ) != ids.end() ) return Type::Invalid;

    types.emplace_back( name );
    // create new id and assign it to name
    auto id = idCounter++;
    ids[name] = id;
    return id;
}

TypeDatabase& TypeDatabase::getInstance()
{
    static TypeDatabase instance;
    return instance;
}

TypeDatabase::TypeDatabase()
    : types( 1 ), idCounter( 1 )
{
    types[Type::Invalid].name = "INVALID";
}
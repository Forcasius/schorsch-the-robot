#ifndef INCLUDED_COM_SUN_STAR_XML_SAX_SAXINVALIDCHARACTEREXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_XML_SAX_SAXINVALIDCHARACTEREXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/xml/sax/SAXInvalidCharacterException.hdl"

#include "com/sun/star/xml/sax/SAXException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "osl/mutex.hxx"

namespace com { namespace sun { namespace star { namespace xml { namespace sax {

inline SAXInvalidCharacterException::SAXInvalidCharacterException() SAL_THROW( () )
    : ::com::sun::star::xml::sax::SAXException()
{ }

inline SAXInvalidCharacterException::SAXInvalidCharacterException(const ::rtl::OUString& Message_, const ::com::sun::star::uno::Reference< ::com::sun::star::uno::XInterface >& Context_, const ::com::sun::star::uno::Any& WrappedException_) SAL_THROW( () )
    : ::com::sun::star::xml::sax::SAXException(Message_, Context_, WrappedException_)
{ }

SAXInvalidCharacterException::SAXInvalidCharacterException(SAXInvalidCharacterException const & the_other): ::com::sun::star::xml::sax::SAXException(the_other) {}

SAXInvalidCharacterException::~SAXInvalidCharacterException() {}

SAXInvalidCharacterException & SAXInvalidCharacterException::operator =(SAXInvalidCharacterException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::com::sun::star::xml::sax::SAXException::operator =(the_other);
    return *this;
}

} } } } }

namespace com { namespace sun { namespace star { namespace xml { namespace sax {

inline ::com::sun::star::uno::Type const & cppu_detail_getUnoType(::com::sun::star::xml::sax::SAXInvalidCharacterException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::com::sun::star::uno::Type& rBaseType = ::cppu::UnoType< const ::com::sun::star::xml::sax::SAXException >::get();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.xml.sax.SAXInvalidCharacterException", rBaseType.getTypeLibType(), 0,  0 );
    }
    return * reinterpret_cast< const ::com::sun::star::uno::Type * >( &the_type );
}

} } } } }

inline ::com::sun::star::uno::Type const & SAL_CALL getCppuType(::com::sun::star::xml::sax::SAXInvalidCharacterException const *) SAL_THROW(()) {
    return ::cppu::UnoType< ::com::sun::star::xml::sax::SAXInvalidCharacterException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XML_SAX_SAXINVALIDCHARACTEREXCEPTION_HPP

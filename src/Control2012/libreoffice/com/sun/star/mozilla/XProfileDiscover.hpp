#ifndef INCLUDED_COM_SUN_STAR_MOZILLA_XPROFILEDISCOVER_HPP
#define INCLUDED_COM_SUN_STAR_MOZILLA_XPROFILEDISCOVER_HPP

#include "sal/config.h"

#include "com/sun/star/mozilla/XProfileDiscover.hdl"

#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/mozilla/MozillaProductType.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "osl/mutex.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace mozilla {

inline ::com::sun::star::uno::Type const & cppu_detail_getUnoType(::com::sun::star::mozilla::XProfileDiscover const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.mozilla.XProfileDiscover", 0, 0 );
    }
    return * reinterpret_cast< ::com::sun::star::uno::Type * >( &the_type );
}

} } } }

inline ::com::sun::star::uno::Type const & SAL_CALL getCppuType(::com::sun::star::uno::Reference< ::com::sun::star::mozilla::XProfileDiscover > const *) SAL_THROW(()) {
    return ::cppu::UnoType< ::com::sun::star::uno::Reference< ::com::sun::star::mozilla::XProfileDiscover > >::get();
}

::com::sun::star::uno::Type const & ::com::sun::star::mozilla::XProfileDiscover::static_type(void *) {
    return ::getCppuType(static_cast< ::com::sun::star::uno::Reference< ::com::sun::star::mozilla::XProfileDiscover > * >(0));
}

#endif // INCLUDED_COM_SUN_STAR_MOZILLA_XPROFILEDISCOVER_HPP

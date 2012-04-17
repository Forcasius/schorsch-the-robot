#ifndef INCLUDED_COM_SUN_STAR_UCB_XCOMMANDPROCESSOR_HPP
#define INCLUDED_COM_SUN_STAR_UCB_XCOMMANDPROCESSOR_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/XCommandProcessor.hdl"

#include "com/sun/star/ucb/CommandAbortedException.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/ucb/Command.hpp"
#include "com/sun/star/ucb/XCommandEnvironment.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "osl/mutex.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline ::com::sun::star::uno::Type const & cppu_detail_getUnoType(::com::sun::star::ucb::XCommandProcessor const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.ucb.XCommandProcessor", 0, 0 );
    }
    return * reinterpret_cast< ::com::sun::star::uno::Type * >( &the_type );
}

} } } }

inline ::com::sun::star::uno::Type const & SAL_CALL getCppuType(::com::sun::star::uno::Reference< ::com::sun::star::ucb::XCommandProcessor > const *) SAL_THROW(()) {
    return ::cppu::UnoType< ::com::sun::star::uno::Reference< ::com::sun::star::ucb::XCommandProcessor > >::get();
}

::com::sun::star::uno::Type const & ::com::sun::star::ucb::XCommandProcessor::static_type(void *) {
    return ::getCppuType(static_cast< ::com::sun::star::uno::Reference< ::com::sun::star::ucb::XCommandProcessor > * >(0));
}

#endif // INCLUDED_COM_SUN_STAR_UCB_XCOMMANDPROCESSOR_HPP
#ifndef INCLUDED_COM_SUN_STAR_UCB_CONTENTPROVIDERINFO_HPP
#define INCLUDED_COM_SUN_STAR_UCB_CONTENTPROVIDERINFO_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/ContentProviderInfo.hdl"

#include "com/sun/star/ucb/XContentProvider.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline ContentProviderInfo::ContentProviderInfo() SAL_THROW( () )
    : ContentProvider()
    , Scheme()
{
}

inline ContentProviderInfo::ContentProviderInfo(const ::com::sun::star::uno::Reference< ::com::sun::star::ucb::XContentProvider >& ContentProvider_, const ::rtl::OUString& Scheme_) SAL_THROW( () )
    : ContentProvider(ContentProvider_)
    , Scheme(Scheme_)
{
}

} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::com::sun::star::uno::Type const & cppu_detail_getUnoType(::com::sun::star::ucb::ContentProviderInfo const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::com::sun::star::uno::Reference< ::com::sun::star::ucb::XContentProvider > >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.ContentProviderInfo", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::com::sun::star::uno::Type * >(&the_type);
}

} } } }

inline ::com::sun::star::uno::Type const & SAL_CALL getCppuType(::com::sun::star::ucb::ContentProviderInfo const *) SAL_THROW(()) {
    return ::cppu::UnoType< ::com::sun::star::ucb::ContentProviderInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_CONTENTPROVIDERINFO_HPP

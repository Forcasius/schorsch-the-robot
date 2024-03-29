#ifndef INCLUDED_COM_SUN_STAR_FRAME_BORDERWIDTHS_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_BORDERWIDTHS_HPP

#include "sal/config.h"

#include "com/sun/star/frame/BorderWidths.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace frame {

inline BorderWidths::BorderWidths() SAL_THROW( () )
    : Left(0)
    , Top(0)
    , Right(0)
    , Bottom(0)
{
}

inline BorderWidths::BorderWidths(const ::sal_Int32& Left_, const ::sal_Int32& Top_, const ::sal_Int32& Right_, const ::sal_Int32& Bottom_) SAL_THROW( () )
    : Left(Left_)
    , Top(Top_)
    , Right(Right_)
    , Bottom(Bottom_)
{
}

} } } }

namespace com { namespace sun { namespace star { namespace frame {

inline ::com::sun::star::uno::Type const & cppu_detail_getUnoType(::com::sun::star::frame::BorderWidths const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.frame.BorderWidths", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::com::sun::star::uno::Type * >(&the_type);
}

} } } }

inline ::com::sun::star::uno::Type const & SAL_CALL getCppuType(::com::sun::star::frame::BorderWidths const *) SAL_THROW(()) {
    return ::cppu::UnoType< ::com::sun::star::frame::BorderWidths >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_BORDERWIDTHS_HPP

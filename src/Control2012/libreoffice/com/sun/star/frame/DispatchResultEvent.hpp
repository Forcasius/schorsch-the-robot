#ifndef INCLUDED_COM_SUN_STAR_FRAME_DISPATCHRESULTEVENT_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_DISPATCHRESULTEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/frame/DispatchResultEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace frame {

inline DispatchResultEvent::DispatchResultEvent() SAL_THROW( () )
    : ::com::sun::star::lang::EventObject()
    , State(0)
    , Result()
{
}

inline DispatchResultEvent::DispatchResultEvent(const ::com::sun::star::uno::Reference< ::com::sun::star::uno::XInterface >& Source_, const ::sal_Int16& State_, const ::com::sun::star::uno::Any& Result_) SAL_THROW( () )
    : ::com::sun::star::lang::EventObject(Source_)
    , State(State_)
    , Result(Result_)
{
}

} } } }

namespace com { namespace sun { namespace star { namespace frame {

inline ::com::sun::star::uno::Type const & cppu_detail_getUnoType(::com::sun::star::frame::DispatchResultEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::com::sun::star::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.frame.DispatchResultEvent", ::cppu::UnoType< ::com::sun::star::lang::EventObject >::get().getTypeLibType(), 2, the_members, 0);
    }
    return *reinterpret_cast< ::com::sun::star::uno::Type * >(&the_type);
}

} } } }

inline ::com::sun::star::uno::Type const & SAL_CALL getCppuType(::com::sun::star::frame::DispatchResultEvent const *) SAL_THROW(()) {
    return ::cppu::UnoType< ::com::sun::star::frame::DispatchResultEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_DISPATCHRESULTEVENT_HPP

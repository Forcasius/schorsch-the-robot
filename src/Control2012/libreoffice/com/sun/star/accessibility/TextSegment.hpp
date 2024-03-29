#ifndef INCLUDED_COM_SUN_STAR_ACCESSIBILITY_TEXTSEGMENT_HPP
#define INCLUDED_COM_SUN_STAR_ACCESSIBILITY_TEXTSEGMENT_HPP

#include "sal/config.h"

#include "com/sun/star/accessibility/TextSegment.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace accessibility {

inline TextSegment::TextSegment() SAL_THROW( () )
    : SegmentText()
    , SegmentStart(0)
    , SegmentEnd(0)
{
}

inline TextSegment::TextSegment(const ::rtl::OUString& SegmentText_, const ::sal_Int32& SegmentStart_, const ::sal_Int32& SegmentEnd_) SAL_THROW( () )
    : SegmentText(SegmentText_)
    , SegmentStart(SegmentStart_)
    , SegmentEnd(SegmentEnd_)
{
}

} } } }

namespace com { namespace sun { namespace star { namespace accessibility {

inline ::com::sun::star::uno::Type const & cppu_detail_getUnoType(::com::sun::star::accessibility::TextSegment const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.accessibility.TextSegment", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::com::sun::star::uno::Type * >(&the_type);
}

} } } }

inline ::com::sun::star::uno::Type const & SAL_CALL getCppuType(::com::sun::star::accessibility::TextSegment const *) SAL_THROW(()) {
    return ::cppu::UnoType< ::com::sun::star::accessibility::TextSegment >::get();
}

#endif // INCLUDED_COM_SUN_STAR_ACCESSIBILITY_TEXTSEGMENT_HPP

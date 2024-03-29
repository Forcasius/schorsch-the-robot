#ifndef INCLUDED_COM_SUN_STAR_I18N_LINEBREAKRESULTS_HPP
#define INCLUDED_COM_SUN_STAR_I18N_LINEBREAKRESULTS_HPP

#include "sal/config.h"

#include "com/sun/star/i18n/LineBreakResults.hdl"

#include "com/sun/star/linguistic2/XHyphenatedWord.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace i18n {

inline LineBreakResults::LineBreakResults() SAL_THROW( () )
    : breakType(0)
    , breakIndex(0)
    , rHyphenatedWord()
{
}

inline LineBreakResults::LineBreakResults(const ::sal_Int16& breakType_, const ::sal_Int32& breakIndex_, const ::com::sun::star::uno::Reference< ::com::sun::star::linguistic2::XHyphenatedWord >& rHyphenatedWord_) SAL_THROW( () )
    : breakType(breakType_)
    , breakIndex(breakIndex_)
    , rHyphenatedWord(rHyphenatedWord_)
{
}

} } } }

namespace com { namespace sun { namespace star { namespace i18n {

inline ::com::sun::star::uno::Type const & cppu_detail_getUnoType(::com::sun::star::i18n::LineBreakResults const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::com::sun::star::uno::Reference< ::com::sun::star::linguistic2::XHyphenatedWord > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.i18n.LineBreakResults", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::com::sun::star::uno::Type * >(&the_type);
}

} } } }

inline ::com::sun::star::uno::Type const & SAL_CALL getCppuType(::com::sun::star::i18n::LineBreakResults const *) SAL_THROW(()) {
    return ::cppu::UnoType< ::com::sun::star::i18n::LineBreakResults >::get();
}

#endif // INCLUDED_COM_SUN_STAR_I18N_LINEBREAKRESULTS_HPP

#ifndef INCLUDED_COM_SUN_STAR_UCB_RULETERM_HPP
#define INCLUDED_COM_SUN_STAR_UCB_RULETERM_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/RuleTerm.hdl"

#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline RuleTerm::RuleTerm() SAL_THROW( () )
    : Property()
    , Operand()
    , Operator(0)
    , CaseSensitive(false)
    , RegularExpression(false)
{
}

inline RuleTerm::RuleTerm(const ::rtl::OUString& Property_, const ::com::sun::star::uno::Any& Operand_, const ::sal_Int16& Operator_, const ::sal_Bool& CaseSensitive_, const ::sal_Bool& RegularExpression_) SAL_THROW( () )
    : Property(Property_)
    , Operand(Operand_)
    , Operator(Operator_)
    , CaseSensitive(CaseSensitive_)
    , RegularExpression(RegularExpression_)
{
}

} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::com::sun::star::uno::Type const & cppu_detail_getUnoType(::com::sun::star::ucb::RuleTerm const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::com::sun::star::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.RuleTerm", 0, 5, the_members, 0);
    }
    return *reinterpret_cast< ::com::sun::star::uno::Type * >(&the_type);
}

} } } }

inline ::com::sun::star::uno::Type const & SAL_CALL getCppuType(::com::sun::star::ucb::RuleTerm const *) SAL_THROW(()) {
    return ::cppu::UnoType< ::com::sun::star::ucb::RuleTerm >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_RULETERM_HPP

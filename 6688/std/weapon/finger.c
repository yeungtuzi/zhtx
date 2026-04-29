// finger.c

#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

varargs void init_finger(int damage, int flag)
{
        if( clonep(this_object()) ) return;

        set("weapon_prop/damage", damage);
        set("flag", (int)flag | EDGED);
        set("skill_type", "finger");
        if( !query("actions") )
                set("actions", (: call_other, SKILL_D("finger"), "query_action" :) );
}

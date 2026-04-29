// glove.c

#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

varargs void init_glove(int damage, int flag)
{
        if( clonep(this_object()) ) return;

        set("weapon_prop/damage", damage);
        set("flag", (int)flag | EDGED);
        set("skill_type", "cuff");
        if( !query("actions") )
                set("actions", (: call_other, SKILL_D("cuff"), "query_action" :) );
}



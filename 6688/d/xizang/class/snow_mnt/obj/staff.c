// /d/xizang/class/snow_mnt//obj/staff.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("木禅杖" , ({ "wood staff", "staff" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", "一条又粗又长的木禅杖，上面涂亮黑漆, 还刻有梵文标记。\n");
                set("value", 120);
                set("material", "wood");
                set("wield_msg", "$N拿出一根乌黑的$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_staff(20);
        setup();
}

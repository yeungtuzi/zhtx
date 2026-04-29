// /d/xizang/npc/obj/snowblade.c

#include <weapon.h>

inherit BLADE;

void create()
{
//原名"碧雪刀"
        set_name("碎雪", ({ "snowblade" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", 
	"这是一把看上去很普通的长刀,刀头截去一块,呈方型\n");
                set("value", 900);
		set("rigidity", 200);
                set("material", "steel");
        }
        init_blade(70);

        set("wield_msg", "$N从铁皮雕花刀鞘中抽出一把银光闪闪的$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插回铁皮雕花刀鞘中。\n");

        setup();
}

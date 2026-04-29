
#include <weapon.h>

inherit BLADE;
inherit F_UNIQUE;
void create()
{
        set_name("碧玉胡刀", ({ "jadeblade" }) );
        set_weight(100000);
	set("unpawnable",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把弯如月牙儿，镶满碧玉的胡刀");
                set("value", 100000);
		set("rigidity", 20000);
                set("material", "steel");
		set("replica_ob", __DIR__"hu-blade");
        }
        init_blade(130);
        set("wield_msg", "$N从腰间抽出一把亮闪闪的$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n别在腰间。\n");
        setup();
}


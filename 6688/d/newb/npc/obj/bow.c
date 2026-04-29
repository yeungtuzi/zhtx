///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

// sword:__DIR__"obj/broken_sword.c" 破残奇剑一把

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
//inherit F_UNIQUE;

void create()
{
    set_name("猎弓",({"hunt bow","bow"}));
        set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else{
                set("unit", "把");
        set("long", "一把坚硬的弓。很多人都用它来打猎。\n");
                set("value", 6000);
                set("material", "异类金属");
        set("wield_msg", "$N「唰」地一声拉开$n紧握在手中。\n");
        set("unwield_msg", "$N将手中的$n放下。\n");
    }
        init_sword(25);
        setup();
}


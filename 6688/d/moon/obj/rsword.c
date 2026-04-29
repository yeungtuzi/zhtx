/**************************************************************************/
// $Id: rsword.c,v 1.1 2000/12/14 15:21:45 cmy Exp $
/**************************************************************************/
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("红鹰剑", ({ "rsword" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是红鹰剑客的随身武器。\n");
                set("value", 1500);
                set("material", "steel");
                set("rigidity", 99);
                set("wield_msg", "$N从红色剑鞘中抽出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入腰间的红色剑鞘。\n");
        }
        init_sword(40);
        setup();
}


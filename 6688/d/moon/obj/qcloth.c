/**************************************************************************/
// $Id: cloth.c,v 1.1 2000/12/14 15:21:45 cmy Exp $
/**************************************************************************/
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("黄冠衫", ({ "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这件由普通棉布做成的棉布衫。\n");
                set("unit", "件");
                set("value", 600);
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 3);
                set("male_only", 1);
        }
        setup();
}



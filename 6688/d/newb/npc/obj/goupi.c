///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("狗皮", ({ "gou pi", "pi" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是一块上好的狗皮，看来可以穿在身上。\n");
                set("material", "fur");
                set("value", 500);
                set("armor_prop/armor", 5);
        }
        setup();
}



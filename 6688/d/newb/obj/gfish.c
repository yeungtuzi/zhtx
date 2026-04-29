///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"金鲤鱼"NOR, ({"golden fish","fish"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 1000);
                set("long", "一条金色大鲤鱼,看起来能卖个好价钱。\n");
        }
        setup();
}


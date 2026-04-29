///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL"野兔"NOR, ({"hare","ye tu"}));
        set_weight(1800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("value", 3000);
                set("long", "一只野兔，被箭射伤了。\n");
                set("dex",50);
                set("mark_hunt",1);
        }
        set("unpawnable",1);
        setup();
}


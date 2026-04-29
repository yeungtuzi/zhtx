///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("麻雀", ({"sparrow","ma que"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("value", 2000);
                set("long", "一只麻雀，被箭射伤了。\n");
                set("dex",40);
                set("mark_hunt",1);
        }
        set("unpawnable",1);
        setup();
}


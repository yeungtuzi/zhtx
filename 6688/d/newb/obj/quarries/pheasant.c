///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"长"HIR"尾"HIW"雉"NOR, ({"pheasant","zhi"}));
        set_weight(1800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("value", 8000);
                set("long", "一只长尾雉，非常珍希。可惜被射伤了。\n");
                set("dex",88);
                set("mark_hunt",1);
        }
        set("unpawnable",1);
        setup();
}


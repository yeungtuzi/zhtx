///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"梅"HIW"花"HIR"鹿"NOR, ({"deer","spotted deer"}));
        set_weight(1800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("value", 5000);
                set("long", "一只梅花鹿，被箭射伤了。\n");
                set("dex",60);
                set("mark_hunt",1);
        }
        set("unpawnable",1);
        setup();
}


// ling.c
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"魔域令"NOR, ({ "moyu ling", "ling" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是武林狐子任狂的随身令牌，令在人在，令失人亡。\n");
                set("no_get", 1);
                set("no_put", 1);
                set("unpawnable",1);
                set("research",250);
                set("unit", "枚");
                set("weight", 50);
                set("value", 100);
        }
}


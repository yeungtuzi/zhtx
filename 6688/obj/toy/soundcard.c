// /obj/toy/soundcard.c

inherit ITEM;

void create()
{
        set_name("声卡", ({ "soundcard", "shengka" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
        set("long","这是一块花王五代声卡.\n");
        set("value", 15000);
        }
}

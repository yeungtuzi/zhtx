// jtea.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("毛尖", ({  "jtea" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "轻香袭人的上好毛尖。\n");
                set("unit", "杯");
                set("value", 50);
                set("max_liquid", 2);
        }

        set("liquid", ([
                "type": "water",
                "name": "毛尖",
                "remaining": 5,
        ]) );
}

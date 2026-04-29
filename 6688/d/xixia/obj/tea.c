inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("青花盖碗", ({  "tea" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "里面盛满了轻香袭人的茶水。\n");
                set("unit", "杯");
                set("value", 50);
                set("max_liquid", 2);
        }

        set("liquid", ([
                "type": "water",
                "name": "茶",
                "remaining": 5,
        ]) );
}

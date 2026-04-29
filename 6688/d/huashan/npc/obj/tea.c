inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("粗瓷茶碗", ({ "cuci chawan", "chawan","wan" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "粗瓷的大茶碗。\n");
                set("unit", "个");
                set("value", 40);
                set("max_liquid", 15);
        }

        // The liquid contained in the container is independent, we set a copy
        // in each cloned copy.
        set("liquid", ([
                "type": "water",
                "name": "香茶",
	            "remaining": 15,
        ]) );
}

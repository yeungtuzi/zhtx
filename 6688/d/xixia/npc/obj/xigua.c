inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("西瓜", ({  "xigua" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个又圆又大的西瓜。\n");
                set("unit", "个");
                set("value", 50000);
                set("max_liquid", 2);
        }

        set("liquid", ([
                "type": "water",
                "name": "西瓜",
                "remaining": 10,
        ]) );
}

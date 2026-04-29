// /d/xizang/class/snow_mnt/obj/shaolinb.c

inherit ITEM;

void create()
{
        set_name("少林武籍", ({ "shaolin wuji", "book", "wuji" }));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是从少林寺偷出来的武籍,可惜已经残缺不全了.\n");
                set("value", 100);
                set("material", "paper");
                set("skill", ([
                        "name": "unarmed",
                        "exp_required": 1000+random(10)*100, 
                        "sen_cost":  30,
                        "difficulty":20,
                        "max_skill": 40+random(10)*10,
                ]) );
        }
}

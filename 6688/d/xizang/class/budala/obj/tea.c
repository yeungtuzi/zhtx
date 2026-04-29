// /d/xizang/class/budala/obj/tea.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("酥油茶", ({ "su you cha", "tea", "cha" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一碗香喷喷的酥油茶.\n");
                set("unit", "碗");
                set("value", 20);
                set("max_liquid", 3);
        }

        // The liquid contained in the container is independent, we set a copy
        // in each cloned copy.
        set("liquid", ([
                "type": "tea",
                "name": "酥油茶",
                "remaining": 3,
                "drunk_apply": 10,
        ]) );
}

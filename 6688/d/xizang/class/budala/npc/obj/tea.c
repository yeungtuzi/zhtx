// /d/xizang/class/budala/npc/obj/tea.c

inherit ITEM;
inherit F_LIQUID;

string* titles = ({
"普洱茶",
"茉莉花茶",
"乌龙茶",
"酥油茶",
"龙井茶",
"毛尖",
薄荷茶"
});

void create()
{
	string name1;
	name1 = titles[random(sizeof(titles))]
        set_name(name1, ({ "tea", "cha" }) );
        set_weight(25);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一碗泡好的香茶.\n");
                set("unit", "碗");
                set("value", 10);
                set("max_liquid", 2);
        }

        // The liquid contained in the container is independent, we set a copy
        // in each cloned copy.
        set("liquid", ([
                "type": "tea",
                "name": name1,
                "remaining": 2,
                "drunk_apply": 7,
        ]) );
}

inherit ITEM;

string* titles = ({
        "天竺梵文",
});

void create()
{
        int i = random(sizeof(titles));

    	set_name(titles[i], ({ "shu", "shu ji" }));
        set_weight(200);
        set("unit", "册");
        set("long", "这是一册" + titles[i] + "，相传是当年唐僧所著。\n");
        set("value",100000);
        set("material", "paper");
        set("skill", ([
                        "name": "fanwen",       // name of the skill
                        "base_skill": 30,
                        "sen_cost": 10+random(20),// jing cost every time study this
                        "difficulty":   20,     // the base int to learn this skill
                        "max_skill":    180     // the maximum level you can learn
    	]) );
}

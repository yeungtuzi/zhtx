// /obj/book/litbook.c

inherit ITEM;

void create()
{
        string *names = ({
                "狂人日记", "围城", "红楼梦", "三国演义", "西游记",
                "水浒传", "拍案惊奇", "警世通言", "唐诗三百首",
                "傲慢与偏见", "简.爱"
        });
        set_name(names[random(sizeof(names))], ({ "literate book", "book"}));
        set_weight(1000);
        set("unit", "本");
        set("long", "这是一本文学名著.\n");
        set("value", 1000);
        set("skill", ([
                "name": "literate",
                "exp_required": 0,
                "sen_cost":    35,
                "difficulty":  35,
                "max_skill":  110,
        ]) );
}

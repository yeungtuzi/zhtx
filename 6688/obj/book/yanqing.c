// /obj/book/yanqing.c

inherit ITEM;

void create()
{
        string *names = ({
                "彩霞满天", "他乡明月", "在水一方", "白雪红尘", "北京人在纽约",
                "婉君", "撒哈拉的故事"
        });
        set_name(names[random(sizeof(names))], ({ "yanqing book", "book" }));
        set_weight(800);
        set("unit", "本");
        set("long", "这是时下流行的言情小说.\n");
        set("value", 1000);
        set("skill", ([
                "name": "literate",
                "exp_required": 0,
                "sen_cost":    22,
                "difficulty":  22,
                "max_skill":   88,
        ]) );
}

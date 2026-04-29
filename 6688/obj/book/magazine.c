// /obj/book/magazine.c

inherit ITEM;

void create()
{
        string *names = ({
                "航空知识","舰船知识","兵器知识","军事家","读者文摘",
                "青年文摘","了望","大众电影","大众电视","大众软件",
                "北京青年报","科幻世界"
        });
        set_name(names[random(sizeof(names))], ({ "magazine" }) );
        set_weight(200);
        set("unit", "本");
        set("long", "这是时下流行的报刊杂志.\n");
        set("value", 300);
        set("skill", ([
                "name": "literate",
                "exp_required": 0,
                "sen_cost":    27,
                "difficulty":  27,
                "max_skill":   49,
        ]) );
}

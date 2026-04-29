// /obj/book/wuxia.c

inherit ITEM;

void create()
{
        string *names = ({
                "寻秦记", "大剑师", "四大名捕", "大侠传奇", "蜀山剑侠传",
                "温柔一刀", "一怒拔剑", "惊艳一枪", "伤心小箭", "朝天一棍",
                "大唐双龙传", "风雪会中州", "多情剑客无情剑", "绝代双骄",
                "流星蝴蝶剑", "天涯明月刀", "楚留香传奇", "陆小凤"
        });
        set_name(names[random(sizeof(names))], ({ "wuxia book", "book" }));
        set_weight(1000);
        set("unit", "本");
        set("long", "这是时下流行的武侠小说.\n");
        set("value", 1000);
        set("skill", ([
                "name": "literate",
                "exp_required": 0,
                "sen_cost":    25,
                "difficulty":  26,
                "max_skill":   85,
        ]) );
}

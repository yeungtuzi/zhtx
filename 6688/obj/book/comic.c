// /obj/book/comic.c

inherit ITEM;

void create()
{
        string *names = ({
                "天地无用","魔幻游戏","中国漫画","少年漫画","乱马",
                "福星小子","圣斗士","北斗神拳","机器猫","城市猎人"
        });
        set_name(names[random(sizeof(names))], ({ "comic book", "comic" }) );
        set_weight(200);
        set("unit", "本");
        set("long", "这是时下流行的漫画书.\n");
        set("value", 600);
        set("skill", ([
                "name": "literate",
                "exp_required": 0,
                "sen_cost":    25,
                "difficulty":  25,
                "max_skill":   45,
        ]) );
}

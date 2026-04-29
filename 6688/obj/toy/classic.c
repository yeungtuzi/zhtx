// /obj/toy/classic.c

inherit ITEM;

void create()
{
        string *names = ({
                "贝多芬","瓦格纳","海顿","巴赫","柴可夫斯基","肖邦",
                "梁祝","约翰.施特劳斯","莫扎特"
        });
        set_name("经典音乐CD", ({ "classic music cd", "cd" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "盘");
                set("long","这是一盘"+names[random(sizeof(names))]+
                   "的唱碟.\n");
        set("value", 3100);
        set("skill", ([
                "name":                 "music",
                "exp_required": 0,
                "sen_cost":             20,
              "difficulty":   random(40)+10,
               "max_skill":   random(60)+20,
        ]) );
        }
}

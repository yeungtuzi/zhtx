// /obj/toy/vcd.c

inherit ITEM;

void create()
{
        string *names = ({
                "大话西游", "彩霞满天", "小城故事", "东方不败",
                "笑傲江湖", "逃学威龙", "人皮灯笼"
        });
        set_name("影碟", ({ "video cd", "vcd" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "盘");
                set("long","这是一盘"+names[random(sizeof(names))]+
                   "的影碟.\n");
        set("value", 1500);
        set("skill", ([
                "name":                 "literate",
                "exp_required": 0,
                "sen_cost":             25,
              "difficulty":   random(30)+10,
               "max_skill":   random(50)+10,
        ]) );
        }
}


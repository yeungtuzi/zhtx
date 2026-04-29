// /obj/toy/vhs.c

inherit ITEM;

void create()
{
        string *names = ({
                "火战士", "全金属外壳", "星球大战", "终结者",
                "异性", "桂河大桥", "刺杀肯尼迪"
        });
        set_name("录像带", ({ "video tape", "tape" }) );
        set_weight(40);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "盘");
                set("long","这是一盘"+names[random(sizeof(names))]+
                   "的原文配字幕录像带.\n");

        set("value", 1000);
        set("skill", ([
                    "name": "english",
            "exp_required": 0,
                "sen_cost": 40,
              "difficulty": random(30)+20,
               "max_skill": random(50)+10,
        ]) );
        }
}

// /obj/toy/cd.c

inherit ITEM;

void create()
{
        string *names = ({
                "windows98", "m$word", "civ2", "朗道词典", "中文之星",
                "四通立方", "傻瓜软件集成", "晕倒NT", "晕到死", "ie",
                "帝国时代", "三国志IV", "家庭书库", "有你可死", "catz",
                "中文游戏138", "软件大补贴", "游戏天堂", "中关村启示录",
                "仙剑奇侠传", "异次元狂热", "mp3大全"
        });
        set_name("盗版光盘", ({ "cd" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long","这是一张"+names[random(sizeof(names))]+
                   "的盗版光盘.\n");
        set("value", 2500);
        set("skill", ([
                "name": "computer",
        "exp_required": 0,
            "sen_cost": 20+random(30),
          "difficulty": random(50)+10,
           "max_skill": random(50)+10,
        ]) );
        }
}

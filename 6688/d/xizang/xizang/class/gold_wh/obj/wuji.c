// /d/xizang/class/gold_wh/obj/wuji.c

inherit ITEM;
string * skills = ({
"parry",
"dodge",
"hammer",
"force",
"unarmed"
});

void create()
{
      set_name("密宗金轮派基本武籍",({"mizong wuji", "book", "basic book"}));
      set_weight(130);
      if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是一本讲解密宗基本功夫的书.\n");
                set("value", 0);
                set("material", "paper");
                set("skill", ([
                        "name": skills[random(sizeof(skills))],
                "exp_required": 10000,
                    "sen_cost": 15+random(20),
                  "difficulty": 20+random(11),
                   "max_skill": 70+random(31),
                ]) );
        }
}
